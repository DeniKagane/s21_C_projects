#include "./s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  status = s21_validate_matrix(A);
  if (status == OK) {
    status = s21_create_matrix(A->rows, B->columns, result);
  }
  if (status == OK) {
    status = s21_validate_matrix(B);
  }

  if (status == OK && (A->columns != B->rows)) {
    status = CALC_ERROR;
  }

  if (status == OK) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          if (!isfinite(result->matrix[i][j])) {
            status = CALC_ERROR;
          }
        }
      }
  }

  return status;
}