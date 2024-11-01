#include "./s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    status = ERROR;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;
  }

  if (status == OK) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else if (A->rows > 2) {
      int sign = 1;
      *result = 0;
      for (int i = 0; i < A->columns && status == OK; i++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_minor_matrix(A, &minor, 0, i);
        if (minor.matrix == NULL) {
          status = ERROR;
        } else {
          double minor_det = 0;
          status = s21_determinant(&minor, &minor_det);
          if (!status) {
            *result += sign * A->matrix[0][i] * minor_det;
            sign = -sign;
          }
          s21_remove_matrix(&minor);
        }
      }
    }
  }

  return status;
}