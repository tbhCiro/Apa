#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    float x, y, z, x_sum=0, y_sum=0, z_sum=0;
    int counter=0;
    if (argc != 2) return 1;
    FILE *elenco;
    elenco=fopen(argv[1], "r");
    while ((fscanf(elenco, "%f %f %f", &x, &y, &z)) != EOF){

        printf("%f %f %f\n", x, y, z);
        x_sum+=x;
        y_sum+=y;
        z_sum+=z;
        counter++;
    }
    printf("Baricentro: %.1f %.1f %.1f\n", x_sum/counter, y_sum/counter, z_sum/counter);
    fclose(elenco);
    return 0;
}
