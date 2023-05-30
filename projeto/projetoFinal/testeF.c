#include <stdio.h>
#include <gmp.h>
#include <pthread.h>

typedef struct {
  mpf_t soma;
  mpf_t termo;
  mpf_t count;
  unsigned int start;
  unsigned int end;
} ThreadArgs;

void *calculateSeries(void *arg) {
  ThreadArgs *args = (ThreadArgs *)arg;

  unsigned int start = args->start;
  unsigned int end = args->end;

  mpf_t soma, termo, count;
  mpf_init(soma);
  mpf_init(termo);
  mpf_init(count);

  mpf_set_ui(soma, 0);
  mpf_set_ui(termo, 1);
  mpf_set(count, args->count);

  for (unsigned int i = start; i <= end; i++) {
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
  mpf_set_default_prec(100000); // Aumenta a precisão para 100000 bits

  mpf_t soma, termo, count;
  mpf_init(soma);
  mpf_init(termo);
  mpf_init(count);

  mpf_set_d(soma, 0.0);
  mpf_set_d(termo, 1.0);
  mpf_set_d(count, 0.0);

  pthread_t thread1, thread2;
  ThreadArgs args1, args2;

  unsigned int totalIterations = 1000;
  unsigned int midPoint = totalIterations / 2;

  mpf_init(args1.soma);
  mpf_init(args1.termo);
  mpf_init(args1.count);
  args1.start = 2;
  args1.end = midPoint;

  mpf_init(args2.soma);
  mpf_init(args2.termo);
  mpf_init(args2.count);
  args2.start = midPoint + 1;
  args2.end = totalIterations;

  pthread_create(&thread1, NULL, calculateSeries, (void *)&args1);
  pthread_create(&thread2, NULL, calculateSeries, (void *)&args2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  mpf_add(soma, args1.soma, args2.soma);

  mpf_t result;
  mpf_init(result);
  mpf_add(result, soma, termo);

  char resultStr[100000];
  mp_exp_t exp;
  mpf_get_str(resultStr, &exp, 10, 0, result);

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
  mpf_clear(result);

  return 0;
}

