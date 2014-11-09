/*
 * =====================================================================================
 *
 *       Filename:  coda.c
 *
 *    Description:  source code for coda.h lab6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 07:41:42 PM
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
#include"coda.h"
//#include"comune.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage_coda
 *  Description:  
 * =====================================================================================
 */
void usage_coda (){
	int i;
	printf(">> <Coda> >> %d: Cardinalità della coda;\n", ++i);
	printf(">> <Coda> >> %d: Inserimento alla fine;\n", ++i);
	printf(">> <Coda> >> %d: Estrazione elemento di testa;\n", ++i);
	printf(">> <Coda> >> %d: Stampa intera coda;\n", ++i);
	printf(">> <Coda> >> %d: Distruzione della coda;\n", ++i);
	printf(">> <Coda> >> %d: Aiuto;\n", ++i);
	printf(">> <Coda> >> %d: Uscita;\n", ++i);	
	return;
}		/* -----  end of function usage_coda  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  coda
 *  Description:  in "main" di coda.c
 * =====================================================================================
 */
void coda (){
	int cmd=0, continua=1;	
	usage_coda();
	while (continua){
		printf(">> <Coda> >> ");
		scanf("%d", &cmd);

		if ( cmd == 1 ){
			printf ("Card\n");
		}else if ( cmd == 2 ){
			printf ("ins alla fine\n");
		}else if ( cmd == 3 ){
			printf ("estrai dalla testa\n");
		}else if ( cmd == 4 ){
			printf ("stampa coda\n");
		}else if ( cmd == 5 ){
			printf ("distruggi coda\n");
		}else if ( cmd == 6 ){
			usage_coda();
		}else if ( cmd == 7 ){
			printf("esci\n");
			continua=0;
		}
	}
	return;
}		/* -----  end of function coda  ----- */
