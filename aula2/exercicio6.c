#include <stdio.h>

int main(void) {
  int matriz [3][2];

  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
      matriz[i][j] = i+j;
    }
  }

 printf("Matriz:\n\n");
  for (int i=0; i<3; i++ ){
    for (int j=0; j<2; j++ ){
     printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  int matrizT [2][3];
    for (int i=0; i<2; i++ ){
      for (int j=0; j<3; j++ ){
        matrizT[i][j] = matriz[j][i];
    }
  }

  printf("\nMatriz Transposta:\n\n");
  for (int i=0; i<2; i++ ){
    for (int j=0; j<3; j++ ){
     printf("%d\t", matrizT[i][j]);
    }
    printf("\n");
  }
  return 0;
}
