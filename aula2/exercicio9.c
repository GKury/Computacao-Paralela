#include <stdio.h>

int main(void) {
  int matriz [2][3];

  for (int i=0; i<2; i++ ){
    for (int j=0; j<3; j++ ){
      matriz[i][j] = -5 + i*j*6;
    }
  }

 printf("Matriz:\n\n");
  for (int i=0; i<2; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i=0; i<2; i++ ){
    for (int j=0; j<3; j++ ){
      if(matriz[i][j] < 0){
        matriz[i][j] = matriz[i][j] * -1;
      }
    }
  }

  printf("\n\nMatriz com modulo nos negativos:\n\n");
  for (int i=0; i<2; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}
