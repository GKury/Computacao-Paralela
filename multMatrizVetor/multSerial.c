#include <stdio.h>
#include <stdlib.h>

#define N 500
                                            //Declaracoes globais
int matriz[N][N], vetor[N], resultado[N];

void multiplica() {
    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j < N; j++) {          //funcao que faz o processo
            soma += matriz[i][j] * vetor[j];
        }
        resultado[i] = soma;
    }

}

int main() {
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 10;
        for (int j = 0; j < N; j++) {    //Gera matriz e vetor com numeros aleatorios
            matriz[i][j] = rand() % 10;
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {      // Printa a matriz
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Vetor:\n");
    for (int i = 0; i < N; i++) {          //Printa o vetor
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    multiplica();                          //Gera resultado
    
    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);  //Printa o resultado
    }
    printf("\n");

    return 0;
}
