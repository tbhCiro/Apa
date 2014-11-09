/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main file for 5.4 lab
 *
 *        Version:  1.0
 *        Created:  11/08/2014 05:31:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Umberto Reale (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


/*-----------------------------------------------------------------------------
 *  Data Struct
 *-----------------------------------------------------------------------------*/
typedef struct nodo *link;
struct nodo{
	char cod[11];
	link next;	// link al nodo successivo
};

/*-----------------------------------------------------------------------------
 *  Proto
 *-----------------------------------------------------------------------------*/
void usage (int);
link add_node (char *);  
void print_all (link);
void print_first ();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
link head=NULL;	// puntatore in testa alla lista.

int main ( int argc, char **argv ){
	int continua=1;
	char stringa[11];
	char *comando=malloc(sizeof(char));
	system("clear");
	usage(0);
	while ( continua ) {
		printf (">> ");
		scanf ("%s", comando);
		if (strlen(comando)!=1) {
			usage(1);		// il comando non può essere più lungo di una lettera!
			continue;	// quindi se lo è salta all'iterazione successiva dopo aver lanciato usage();.
		}
		comando[0]=toupper(comando[0]);
		if ( comando[0] == 'A'  ){
//			printf("Aggiungo nodo alla lista (in coda):\n");
			printf(">> <Adding node function> >> Inserire codice di 10 cifre: ");
			scanf("%s", stringa);
			head=add_node(stringa);
		}else	if ( comando[0] == 'S'  ){
			printf("Stampo il primo della lista\n");
		}else	if ( comando[0] == 'T'  ){
			print_all(head);
		}else	if ( comando[0] == 'E'  ){
			printf("Esco\n");
			return EXIT_SUCCESS;
		}else{
			usage(1);
		}
	}// while ( continua )
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage
 *  Description:  Simply printf the program "syntax" 
 * =====================================================================================
 */
void usage (int a){
	if (a) printf("Comando non trovato!\n");
	printf("<<< [A]ggiungi in coda, [S]tampa il primo, s[T]ampa tutti, [E]sci >>>\n");
}		/* -----  end of function usage  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  add_node
 *  Description:  aggiunge nodo alla lista, controlla che la lista non sia vuota
 *  					in tal caso la inizializza.
 * =====================================================================================
 */
link add_node (char *str){
	link k, tmp=malloc(sizeof *tmp);
	tmp->next=NULL;
	strcpy(tmp->cod,str);
	if ( head == NULL )	{
		head=tmp;
	}else{
		k=malloc(sizeof *k);
		// cerco il nodo finale a al suo ->next pianto tmp
		for (k=head; k->next!=NULL; k=k->next);
		k->next=tmp;	
	}
	return head;
}		/* -----  end of function add_node  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_all
 *  Description:  printf all list 
 * =====================================================================================
 */
void print_all (link t){
	int i=1;
	 
	for (t=head ; t!=NULL ; t=t->next){
		printf (">> <printing function> >> %2d) %s\n", i++, t->cod);
		//t=t->next;
	}	
	return;
}		/* -----  end of function print_all  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_first
 *  Description:  print & delete first entry in list
 * =====================================================================================
 */
void print_first ( ){
	return;
}		/* -----  end of function print_first  ----- */

