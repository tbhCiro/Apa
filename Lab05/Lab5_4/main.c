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

void usage ();
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char **argv ){
	int continua=1;
	char *comando=malloc(sizeof(char));
	
	system("clear");
	usage();
	while ( continua ) {
		printf (">> ");
		scanf ("%s", comando);
		if (strlen(comando)!=1) {
			usage();		// il comando non può essere più lungo di una lettera!
			continue;	// quindi se lo è salta all'iterazione successiva dopo aver lanciato usage();.
		}
		comando[0]=toupper(comando[0]);
		if ( comando[0] == 'A'  ){
			printf("Aggiungo in coda\n");
		}else	if ( comando[0] == 'S'  ){
			printf("Stampo il primo della lista\n");
		}else	if ( comando[0] == 'T'  ){
			printf("Stampo tutti\n");
		}else	if ( comando[0] == 'E'  ){
			printf("Esco\n");
			return EXIT_SUCCESS;
		}else{
			usage();
		}
	}// while ( continua )
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage
 *  Description:  
 * =====================================================================================
 */
void usage (){
	printf("<<< [A]ggiungi in coda, [S]tampa il primo, s[T]ampa tutti, [E]sci >>>\n");
}		/* -----  end of function usage  ----- */
