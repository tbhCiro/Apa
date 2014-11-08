#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

typedef struct item{
	int n;
	char *string;
}item;

void usage(char*);
void acquisisci_interi(FILE *, item *, int);
int less_int(item, item);
// merge func
void mergesortint(item *, int, int);
void mergeint();
//int eq_int(item, item);
int less_string(item, item);
//int eq_string(item, item);


int less_int(item a, item b){
	return(a.n - b.n);
} // int less

//int eq_int(item a, item b){
//	if (item a.n == item b.n) return 0;
//	return 1;
//} // int eq_int

int less_string(item a, item b){
	return (strcmp(a.string, b.string));
} // int less_stringh

void acquisisci_interi(FILE *file, item *vett, int lines){
	int i;

//	fscanf(file, "%d", &*lines);
	vett=malloc(lines*sizeof(item));
	printf("1\n");
	for (i=0; i<lines; i++){
	  	fscanf(file, "%d", &vett[i].n);
		printf("%d\n", vett[i].n);
	}
	printf("2\n");
}

void usage(char *str){
	printf("==> USO: %s -s stringhe.txt\n", str);
	printf("==>      %s -d interi.txt\n", str);
}

void mergesortint(item *V, int l, int r){
	int q;	// valore di mezzo con cui dividerò il vettore
	q=(l+r)/2;
	if (r<=l) return;	// condizione di terminazione del ciclo	
	mergesortint(V, l, q); // sottovettore di sinistra
	mergesortint(V, q+1, r);	// sottovettore di destra
	mergeint(V, l, q, r);	// chiamata alla funzione che "mergea" i vettori.
} // void mergesort

void mergeint(item *V, int l, int q, int r){
	int i, j, k;
	item W[MAX];	// vettore di appoggio
	i=l; 
	j=q+1;
	for (k=l; k<=r; k++){
		if (i>q) W[k]=V[j++];		// sottovettore di dx
		else if (j>r) W[k]=V[i++];	// sottovettore di sx
		else if (less_int(V[i], V[j]) <= 0) W[k]=V[i++];
		else W[k]=V[j++];
	}//for k
	for (k=l; k<=r; k++) V[k]=W[k];
} // void mergeint()

int main (int argc, char **argv){
	int num, i;
	FILE *f1;
	item *V=NULL;
	if (argc!=3) {
		usage(argv[0]);
		return 1;
	}
	f1=fopen(argv[2], "r");
	if (strcmp(argv[1], "-d")==0){
		fscanf(f1, "%d", &num);
		acquisisci_interi(f1, V, num);
		printf("3\n");
		//mergesortint(V, 0, num);		
	/*elseif (strcmp(argv[1], '-s')==0){
		acquisisci_stringhe;
		ordina_stringhe;
	}else{
		usage(argv[0]);
		return 2;*/
	}	

	//free(V);
	//fclose(f1);
	
	for (i=0; i<num; i++); 
	//	printf("%d\n", V[i].n);
	return 0;
}
