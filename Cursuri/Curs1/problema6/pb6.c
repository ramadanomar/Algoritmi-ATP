#include <stdio.h>
#include <stdlib.h>

int logica(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

void sortare(int **mat, int rows, int cols) {
  for(int i=0; i<rows; i++) {
    qsort(mat[i], cols, sizeof(int), logica);
  }
}

int **creare_matrice(int rows, int cols) {
  int **mat = (int **)malloc(rows * sizeof(int *));
  for(int i=0; i<rows;i++) {
    mat[i] = (int *)malloc(cols * sizeof(int));
  }
  return mat;
}

void free_matrix(int **mat, int rows) {
  for(int i=0; i<rows;i++) {
    free(mat[i]);
  }
  free(mat);
}

void afisare(int **mat, int rows, int cols) {
  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows, cols;

  printf("Nr Randuri: ");
  scanf("%d", &rows);

  printf("Nr Coloane: ");
  scanf("%d", &cols);

  int **mat = creare_matrice(rows,cols);

  printf("Elementele matricii:\n");
  for(int i=0; i<rows;i++) {
    for(int j=0;j<cols;j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  sortare(mat, rows, cols);

  printf("Matricea sortata este:\n");
  afisare(mat, rows, cols);

  free_matrix(mat, rows);

  return 0;
}
