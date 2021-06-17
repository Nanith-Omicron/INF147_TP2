#ifndef __T_ARRANGEMENT__
#define __T_ARRANGEMENT__

#include "t_permutation.h"

/*
Un arrangement

Mathématiquement, tout arrangement peut être
considérée comme une liste ordonnée de
permutations et l’arrangement inverse consiste
alors en la liste inversée des mêmes permutations.

L’implémentation d’un arrangement
(une collection de t_permut_bits) se fera avec
le type
*/
#define MAX_ARR 100
#define INT_BIT 32

typedef struct{
   t_permut_bits tablo [MAX_ARR]; //tableau de permutations
   int nb_permuts;
 }t_arrange_bits;


/*
*3 prototype Edéfinir :
*
*        - Initialiser un t_arrage_bits (création du tableau de t_permut_bits".
*        - Crypter un tableau void*.
*        - Décrypter un tableau void* préalablement cryptEpar la méthode prévue.
*
* Tous les autres sous-programmes sont privés (dans le .c)
*/



void permute2Bits(void* vTableau, unsigned int position, unsigned int decalage);
int permute2Blocs(void* vTableau, int iTaille, t_permut_bits* t_Info_Permutation);
void initialiser_Tableau();

#endif __T_ARRANGEMENT__