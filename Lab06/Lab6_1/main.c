/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  lab 6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 04:23:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Umberto Reale
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "pila.h"
#include "coda.h"
#include "priorita.h"
#include "comune.h"

/*-----------------------------------------------------------------------------
 *  Prototipi
 *-----------------------------------------------------------------------------*/
void menu ();
void usage ();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (){
	system("clear");
	menu();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu
 *  Description:  
 * =====================================================================================
 */
void menu ( ){
	int continua=1, cmd=0;
	usage();
	while ( continua ){
	printf(">> ");
	scanf("%d", &cmd);
	if ( cmd == 1 ){
			// Lista non ordinata
			lista();
			usage();
		} else if ( cmd == 2 ){
			// Pila
			pila();
			usage();
		} else if ( cmd == 3 ){
			// coda
			coda();
			usage();
		} else if ( cmd == 4 ){
			// coda a priorità
			priorita();
			usage();
		} else if ( cmd == 5 ){
			usage();
		} else if ( cmd == 6 )
			continua=0;
		cmd=0;
	}
	return;
}		/* -----  end of function menu  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage
 *  Description:  Funziona che semplicemente stampa la `sintassi` di questa funzione
 * =====================================================================================
 */
void usage (){
	int i=0;
//	printf(">> Applicazione per la gestione di una lista:\n");
	printf(">> %d: Gestione a \"Lista non ordinata\";\n", ++i);
	printf(">> %d: Gestione a \"Pila\";\n", ++i);	
	printf(">> %d: Gestione a \"Coda\";\n", ++i);
	printf(">> %d: Gestione a \"Coda di priorita\";\n", ++i);
	printf(">> %d: Aiuto;\n", ++i);
	printf(">> %d: Uscita:\n", ++i);
	return;
}		/* -----  end of function usage  ----- */
