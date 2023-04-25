#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double num) {
    return exp(num);
}

int main(void) {
    double a, b;
    int n;
  
    printf("Insira os seguintes valores: a <espaco> b <espaco> n\n");
    scanf("%lf %lf %d", &a, &b, &n);
  
    double h = (b-a)/n;
    double approx = (f(a) + f(b))/2.0;

    #pragma omp parallel for reduction(+:approx)
    for(int i = 1; i <= n-1; i++) {
        double x_i = a + i*h;
        approx += f(x_i);
    }
  
    approx = h*approx;

    printf("Resultado = %lf", approx);
  
    return 0;
}
