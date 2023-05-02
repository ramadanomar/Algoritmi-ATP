#include <stdio.h>
#include <stdlib.h>

int findFirst(int arr[], int marime, int key) {
  for(int i=0; i<marime; i++) {
    if(arr[i] == key){
      return i;
    }
  }
  return -1;
}

int findAll(int arr[], int marime, int key, int **result) {
  int count = 0;
  *result = NULL;

  for(int i=0; i<marime; i++) {
    if(arr[i]==key) {
      count++;
      *result = realloc(*result, count*sizeof(int));
      (*result)[count-1] =i;
    }
  }
  return count;
}

void afisareVector(int arr[], int marime) {
  printf("[ ");
  for(int i=0;i<marime;i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int main() {
  int arr[] = {1,2,3,4,2,7,3,1,5,8,3,2,1,8,5,6,7,8,9};
  int marime = sizeof(arr)/sizeof(arr[0]);
  int key = 2;

  int primaAparitie = findFirst(arr, marime, key);
  printf("Prima aparitie: %d\n", primaAparitie);

  int *aparitii;
  int count = findAll(arr, marime, key, &aparitii);
  printf("Toate aparitiile: ");
  afisareVector(aparitii,count);

  free(aparitii);

  return 0;
}

