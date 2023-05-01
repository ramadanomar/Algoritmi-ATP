#include <stdio.h>

// CONSTANTE
int N=5, M=5;

// Prototipul functiei
int min(int x[N][M]);

int max(int x[N][M]);

// Main
int main() {
  int mat[N][M];
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      mat[i][j]=i*j;
    }
  }

  int minim = min(mat);
  int maxim = max(mat);

  printf("MIN: %2d\nMAX: %2d", minim, maxim);
}

int min(int x[N][M]) {
  int minim = x[N][M];
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(minim > x[i][j])
        minim = x[i][j];
    }
  }
  return minim;
}

int max(int x[N][M]) {
  int maxim = x[0][0];
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(maxim < x[i][j])
        maxim = x[i][j];
    }
  }
  return maxim;
