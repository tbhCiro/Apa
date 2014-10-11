#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 30

int periodica(char *str);

int periodica(char *str){
    int i, j=0, x, flag=0, lung, n_sub, l_sub;
    lung=strlen(str);
    for (i=0; i<lung; i++) str[i]=tolower(str[i]);
    if (!strcmp(str,"stop")) return 0;  //caso "stop"
    if (lung==1) return -1; //caso str composta da una sola lettera
    // caso tutte lettere uguali
    for(i=1; i<=lung; i++){
        if (str[0]==str[i]) flag++;
    }if (flag==(lung-1)) return 1;
    flag=0;
    //cerco periodicità
    for (i=lung/2; i>=2; i--){
        if ((lung%i)==0){
            n_sub=i; l_sub=lung/n_sub;
            for (j=0; j<l_sub; j++){
                for (x=1; x<=n_sub; x++){
                        if (str[j]==str[j+(x*l_sub)]) flag++;
                }//for x
            }//for j
            if (flag==(lung-l_sub)) return l_sub;
        }//if lung%i
        flag=0;
    }//for i

    return -1;
} //void

int main(void){
    char stringa[N];
    int T;
    printf("Cerco periodicità nelle stringhe.\nDigitare stop per uscire.\n");
    while(strcmp(stringa,"stop")){
        printf("Stringa? ");
        scanf("%s", stringa);
        T=periodica(stringa);
        if (T == -1){
            printf("La stringa %s non è periodica.\n", stringa);
        }else if (T != 0){
            printf("La stringa %s ha periodo %d.\n", stringa, T);
        }
    }
    return 0;
} //main
