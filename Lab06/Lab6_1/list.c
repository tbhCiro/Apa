/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  source file for list.h headers lab 6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 05:52:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Umberto Reale (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"list.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage_lista
 *  Description:  stampa la "sintassi per l'interfaccia di list.c"
 * =====================================================================================
 */
void usage_lista (){
	int i=0;
	printf(">> <Lista> >> %d: Cardinalità della lista;\n", ++i);
	printf(">> <Lista> >> %d: Inserimento all'inizio;\n", ++i);
	printf(">> <Lista> >> %d: Inserimento alla fine;\n", ++i);
	printf(">> <Lista> >> %d: Ricerca;\n", ++i);
	printf(">> <Lista> >> %d: Estrazione;\n", ++i);
	printf(">> <Lista> >> %d: Stampa intera lista;\n", ++i);
	printf(">> <Lista> >> %d: Distruzione della lista;\n", ++i);
	printf(">> <Lista> >> %d: Aiuto;\n", ++i);
	printf(">> <Lista> >> %d: Uscita;\n", ++i);
	return;
}		/* -----  end of function usage_lista  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lista
 *  Description:  "main" function of this file
 * =====================================================================================
 */
void lista (){	
	int cmd=0, continua=1;	
	usage_lista();
	while (continua){
		printf(">> <Lista> >> ");
		scanf("%d", &cmd);

		if ( cmd == 1 ){
			printf ("Card\n");
		}else if ( cmd == 2 ){
			printf ("ins all'inizio\n");
		}else if ( cmd == 3 ){
			printf ("ins alla fine\n");
		}else if ( cmd == 4 ){
			printf ("ricerca\n");
		}else if ( cmd == 5 ){
			printf ("estrai\n");
		}else if ( cmd == 6 ){
			printf ("stampa lista\n");
		}else if ( cmd == 7 ){
			printf ("distruggi lista\n");
		}else if ( cmd == 8 ){
			usage_lista();
		}else if ( cmd == 9 ){
			printf("esci\n");
			continua=0;
		}
	}
	return;
}		/* -----  end of function lista  ----- */



