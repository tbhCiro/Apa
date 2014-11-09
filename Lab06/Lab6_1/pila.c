/*
 * =====================================================================================
 *
 *       Filename:  pila.c
 *
 *    Description:  source for pila.h lab6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 07:06:09 PM
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
#include"pila.h"
//#include"comune.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage_pila
 *  Description:  stampa la "sintassi" utile al file pila.c
 * =====================================================================================
 */
void usage_pila (){
	int i=0;
	printf(">> <Pila> >> %d: Cardinalità della pila;\n", ++i);
	printf(">> <Pila> >> %d: Inserimento all'inizio;\n", ++i);
	printf(">> <Pila> >> %d: Estrazione;\n", ++i);
	printf(">> <Pila> >> %d: Stampa intera pila;\n", ++i);
	printf(">> <Pila> >> %d: Distruzione della pila;\n", ++i);
	printf(">> <Pila> >> %d: Aiuto;\n", ++i);
	printf(">> <Pila> >> %d: Uscita;\n", ++i);
	return;
}		/* -----  end of function usage_pila  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pila
 *  Description:  "Main" di pila.c
 * =====================================================================================
 */
void pila (){
	int cmd=0, continua=1;	
	usage_pila();
	while (continua){
		printf(">> <Pila> >> ");
		scanf("%d", &cmd);

		if ( cmd == 1 ){
			printf ("Card\n");
		}else if ( cmd == 2 ){
			printf ("ins all'inizio\n");
		}else if ( cmd == 3 ){
			printf ("estrai\n");
		}else if ( cmd == 4 ){
			printf ("stampa pila\n");
		}else if ( cmd == 5 ){
			printf ("distruggi pila\n");
		}else if ( cmd == 6 ){
			usage_pila();
		}else if ( cmd == 7 ){
			printf("esci\n");
			continua=0;
		}
	}
	return;
}		/* -----  end of function pila  ----- */
