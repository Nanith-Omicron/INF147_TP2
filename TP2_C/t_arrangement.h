#include "t_permutation.h"

/*
Un arrangement

Math�matiquement, tout arrangement peut �tre
consid�r�e comme une liste ordonn�e de
permutations et l�arrangement inverse consiste
alors en la liste invers�e des m�mes permutations.

L�impl�mentation d�un arrangement
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
*3 prototype � d�finir :
*
*        - Initialiser un t_arrage_bits (cr�ation du tableau de t_permut_bits".
*        - Crypter un tableau void*.
*        - D�crypter un tableau void* pr�alablement crypt� par la m�thode pr�vue.
*
* Tous les autres sous-programmes sont priv�s (dans le .cpp)
*/