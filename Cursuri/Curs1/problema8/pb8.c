#include <stdio.h>

int cautareBinara(double arr[], int st, int dr, double x) {
  if(dr>=st) {
    int mij= st+ (dr-st)/2;

    // daca elem este fix in mij vectorului
    if(arr[mij] == x)
      return mij;

    //Mai mic decat mij;
    if(arr[mij] > x)
      return cautareBinara(arr,st,mij-1,x);
    
    return cautareBinara(arr,mij+1,dr,x);
  }

  return -1;
}

void verificaApartenenta(double arr[], int n, double x) {
  int rez = cautareBinara(arr, 0, n-1, x);
  (rez == -1) ? printf("Elementul nu este prezent in vector\n") : printf("Elementul este prezent in vector\n");
}

int main(void) {
  double arr[] = {2.3,3.4,4.7,6.8,12.5,34.5,50.9};
  int n = sizeof(arr) / sizeof(arr[0]);

  double x = 34.6;

  verificaApartenenta(arr, n, x);

  return 0;
}
