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
	scanf("%d", &cmd);
	while ( continua ){
		if ( cmd == 1 ){
			// Lista non ordinata
			lista();
		} else if ( cmd == 2 ){
			// Pila
		} else if ( cmd == 3 ){
			// coda
		} else if ( cmd == 4 ){
			// coda a priorità
		} else if ( cmd == 5 )
			continua=0;
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
	printf(">> Applicazione per la gestione di una lista:\n");
	printf(">> Digita 1 per la gestione a \"Lista non ordinata\";\n");
	printf(">> Digita 2 per la gestione a \"Pila\";\n");
	printf(">> Digita 3 per la gestione a \"Coda\";\n");
	printf(">> Digita 4 per la gestione a \"Coda di priorita\";\n");
	printf(">> Digita 5 per uscire:\n");
	printf(">> ");
	return;
}		/* -----  end of function usage  ----- */
