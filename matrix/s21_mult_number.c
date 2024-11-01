#include "./s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  status = s21_validate_matrix(A);
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (!isfinite(number)) {
    status = CALC_ERROR;
  }
  if (status == OK) {
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns && status == OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) {
          status = CALC_ERROR;
        }
      }
    }
  }
  return status;
}
