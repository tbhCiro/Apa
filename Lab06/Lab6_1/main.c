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

#define MAX 35
/*-----------------------------------------------------------------------------
 *  Struttura dati
 *-----------------------------------------------------------------------------*/
typedef struct studente *link;

typedef struct {	// sotto struttura carriera
	int crediti;
	float media;
}carriera;

struct {				// nodo della lista
	char nome[MAX];
	char cognome[MAX];
	char matricola[MAX];
	carriera voti;
	link prossimo;
}studente;

link head=NULL;	// testa della lista;

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
		} else if ( cmd == 4 ){
			// coda a priorità
		} else if ( cmd == 5 )
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
