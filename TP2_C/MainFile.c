/*!  @file                              MainFile.cpp
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

#include "op_bits.h"
#include "mtwister.h"
#include "t_arrangement.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEGUB
#pragma warning(disable:4996)       //Disable les erreurs de scanf -> scanf_s


int test_voirbloc();

 
int main(int argc, char** argv)
{

	test_voirbloc();

	return EXIT_SUCCESS;
}

 

int test_voirbloc()
{
	unsigned int TEST_Taille =5;
	unsigned int TEST_Tableau[5] = {
	0xFFFFFFFF,
	1,
	2,
	4,
	8/*,
	16,
	32,
	64,
	128,
	256	*/
	};	

	unsigned int TEST_NbBitsAfficher = 8;

	t_permut_bits tablo;

	tablo.n1 = 0;
	tablo.n2 = 6;
	tablo.taille_bloc = 8;

	voirbloc(TEST_Tableau, TEST_Taille, TEST_NbBitsAfficher);

	permute2Blocs(TEST_Tableau, 5, &tablo);

	voirbloc(TEST_Tableau, TEST_Taille, TEST_NbBitsAfficher);


	system("pause");

	return EXIT_SUCCESS;
}

 