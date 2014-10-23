#include <stdio.h>
#include <stdlib.h>

int fact(int);

int main(){
    int n;
    int fatt;
    printf("Calcolo il fattoriale di: ");
    scanf("%d", &n);
    fatt=fact(n);
    printf("%d! = %d\n", n, fatt);
    return 0;
}

int fact(int num){
    if (num == 0) return 1;
    return (num*fact(num-1));
}
