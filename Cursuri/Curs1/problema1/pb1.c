#include <stdio.h>

// Function Prototype
double calc_medie(int vector[], int size);

int main() {
  int vector[] = {1,2,3,4,5,6,7};

  int size = sizeof(vector) / sizeof(vector[0]);

  double medie = calc_medie(vector, size);

  printf("Media este: %.2f\n", medie);

  return 0;
}


double calc_medie(int vector[], int size) {
  int suma = 0;

  for(int i=0; i< size; i++) {
    suma += vector[i];
  }
  
  // Trb sa facem converitrea tipului altfel int impartit la int tot intreg va da.
  double medie = (double)suma/size;

  return medie;
}
