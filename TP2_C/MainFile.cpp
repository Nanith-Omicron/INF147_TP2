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
#include "t_permutation.h"
#include "t_arrangement.h"

#include <stdio.h>
#include <stdlib.h>


#pragma warning(disable:4996)       //Disable les erreurs de scanf -> scanf_s

// TODO PUT THERE IN 
#define MAX_BITS 11
#define GetBit(input,n)((input) >> (n) & 1)
#define setBit(input,n)((input) |= 1 << (n))
#define unsetBit(input,n)((input) &= ~(1 << (n)))

int test_voirbloc();

int main(int argc, char** argv)
{

	test_voirbloc();

	return EXIT_SUCCESS;
}


//TODO BAD
void invertBlock(int a ,int b,unsigned int* tab, int max)
{
	unsigned int  temp = tab[a];
	tab[a] = b;
	tab[b] = temp;


}
void showBits(unsigned int* tab, int max)
{
	/*int pos; int l;
	while ()
	{
		if (GetBit(pos, &tab[pos]))
			pos++;
	}
		
	 
	*/

}

int test_voirbloc()
{


	unsigned int TEST_Tableau[4] = {
	1,
	7,
	256,
	16,
	/*220,
	2220,
	350,
	3476,
	35678,
	468393*/
	};


	unsigned int TEST_Taille = 4;


	unsigned int TEST_NbBitsAfficher = 11;


	voirbloc(TEST_Tableau, TEST_Taille, TEST_NbBitsAfficher);




	system("pause");

	return EXIT_SUCCESS;
}