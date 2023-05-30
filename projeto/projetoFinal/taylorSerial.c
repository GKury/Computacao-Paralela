#include <stdio.h>
#include <gmp.h>

int main(void) {
  mpf_set_default_prec(1000); // Define a precisão padrão para 1000 bits

  mpf_t soma, termo, count;
  mpf_init(soma);
  mpf_init(termo);              //Declara Variaveis
  mpf_init(count);

  mpf_set_d(soma, 1.0);
  mpf_set_d(termo, 1.0);       //Atribui as variaveis
  mpf_set_d(count, 1.0);

  while (mpf_get_d(termo) > 1e-100) {
    mpf_div_ui(termo, termo, mpf_get_ui(count)); 
    mpf_add(soma, soma, termo);                     // Calcula a serie         
    mpf_add_ui(count, count, 1); 
  }

  char resultado[256];
  mp_exp_t exp;
  mpf_get_str(resultado, &exp, 10, 0, soma); // Converte o valor da soma pra uma string

  printf("%sE%ld\n", resultado, exp); // Print em formato científico

  mpf_clear(soma);
  mpf_clear(termo);     //Memoria
  mpf_clear(count);

  return 0;
}
