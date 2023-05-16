#include <stdio.h>
#include <stdlib.h>

double* mergeArrays(double* array1, int size1, double* array2, int size2) {
  
  double* mergedArray = (double*)malloc(sizeof(double)*(size1+size2));
  
  // Iteratori
  int i=0,j=0,k=0;

  while(i<size1 && j<size2) {
    if(array1[i] >= array2[j]) {
      mergedArray[k++] = array1[i++];
    } else {
      mergedArray[k++] = array2[j++];
    }
  }

  while(i<size1) {
    mergedArray[k++] = array1[i++];
  }
  
  while(j<size2) {
    mergedArray[k++] = array2[j++];
  }
  
  return mergedArray;
}

int main() {
  double array1[] = {10, 8, 6, 4, 2};
  int size1 = sizeof(array1) / sizeof(array1[0]);

  double array2[] = {9, 7, 5, 3, 1};
  int size2 = sizeof(array2) / sizeof(array2[0]);

  double* mergedArray = mergeArrays(array1, size1, array2, size2);

  for(int i=0; i<size1+size2; i++) {
    printf("%.2f ", mergedArray[i]);
  }

  free(mergedArray);

  return 0;
}
