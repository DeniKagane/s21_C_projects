#include "./s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  status = s21_validate_matrix(A);
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (A->rows == 1 || A->columns == 1) {
    // exclude vectors
    status = CALC_ERROR;
  }
  if (status == OK) {
    for (int i = 0; i < A->rows && status == OK; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      for (int j = 0; j < A->columns; j++) {
        if (status == OK) {
          matrix_t minor;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          s21_minor_matrix(A, &minor, i, j);
          double mon_det = 0;
          status = s21_determinant(&minor, &mon_det);
          result->matrix[i][j] = mon_det * sign;
          sign = -sign;
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return status;
}
