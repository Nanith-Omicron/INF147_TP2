/*****************************************************/
/*  PAR   : Hugues Saulniers  Fr�d�rick Henri*/
/*****************************************************/

/*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Impl�mentation des fonctions offertes dans op_bits.h*/
/* toutes sont simples et bas�es sur les "bitwise operators" du C */

#include "op_bits.h"

/*********************************************************/


/*****************************************************/
/*		DEFINITIONS DES FONCTIONS				*/
/*****************************************************/



/*****************************************************/
int get_bit(unsigned int nombre, unsigned int ordre) {
	// STRATEGIE
	// tester  ordre valide 
	// si oui, un bitwise and avec un train de bit n'ayant qu'un 1
	// judicieusement plac� au bon ordre
	// sinon retour de 0

	return (ordre < NB_BITS) ? ((nombre & (1 << ordre)) != 0) : 0;
}

/*****************************************************/
unsigned int set_bit(unsigned int nombre, unsigned int ordre) {
	// STRATEGIE
	// tester ordre valide
	// SI OUI un bitwise or avec un train de bit n'ayant qu'un 1
	// judicieusement plac� au bon ordre
	// sinon retour de la valeur recue 
	return  (ordre < NB_BITS) ? (nombre | (1 << ordre)) : nombre;

}

/*****************************************************/
unsigned int clear_bit(unsigned int nombre, unsigned int ordre){
	// STRATEGIE
	// tester ordre valide
	// SI OUI un bitwise and avec le complement d un train de bits 
	//  qui  a  un un seul  0 judicieusement plac� au bon ordre
	// sinon retour de la valeur recue 

	return  (ordre < NB_BITS) ? (nombre & ~(1 << ordre)) : nombre;
}

/*****************************************************/
unsigned int flip_bit(unsigned int nombre, unsigned int ordre){
	// STRATEGIE
	// tester ordre valide
	// SI OUI si le bit ordre est � 1, on le clear sinon on le set	
	// sinon retour de la valeur recue 

	// Remarquez le double usage de l'operateur conditionnel

	return  (ordre < NB_BITS)
			? (get_bit(nombre, ordre))
					? (clear_bit(nombre, ordre))
							: set_bit(nombre, ordre)
			: nombre;
}

/*****************************************************/
const char * bits2string(unsigned int nombre) {

	/* 200 c'est plus que suffisant
	   c est une locale dont la position est permanente*/
	static char buffer[200];

	int i;

	buffer[NB_BITS] = '\0';

	/* boucle d'assignation de chaque bit obtenu
	// de get_bit dans la string ( mais en ordre inverse )*/
	for (i = 0; i< NB_BITS; i += 1) {
		buffer[NB_BITS - 1 - i] = get_bit(nombre, i) ? '1' : '0';
	}

	return buffer;
}
/*****************************************************/




/*****************************************************/
int voirbloc(unsigned int uTableauAfficher[], unsigned int uTaille, unsigned int uNbBitsAfficher)
{
	int iCodeErreur = EXIT_SUCCESS;

	/*!Le numero du bit a afficher dans l'entier*/
	unsigned int uBit_A_Afficher = 0;

	/*!Le numeros de la case actuellement traitee dans le tableau*/
	unsigned int uCaseTraite = 0;

	/*!Compteur pour les bits deja afficher sur une ligne (un bloc)*/
	unsigned int uBitsAfficher = 0;

	/*!Numeros de la ligne a afficher*/
	unsigned int uOctetsAffiche = 1;
		


		printf("0  : ");

		while (uCaseTraite < uTaille)
		{

			printf("%i", get_bit(uTableauAfficher[uCaseTraite], (NB_BITS - 1 - uBit_A_Afficher)));
			//printf("%i", get_bit(uTableauAfficher[uCaseTraite], (uBit_A_Afficher)));

			uBitsAfficher++;
			uBit_A_Afficher++;

			if (uBitsAfficher == uNbBitsAfficher) {

				printf("\n%-2.1u : ", uOctetsAffiche++);
				uBitsAfficher = 0;
			}

			if (uBit_A_Afficher == INT_BIT) {
				uBit_A_Afficher = 0;
				uCaseTraite++;
			}

		}
		printf("\n----------------------------------------------\n\n");

	

	return iCodeErreur;
}
/*****************************************************/