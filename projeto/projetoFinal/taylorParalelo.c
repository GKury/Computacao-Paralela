#include <stdio.h>
#include <gmp.h>
#include <pthread.h>

typedef struct {
  mpf_t soma;
  mpf_t termo;
  mpf_t count;          //Struct para func
  unsigned int comeco;
  unsigned int fim;
} ThreadArgs;

void *calculaTaylor(void *arg) {
  ThreadArgs *args = (ThreadArgs *)arg;

  unsigned int comeco = args->comeco;
  unsigned int fim = args->fim;

  mpf_t soma, termo, count;
  mpf_init(soma);
  mpf_init(termo);
  mpf_init(count);

  mpf_set_ui(soma, 0);
  mpf_set_ui(termo, 1);                 //Calcula serie de taylor paralelamente
  mpf_set(count, args->count);

  for (unsigned int i = comeco; i <= fim; i++) {
    mpf_div_ui(termo, termo, i);
    mpf_add(soma, soma, termo);
    mpf_add_ui(count, count, 1);
  }

  mpf_set(args->soma, soma);
  mpf_set(args->termo, termo);
  mpf_set(args->count, count);

  mpf_clear(soma);
  mpf_clear(termo);
  mpf_clear(count);

  return NULL;
}

int main(void) {
  mpf_set_default_prec(100000); // Setta precisão pra 100000 bits

  mpf_t soma, termo, count;
  mpf_init(soma);
  mpf_init(termo);              
  mpf_init(count);
                            
  mpf_set_d(soma, 0.0);
  mpf_set_d(termo, 1.0);
  mpf_set_d(count, 0.0);

  pthread_t thread1, thread2;       //declara threads
  ThreadArgs args1, args2;          

  unsigned int nIteracoes = 1000;
  unsigned int meio = nIteracoes / 2;

  mpf_init(args1.soma);
  mpf_init(args1.termo);
  mpf_init(args1.count);
  args1.comeco = 2;
  args1.fim = meio;

  mpf_init(args2.soma);
  mpf_init(args2.termo);
  mpf_init(args2.count);
  args2.comeco = meio + 1;
  args2.fim = nIteracoes;

  pthread_create(&thread1, NULL, calculaTaylor, (void *)&args1);        //chama as threads
  pthread_create(&thread2, NULL, calculaTaylor, (void *)&args2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);                                      //sincroniza

  mpf_add(soma, args1.soma, args2.soma);

  mpf_t resultado;
  mpf_init(resultado);
  mpf_add(resultado, soma, termo);

  char resultStr[100000];
  mp_exp_t exp;
  mpf_get_str(resultStr, &exp, 10, 0, resultado);

  printf("%sE%ld\n", resultStr, exp);

  mpf_clear(soma);
  mpf_clear(termo);
  mpf_clear(count);
  mpf_clear(args1.soma);
  mpf_clear(args1.termo);
  mpf_clear(args1.count);
  mpf_clear(args2.soma);
  mpf_clear(args2.termo);
  mpf_clear(args2.count);
  mpf_clear(resultado);

  return 0;
}
