#include <stdio.h>
#include <pthread.h>

long double somat1, somat2;

struct argumentos{
long double soma;
long double fatorial;
long double count;
long double parada;
};

void * func (void * arg){
  struct argumentos * ag = (struct argumentos *)(arg);
  
  while (ag->count < ag->parada){
    ag->soma += 1/ag->fatorial;
    ag->fatorial *=ag->count;
    ag->count++;
  }
  if(ag->parada == 22){
    somat2 = ag->soma;
  } else{
    somat1 = ag->soma;
  }
}

int main(void) {
  pthread_t t1, t2;

  struct argumentos a1 = {1.0, 1.0, 2.0, 11.0};
  struct argumentos a2 = {0.0, 3628800.0, 11.0, 22.0};

  pthread_create(&t1, NULL, func, (void *)(&a1));
  pthread_create(&t2, NULL, func, (void *)(&a2));

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
 
  //exit(0);

  somat1 += somat2;
  
  printf("%.65Lf\n", somat1);
  
  return 0;
}
