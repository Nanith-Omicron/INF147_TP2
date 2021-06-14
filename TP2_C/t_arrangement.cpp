/*!  @file                              t_arrangement.cpp
	 @version                           1.00
	 @brief                             Implémentation de...

	 @internal

	 projet                             TP2 Encryption

	 @note                              Note au programmeur.

	 <hr width="100%" height="5">
	 <b>Historique</b>
	 <hr width="100%" height="1">
	 @date                              7 juin 2021
	 @author                            Benoit Houle
	 @note                              Entrée originale du code.

	 <hr width="100%" height="5">
*/
//** **************************************************************************

#include "t_arrangement.h"
#include <stdio.h>



//void permute2Bits( void * vTableau, unsigned int position, int decalage);


/*!  @brief                             Implémentation de la procedure pour 
										permuter 2 bits dans un tableau 
										d'entier.

	 @param   void*					    Tableau a afficher      
     @param   unsigned int				Position du premier bit a 
										échanger de place
     @param   unsigned int				Décalage enter le premier et 2e bit
										a échanger de place.

	 @return							Aucun retour

	 @note                              Test unitaire a faire.

	 <hr width="100%" height="5">
	 <b>Historique</b>
	 <hr width="100%" height="1">
	 @date                              7 juin 2021
	 @author                            Benoit Houle
	 @note                              Initialisation de variable.

	 @date                              12 juin 2021
	 @author                            Benoit Houle
	 @note                              Completion du code.

	 <hr width="100%" height="5">
*/
//** **************************************************************************
void permute2Bits(void* vTableau, unsigned int position, unsigned int decalage)
{

	unsigned int* Tableau = (unsigned int*)vTableau;

	unsigned int numCase1 = position / INT_BIT;
	unsigned int numCase2 = (position + decalage) / INT_BIT;

	unsigned int posBit1Case = position - (numCase1 * INT_BIT);
	unsigned int posBit2Case = decalage - (numCase2 * INT_BIT) + posBit1Case;

	printf("index1: [%2.2d]:(%2.2d) \n", numCase1, posBit1Case);
	printf("index2: [%2.2d]:(%2.2d)  \n", numCase2, posBit2Case);

	int bit2 = get_bit(Tableau[numCase1], posBit1Case);
	int bit1 = get_bit(Tableau[numCase2], posBit2Case);

	printf("bit1: %d -> %d \n", get_bit(Tableau[numCase1], posBit1Case), bit1);
	printf("bit2: %d -> %d \n", get_bit(Tableau[numCase2], posBit2Case), bit2);

	Tableau[numCase1] = (bit1) ?
		set_bit(Tableau[numCase1], posBit1Case) :
		clear_bit(Tableau[numCase1], posBit1Case);

	Tableau[numCase2] = (bit2) ?
		set_bit(Tableau[numCase2], posBit2Case) :
		clear_bit(Tableau[numCase2], posBit2Case);
	
}
