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

  
  int menor = matriz [0][0];
  int guardalinha = 0;

  for (int i=0; i<3; i++ ){
    for (int j=0; j<3; j++ ){
      if (matriz[i][j] < menor){
       menor = matriz[i][j];
       guardalinha = i;
     }
    }
  }

  printf("\nConsiderando que as linhas começam em 0, a linha que contém o menor valor é: %d", guardalinha);
  return 0;
}
