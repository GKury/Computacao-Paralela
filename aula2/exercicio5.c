#include <stdio.h>

int main(void) {
  int matriz [3][2];
  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
     matriz[i][j] = i + j;
    }
    printf("\n");
  }
  
  printf("Matriz:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (int j=0; j<2; j++ ){
    matriz[1][j] = matriz[1][j] * 5;
  }

  printf("\nMatriz com linha 1 multiplicada por 5:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i=0; i < 3; i++ ){
    matriz[i][0] = matriz[i][0] * 5;
  }

  printf("\nMatriz com coluna 0 multiplicada por 5:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

    
  return 0;
}
