#include <stdio.h>
#include <math.h>

double f(double num)
{
  return exp(num);
}

int main(void) {
  double a, b;
  int n;
  
  printf("Insira os seguintes valores: a <espaco> b <espaco> n\n");

  scanf("%lf %lf %d", &a, &b, &n);
  
  float h = (b-a)/n;
  float approx = (f(a) + f(b))/2.0;

  for(int i = 1; i <= n-1; i++){
    float x_i = a + i*h;
    approx += f(x_i);
  }
  
  approx = h*approx;

  printf("Resultado = %f", approx);
  
  return 0;
}
