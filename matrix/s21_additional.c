#include "./s21_matrix.h"

int s21_validate_matrix(matrix_t *A) {
  int status = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    status = ERROR;
  }
  return status;
}

void s21_minor_matrix(matrix_t *A, matrix_t *result, int row, int col) {
  int di = 0, dj = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != row && j != col) {
        result->matrix[di][dj] = A->matrix[i][j];
        di = dj == result->columns - 1 ? di + 1 : di;
        dj = dj < result->columns - 1 ? dj + 1 : 0;
      }
    }
  }
}
