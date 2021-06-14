/*****************************************************/
//  PAR   : h saulnier  f henri					     
/*****************************************************/

/* 
 Ce module offre  les  actions les plus standard sur les bits 
 d'une valeur de type unsigned int
 */

/*  
 les int type de base sur nos petites machines ont une repr�sentation
 �E4 bytes(32 bits) au d�but du vingt et uni�me si�cle 
 */

/* 
 L'ordre des bits dans un entier selon la tradition 
 commence �E0 , ordre du bit le moins significatif  
 jusqu'au nombre total de bits -1
 Avec 32 bits, l'ordre peut varier de 0 �E31  inclusivement

 le parametre ordre dans les fonctions offertes plus bas
 est partout positif de type unsigned int
 */

/*
 Le module offre  : 


 obtenir la valeur d'un bit (0 , 1) avec la fonction  get_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant un bit �E1 dans un entier avec 
 la fonction  set_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant un bit �E0 dans un entier avec 
 la fonction  clear_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant l'inversion d'un bit dans un 
 entier avec  la fonction  flip_bit(nombre, ordre)

 donner acc�s �Eune repr�sentation des bits dans une chaine de caract�res bits2string(nombre)

 */

/**********************************************************/

#ifndef  __MODULE_OP_BITS__
#define  __MODULE_OP_BITS__

/**********************************************************/

#define _CRT_SECURE_NO_WARNINGS  

#include<stdlib.h>

/**********************************************************/

/*****************************************************/
/*		CONSTANTE					*/
/*****************************************************/

/*  Le symbole pour le nombre de bits dans notre entier 
 sur la plateforme de travail.
 */
#define NB_BITS	 (sizeof(unsigned int) * 8)
#define INT_BIT 32



/* l'intervalle d'ordre acceptable ira de 0 �E NB_BITS-1 */

/*****************************************************/

/*****************************************************/
/*****************************************************/

/******************* GET_BIT **********************/
/* 
 donne la valeur du  bit d'ordre sp�cifi�E		
 PARAMETRES : nombre , un entier non sign�E					
 ordre , sp�cifie le bit voulu dans nombre. 
 RETOUR : 0 ou 1 	

 SPECIFICATIONS :							
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne 0	
 */

int get_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/*********************** SET_BIT **************************/
/* 
 donne la valeur du nombre avec le bit d'ordre sp�cifi�Emis �E1 
 PARAMETRES : nombre , un entier quelconque					
 ordre , sp�cifie le bit mis �E1 dans nombre. 
 RETOUR : la valeur obtenue du param�tre avec ce bit �E1		

 SPECIFICATIONS :								
 Si ordre n'est pas dans l'intervalle correct
 la	fonction retourne la valeur re�ue	
 */

unsigned int set_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/****************** CLEAR_BIT **************************/
/* 
 donne la valeur du nombre  avec le bit d'ordre sp�cifi�Emis �E0 
 PARAMETRES : nombre , un entier quelconque						
 ordre , sp�cifie le bit mis �E0 dans nombre
 RETOUR : la valeur obtenue du param�tre avec ce bit �E0	

 SPECIFICATIONS :								
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne la valeur re�ue
 */

unsigned int clear_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/******************** FLIP_BIT *************************/
/* 
 donne la valeur du nombre re�u  avec le bit invers�E
 d'ordre sp�cifi�E
 Entr�e : nombre : un entier positif					
 ordre : sp�cifie le bit  �Einverser dans nombre. 
 RETOUR : la valeur obtenue du param�tre avec ce bit invers�E				
 SPECIFICATIONS :							
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne la valeur re�ue
 */

unsigned int flip_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/***************** BITS2STRING ****************************/
/* 
 donne une repr�sentation string ( chaine de caract�re constante) aux
 bits du nombre re�u.        
 PARAMETRE : nombre , un entier non sign�E	
 RETOUR : une chaine constante								
 SPECIFICATIONS :								
 Les bits sont donn�s dans la string du moins significatif au plus 
 significatif, peu importe le signe du param�tre effectif
 */

const char * bits2string(unsigned int nombre);


/**********************************************************/




/*!  @brief                    Affiche un tableau 1 dimention en 2 dimention
*                              avec un nombre de colonnes specifi�E

     @param   unsigned int *   Tableau a afficher      
     @param   unsigned int     Taille du tableau en octets
     @param   unsigned int     Nombre de bits a afficher en colonnes

     @return                   Code d'erreur
     @retval  EXIT_SUCCESS     Aucune erreur
     @retval  EXIT_FAILURE     Erreur lors de l'affichage

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              7 juin 2021
     @author                            Benoit Houle
     @note                              Entr�e originale du code.

     <hr width="100%" height="5">
*/
int voirbloc(unsigned int uTableauAfficher[],
    unsigned int uTaille, 
    unsigned int uNbBitsAfficher);



//c'est fini
#endif
/**********************************************************/

