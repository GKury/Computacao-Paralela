#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 250
#define N 500
                                            //Declaracoes globais
int matriz[N][N], vetor[N], resultado[N];
pthread_t tid[NTHREADS];
int thread_id[NTHREADS];

void *multiplica(void *arg) {
    int id = *(int *) arg;
    int comeco = id * (N / NTHREADS);
    int fim = comeco + (N / NTHREADS);

    for (int i = comeco; i < fim; i++) {      //Funcao que faz a mult. Eh chamada
        int soma = 0;                         //por varias threads ao mesmo tempo 
        for (int j = 0; j < N; j++) {
            soma += matriz[i][j] * vetor[j];
        }
        resultado[i] = soma;
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

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

    
    for (int i = 0; i < NTHREADS; i++) {
        thread_id[i] = i;                        //Cria as threads e chama a func
        pthread_create(&tid[i], NULL, multiplica, &thread_id[i]);
    }

    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    
    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);  //Printa o resultado
    }
    printf("\n");

    return 0;
}
