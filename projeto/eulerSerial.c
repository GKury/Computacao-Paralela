#include <stdio.h>

int main(void) {
  long double soma = 1.0;
  long double fatorial = 1.0;
  long double count = 2.0;
  
  while (count < 22){
    soma += 1/fatorial;
    fatorial *=count;
    count++;
  }
  printf("%.65Lf\n", soma); //18 casas
  
  return 0;
}
