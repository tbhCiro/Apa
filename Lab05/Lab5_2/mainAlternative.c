/* grazie a Ewawes */
#include<stdio.h>
#include<stdlib.h>

void use (char*);
int catalan (int);

int catalan(int n){
	int i, sum=0;
	if (n==0) return 1;
	for (i=0; i<n; i++)
		sum = sum + (catalan(i)*catalan(n-1-i));
	return sum;
}

void use (char *str){
	printf("\n==> USO: %s n\n\n		n è il numero per il quale calcolare Catalan.\n", str);
}

int main (int argc, char **argv){
	if (argc != 2) {
		use(argv[0]);
		return -1;
	}
	int N=atoi(argv[1]);
	printf("Il Catalan di %d è %d.\n", N, catalan(N));	
	return 0;
}
