#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 35

typedef struct dati{
   char *name;
   int day, month, year;
   char sex;
}stud;

char* scrivinome(char *);
void ordina(stud*, int, int);
int diffnascita(stud, stud);
int year(stud);
int month(stud);
int day(stud);


int main(int argc, char **argv){
   if (argc != 2) return -1;
   int N, i;
   stud *studenti;
   FILE *fp, *fboys, *fgirls;
   char tmp[MAX];
   if ((fp=fopen(argv[1], "r")) == NULL) return -2;
   fscanf(fp, "%d", &N);
   studenti=malloc(N*sizeof(stud));
   printf("Studenti che carico in memoria:\n");
   for (i=0; i<N; i++){
      fscanf(fp, "%s %d/%d/%d %c", tmp, &studenti[i].day, &studenti[i].month, &studenti[i].year, &studenti[i].sex);
      studenti[i].name=scrivinome(tmp);
      printf("%s -> %d/%d/%d -> %c\n", studenti[i].name, studenti[i].day, studenti[i].month, studenti[i].year, studenti[i].sex );
   }//i
   /* Implementare ordinamento */
   ordina(studenti, 0, N-1);
   // fine ordinamento
   if ((fgirls=fopen("ragazze.txt", "w")) == NULL) return -3;
   if ((fboys=fopen("ragazzi.txt", "w")) == NULL) return -4;
   for(i=0; i<N; i++){
      if (studenti[i].sex == 'F'){
         fprintf(fgirls, "%s %d/%d/%d\n", studenti[i].name, studenti[i].day, studenti[i].month, studenti[i].year);
      }else{
         fprintf(fboys, "%s %d/%d/%d\n", studenti[i].name, studenti[i].day, studenti[i].month, studenti[i].year);
      }
   }//i
   printf("\n");
   for (i=0; i<N; i++){
   //fscanf(fp, "%s %d/%d/%d %c", tmp, &studenti[i].day, &studenti[i].month, &studenti[i].year, &studenti[i].sex);
      printf("%s -> %d/%d/%d -> %c\n", studenti[i].name, studenti[i].day, studenti[i].month, studenti[i].year, studenti[i].sex );
   }//i

   free(studenti);
   fclose(fp); fclose(fgirls); fclose(fboys);
   return 0;
}//main

char *scrivinome(char *old){
   int j=strlen(old);
   char *new_s;
   new_s=malloc(j*sizeof(char));
   strcpy(new_s, old);
   return new_s;
}// scrivinome

int diffnascita(stud a, stud b){
   if (year(a)!=year(b)) return (year(b)-year(a));
   if (month(a)!=month(b)) return (month(b)-month(a));
   if (day(a)!=day(b)) return (day(b)-day(a));
   return 0;
}//int diffnascita()

void ordina(stud* vett, int l , int r){
	int i, j, min;
	stud temp;
	for(i = l; i < r; i++) {
		min = i;
	for (j = i+1; j <= r; j++)
		if (diffnascita(vett[min], vett[j]))
			min = j;
	temp = vett[i];
	vett[i] = vett[min];
	vett[min] = temp;
	}
	return;
}// void ordina()

int year(stud studente) { return (studente.year); }
int month(stud studente) { return (studente.month); }
int day(stud studente) { return (studente.day); }

