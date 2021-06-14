#ifndef __T_PERMUTATION__
#define __T_PERMUTATION__

#include "op_bits.h"

//Représenté par la taille des deux blocs de bits à permuter 
//et un couple de deux entiers (n1, n2) donnant la position des deux blocs.
typedef struct{
     int n1; // position du premier bloc
     int n2; // position du second bloc, n1≠n2
     int taille_bloc; // taille du bloc de bits 
}t_permut_bits; 

#endif