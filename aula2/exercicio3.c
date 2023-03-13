#include <stdio.h>

int main(void) {
  int tamanho;
  printf("Insira o numero maximo (impar) da piramide\n");
  scanf("%d", &tamanho);
  while (tamanho%2 != 1){
    printf("\n Numero invalido. Insira um novo numero (impar)\n");
    scanf("%d", &tamanho);
  }
  float parada = tamanho/2.0 + 0.5;
  int i = 0;
  int tab;
  int aux;
  while (i < parada){
    aux = i;
    tab = 0;
    while (tab < i){
      printf("\t");
      fflush( stdout );
      tab++;
    }
    while (aux < tamanho){
      printf("%d\t", aux+1);
      aux++;
    }
    i++;
    tamanho--;
    printf("\n");
  }
  return 0;
}
