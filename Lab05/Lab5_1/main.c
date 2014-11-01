#include <stdio.h>
#include <stdlib.h>

void change(int, int); //prototipo

void change(int base, int numero){
  //int X;
  if (numero < base){ 
    printf("%d", numero);
  }else{
    change(base, (numero-(numero%base))/base);
    printf("%d", numero%base);
  }
//  return;
}

int main(int argc, char **argv) {
  int num, base;
  printf("Immetti un numero in base 10: ");
  scanf("%d", &num);
  printf("Immetti una base (tra 2 e 10): ");
  scanf("%d", &base);
  if (base<2 || base>10) return -1;
  change(base, num);
  printf("\n");
  return 0;
}//main ()