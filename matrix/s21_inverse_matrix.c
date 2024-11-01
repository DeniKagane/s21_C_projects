#include "./s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  double det = 0;
  status = s21_validate_matrix(A);
  if (A->rows != A->columns) {
    status = CALC_ERROR;
  }
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    status = s21_determinant(A, &det);
  }
  if (det == 0 && status == OK) {
    status = CALC_ERROR;
  }
  if (det != 0 && status == OK) {
    if (A->rows == 1) {
      status = s21_create_matrix(A->rows, A->columns, result);
      if (status == OK) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    } else {
      matrix_t calc_matrix, tr_calc_matrix;
      status = s21_calc_complements(A, &calc_matrix);
      if (status == OK) {
        status = s21_transpose(&calc_matrix, &tr_calc_matrix);
      }
      if (status == OK) {
        status = s21_mult_number(&tr_calc_matrix, 1 / det, result);
      }
      s21_remove_matrix(&tr_calc_matrix);
      s21_remove_matrix(&calc_matrix);
    }
  }
  return status;
}