#include <stdio.h>

double medie_matrice(int x[3][3],int n, int m);

int main() {
  int n = 3, m=3;
  int mat[n][m];
  for (int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      mat[i][j] = i*j;
    }
  }

  double medie = medie_matrice(mat, n, m);

  printf("Media este: %2f\n", medie);

  return 0;
}

double medie_matrice(int x[3][3], int n, int m) {
  int s = 0;
  for (int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      s+= x[i][j];
    }
  }
  
  // n*m = nr elemente din matrice
  double medie = (double)s/(n*m);
  return medie;
}

