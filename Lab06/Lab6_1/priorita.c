/*
 * =====================================================================================
 *
 *       Filename:  priorita.c
 *
 *    Description:  source for priorita.h lab 6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 07:52:51 PM
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
#include"priorita.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage_priorita
 *  Description:  stampa la "sintassi" utile al file priorita.c
 * =====================================================================================
 */
void usage_priorita (){
	int i=0;
	printf(">> <Priorita> >> %d: Cardinalità della coda a priorità;\n", ++i);
	printf(">> <Priorita> >> %d: Inserimento in base alla media;\n", ++i);
	printf(">> <Priorita> >> %d: Estrazione elemento a massima usage_priorita;\n", ++i);
	printf(">> <Priorita> >> %d: Stampa intera coda;\n", ++i);
	printf(">> <Priorita> >> %d: Distruzione della coda;\n", ++i);
	printf(">> <Priorita> >> %d: Aiuto;\n", ++i);
	printf(">> <Priorita> >> %d: Uscita;\n", ++i);
	return;
}		/* -----  end of function usage_priorità  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pila
 *  Description:  "Main" di priorita.c
 * =====================================================================================
 */
void priorita (){
	int cmd=0, continua=1;	
	usage_priorita();
	while (continua){
		printf(">> <Priorita> >> ");
		scanf("%d", &cmd);

		if ( cmd == 1 ){
			printf ("Card\n");
		}else if ( cmd == 2 ){
			printf ("inserimento in base alla media\n");
		}else if ( cmd == 3 ){
			printf ("estrai card maggiore\n");
		}else if ( cmd == 4 ){
			printf ("stampa coda a priorità\n");
		}else if ( cmd == 5 ){
			printf ("distruggi coda\n");
		}else if ( cmd == 6 ){
			usage_priorita();
		}else if ( cmd == 7 ){
			printf("esci\n");
			continua=0;
		}
	}

	return;
}		/* -----  end of function priorità  ----- */
