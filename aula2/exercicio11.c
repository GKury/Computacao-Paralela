#include <stdio.h>

int main(void) {
  int matriz [3][3];

  for (int i=0; i<3; i++ ){
    for (int j=0; j<3; j++ ){
      matriz[i][j] = i+j;
    }
  }

 printf("Matriz:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (int j=0; j<3; j++){
    matriz[1][j] = matriz[1][j] + matriz[0][j];
  }

  printf("\n\nMatriz com L2 virando L1 + L2:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (int j=0; j<3; j++){
    matriz[1][j] = matriz[1][j] * matriz[0][j];
  }

  printf("\n\nMatriz com L2 virando L1 * L2:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
