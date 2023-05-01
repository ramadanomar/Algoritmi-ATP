#include <stdio.h>
#include <stdlib.h>

double* medie_linie(double** mat, int randuri, int coloane) {
  double* medii = malloc(randuri * sizeof(double));

  for(int i=0; i<randuri; i++) {
    double suma = 0;
    for(int j=0; j<coloane; j++) {
      suma += mat[i][j];
    }
    medii[i] = suma/coloane;
  }

  return medii;
}

int main() {
  int nrRanduri, nrColoane;

  printf("Introdu nr randuri si nr coloane:\n");
  scanf("%d %d", &nrRanduri, &nrColoane);

  double** arr = malloc(nrRanduri * sizeof(double*));

  for(int i=0; i<nrRanduri; i++) {
    arr[i] = malloc(nrColoane * sizeof(double));
    printf("rand %d:\n", i+1);
    for(int j=0; j<nrColoane; j++) {
      scanf("%lf", &arr[i][j]);
    }
  }

  double* vectorMedii = medie_linie(arr,nrRanduri,nrColoane);

  printf("Media Fiecarei Linii este:\n");
  for(int i=0; i<nrRanduri; i++) {
    printf("%.2f ", vectorMedii[i]);
  }
  printf("\n");


  // Garbage Collection
  for(int i=0; i<nrRanduri; i++) {
    free(arr[i]);
  }

  free(arr);
  free(vectorMedii);

  return 0;
}
