#include "./s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = OK, eq_status = SUCCESS;
  status = s21_validate_matrix(A);
  if (status == OK) {
    status = s21_validate_matrix(B);
  }

  if (status == OK && A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && eq_status == SUCCESS; i++) {
      for (int j = 0; j < A->columns && eq_status == SUCCESS; j++) {
        if ((fabs(A->matrix[i][j] - B->matrix[i][j])) >= 1e-7) {
          eq_status = FAILURE;
        }
      }
    }

  } else {
    eq_status = FAILURE;
  }

  return eq_status;
}