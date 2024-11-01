#include "./s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  double **matrix;
  if (rows < 1 || columns < 1 || result == NULL) {
    result = NULL;
    status = ERROR;
  }
  if (status != ERROR) {
    result->rows = rows;
    result->columns = columns;
    matrix = (double **)calloc(rows + rows * columns, sizeof(double));

    if (matrix == NULL) {
      status = ERROR;
    }

    if (status != ERROR) {
      for (int i = 0; i < rows; i++) {
        matrix[i] = calloc(columns, sizeof(double));
        if (!matrix[i]) status = ERROR;
      }
    }
  }

  if (status != ERROR) {
    result->matrix = matrix;
  }
  return status;
}