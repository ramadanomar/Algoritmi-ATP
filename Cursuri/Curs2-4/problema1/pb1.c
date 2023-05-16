#include<stdio.h>

// Structura
typedef struct {
  char nr_inmatriculare[8];
  char marca[20];
  int an_fabricatie;
  long nr_km;
  float valoare;
} Articol;

int main() {
  FILE *fisier = fopen("articole.txt", "w");
  if (fisier == NULL) {
    printf("Nu am putut deschide fisierul\n");
    return -1;
  }

  Articol articole[] = {
  {"AB123CD", "Dacia", 2022, 5000, 10000.5},
  {"EF456GH", "BMW", 2000, 40000, 5000}
  };

  int nrArticole = sizeof(articole) / sizeof(Articol);

  for(int i=0; i<nrArticole; i++) {
    fprintf(fisier, "%s %s %d %ld %.2f\n", articole[i].nr_inmatriculare, articole[i].marca, articole[i].an_fabricatie, articole[i].nr_km, articole[i].valoare);
 }

  fclose(fisier);

  printf("Gata scrierea in articole.txt\n");
  
  return 0;
}
