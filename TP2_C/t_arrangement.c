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

void permute2Bits( void * vTableau, unsigned int position, int decalage);
int permute2Blocs(void* vTableau, int iTaille, t_permut_bits *t_Info_Permutation);


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

	int bit2 = get_bit(Tableau[numCase1], posBit1Case);
	int bit1 = get_bit(Tableau[numCase2], posBit2Case);

	//printf("index1: [%2.2d]:(%2.2d) \n", numCase1, posBit1Case);
	//printf("index2: [%2.2d]:(%2.2d)  \n", numCase2, posBit2Case);
	//printf("bit1: %d -> %d \n", get_bit(Tableau[numCase1], posBit1Case), bit1);
	//printf("bit2: %d -> %d \n", get_bit(Tableau[numCase2], posBit2Case), bit2);

	Tableau[numCase1] = (bit1) ?
		set_bit(Tableau[numCase1], posBit1Case) :
		clear_bit(Tableau[numCase1], posBit1Case);

	Tableau[numCase2] = (bit2) ?
		set_bit(Tableau[numCase2], posBit2Case) :
		clear_bit(Tableau[numCase2], posBit2Case);
	
}

/*!  @brief                             Implémentation de la procedure pour
										permuter 2 blocs de bits

	 @param   void*					    Tableau	contenant les blocs
	 @param   int						La taille du tableau en octets
	 @param   t_permut_bits				Information des blocs
										a intervertir

	 @return							Code d'erreur
	 @retval  EXIT_SUCCESS				Aucune erreur
	 @retval  EXIT_FAILURE				Erreur lors de l'affichage

	 @note                              Test unitaire a faire.

	 <hr width="100%" height="5">
	 <b>Historique</b>
	 <hr width="100%" height="1">

	 @date                              12 juin 2021
	 @author                            Benoit Houle
     @note                              Entrée originale du code.

	 @date                              13 juin 2021
	 @author                            Benoit Houle
	 @note                              Completion du code.

	 <hr width="100%" height="5">
*/
 void permute2Bits(void* vTableau, unsigned int position, int decalage)
{
	 //Creer un nouveau T_permut_bits
	 t_permut_bits temp;
	 temp.n1 = position;
	 temp.n2 = position + decalage;



 }
	 //** **************************************************************************
int permute2Blocs(void* vTableau, int iTaille, t_permut_bits *t_Info_Permutation)
{

	int iCodeErreur = EXIT_SUCCESS;
	int iTemporaire, i;

	int posBit1 = t_Info_Permutation->n1 * t_Info_Permutation->taille_bloc;
	int posBit2 = t_Info_Permutation->n2 * t_Info_Permutation->taille_bloc;

	int iDecalage = posBit2 - posBit1;

	if ((posBit2 + t_Info_Permutation->taille_bloc) > (iTaille  * INT_BIT))
	{
		iCodeErreur = EXIT_FAILURE;
		printf("EXIT_FAILURE\n");
	}
	else 
	{
		if (t_Info_Permutation->n1 > t_Info_Permutation->n2)
		{
			iTemporaire = t_Info_Permutation->n1;
			t_Info_Permutation->n1 = t_Info_Permutation->n2;
			t_Info_Permutation->n2 = iTemporaire;
		}

		for ( i = posBit1; i < t_Info_Permutation->taille_bloc; i++)
		{
			permute2Bits(vTableau, i, iDecalage);
		}
	}

	return iCodeErreur;
}


t_arrange_bits initialiser_Instruction(
	int iNombrePermutation,
	int iTailleOctets,
	int iBornMin,
	int iBornMax,
	unsigned long Clef // A quoi ca  sert??
)
{
	t_arrange_bits nomTemp;

	int i;
		
	nomTemp.nb_permuts = iNombrePermutation;

	for (i = 0; i < iNombrePermutation; i++)
	{
		/*??taille octect - taille bloc pour la born max??*/
		nomTemp.tablo[i].taille_bloc = (int)mt_randf((double)iBornMin, (double)iBornMax);

		nomTemp.tablo[i].n1 = mt_randi(iTailleOctets * 8 / nomTemp.tablo[i].taille_bloc) - 1;
		nomTemp.tablo[i].n2 = mt_randi(iTailleOctets * 8 / nomTemp.tablo[i].taille_bloc) - 1;

		printf("i          : [%d]\n", i);
		printf("taille_bloc: [%d]\n", nomTemp.tablo[i].taille_bloc);
		printf("taille max : [%d]\n", (iTailleOctets * 8 / nomTemp.tablo[i].taille_bloc));
		printf("n1           [%d]\n", nomTemp.tablo[i].n1);
		printf("n2           [%d]\n\n", nomTemp.tablo[i].n2);

	}
	

	return nomTemp;
}