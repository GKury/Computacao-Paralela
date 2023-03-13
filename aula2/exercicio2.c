#include <stdio.h>

int main(void) {
  float n1 = 9;
  float n2 = 7;
  float n3 = 5;
  float me = (n1 + n2+ n3)/3;
  float ma = (n1 + n2*2 + n3*3 + me)/7;

  printf("N1: %f\tN2: %f\tN3: %f\nME: %f\nMA: %f\n", n1, n2, n3, me, ma);
  
  if (ma >= 9){
    printf("A");
  } else if(ma >= 7.5){
    printf("B");
  } else if (ma >= 6){
    printf("C");
  } else if (ma >= 4){
    printf("D");
  } else{
    printf("E");
  }
  
  return 0;
}
