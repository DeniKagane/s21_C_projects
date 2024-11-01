#include "./s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  status = s21_validate_matrix(A);
  if (status == OK) {
    status = s21_validate_matrix(B);
  }
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK && (A->columns != B->columns || A->rows != B->rows)) {
    status = CALC_ERROR;
  }
  if (result == NULL) {
    status = ERROR;
  }
  if (status == OK) {
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns && status == OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) {
          status = CALC_ERROR;
        }
      }
    }
  }

  return status;
}