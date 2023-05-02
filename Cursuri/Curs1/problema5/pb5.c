#include <stdio.h>
#include <stdlib.h>

// cmmdc recursiv
int gcd(int a, int b) {
  if(b==0)
    return a;
  return gcd(a, a%b);
}


// dintr-un vector
int findGCD(int arr[], int n) {
  int result = arr[0];
  for(int i=1; i < n; i++) {
    result = gcd(arr[i], result);

    if(result == 1)
      return 1;
  }
  return result;
}


int main() {
  int n;
  printf("Introdu nr de elemente din vector: ");
  scanf("%d", &n);

  if(n<=0) {
    printf("Marimea vectorului trb sa fie un nr poz");
    return 1;
  }
  
  // Alocare Dinamcia
  int* arr = (int*)malloc(n* sizeof(int));

  if(!arr) {
    printf("Memoria nu poate fi alocata.\n");
    return 1;
  }

  printf("Introduceti %d nr. pozitive: ", n);

  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
    if(arr[i] <= 0) {
      printf("Inputul nu este valid. Nr trb sa fie pozitive\n");
      free(arr);
      return 1;
    }
  }

  int result = findGCD(arr, n);
  printf("CMMDC al vectorului este: %d\n", result);

  // Garbage Collection
  free(arr);
  return 0;
}
