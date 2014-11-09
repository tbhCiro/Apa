/*
 * =====================================================================================
 *
 *       Filename:  comune.h
 *
 *    Description:  libreria comune tra tutti i file del progetto lab6
 *
 *        Version:  1.0
 *        Created:  11/09/2014 08:19:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Umberto Reale (), 
 *   Organization:  
 *
 * =====================================================================================
 */

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


