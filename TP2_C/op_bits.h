/*****************************************************/
//  PAR   : h saulnier  f henri					     
/*****************************************************/

/* 
 Ce module offre  les  actions les plus standard sur les bits 
 d'une valeur de type unsigned int
 */

/*  
 les int type de base sur nos petites machines ont une reprÈsentation
 ÅE4 bytes(32 bits) au dÈbut du vingt et uniËme siËcle 
 */

/* 
 L'ordre des bits dans un entier selon la tradition 
 commence ÅE0 , ordre du bit le moins significatif  
 jusqu'au nombre total de bits -1
 Avec 32 bits, l'ordre peut varier de 0 ÅE31  inclusivement

 le parametre ordre dans les fonctions offertes plus bas
 est partout positif de type unsigned int
 */

/*
 Le module offre  : 


 obtenir la valeur d'un bit (0 , 1) avec la fonction  get_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant un bit ÅE1 dans un entier avec 
 la fonction  set_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant un bit ÅE0 dans un entier avec 
 la fonction  clear_bit(nombre, ordre)

 obtenir la valeur obtenue en forcant l'inversion d'un bit dans un 
 entier avec  la fonction  flip_bit(nombre, ordre)

 donner accËs ÅEune reprÈsentation des bits dans une chaine de caractËres bits2string(nombre)

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



/* l'intervalle d'ordre acceptable ira de 0 ÅE NB_BITS-1 */

/*****************************************************/

/*****************************************************/
/*****************************************************/

/******************* GET_BIT **********************/
/* 
 donne la valeur du  bit d'ordre spÈcifiÅE		
 PARAMETRES : nombre , un entier non signÅE					
 ordre , spÈcifie le bit voulu dans nombre. 
 RETOUR : 0 ou 1 	

 SPECIFICATIONS :							
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne 0	
 */

int get_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/*********************** SET_BIT **************************/
/* 
 donne la valeur du nombre avec le bit d'ordre spÈcifiÅEmis ÅE1 
 PARAMETRES : nombre , un entier quelconque					
 ordre , spÈcifie le bit mis ÅE1 dans nombre. 
 RETOUR : la valeur obtenue du paramËtre avec ce bit ÅE1		

 SPECIFICATIONS :								
 Si ordre n'est pas dans l'intervalle correct
 la	fonction retourne la valeur reÁue	
 */

unsigned int set_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/****************** CLEAR_BIT **************************/
/* 
 donne la valeur du nombre  avec le bit d'ordre spÈcifiÅEmis ÅE0 
 PARAMETRES : nombre , un entier quelconque						
 ordre , spÈcifie le bit mis ÅE0 dans nombre
 RETOUR : la valeur obtenue du paramËtre avec ce bit ÅE0	

 SPECIFICATIONS :								
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne la valeur reÁue
 */

unsigned int clear_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/******************** FLIP_BIT *************************/
/* 
 donne la valeur du nombre reÁu  avec le bit inversÅE
 d'ordre spÈcifiÅE
 EntrÈe : nombre : un entier positif					
 ordre : spÈcifie le bit  ÅEinverser dans nombre. 
 RETOUR : la valeur obtenue du paramËtre avec ce bit inversÅE				
 SPECIFICATIONS :							
 Si ordre n'est pas dans l'intervalle correct 
 la fonction retourne la valeur reÁue
 */

unsigned int flip_bit(unsigned int nombre, unsigned int ordre);
/**********************************************************/

/***************** BITS2STRING ****************************/
/* 
 donne une reprÈsentation string ( chaine de caractËre constante) aux
 bits du nombre reÁu.        
 PARAMETRE : nombre , un entier non signÅE	
 RETOUR : une chaine constante								
 SPECIFICATIONS :								
 Les bits sont donnÈs dans la string du moins significatif au plus 
 significatif, peu importe le signe du paramËtre effectif
 */

const char * bits2string(unsigned int nombre);


/**********************************************************/




/*!  @brief                    Affiche un tableau 1 dimention en 2 dimention
*                              avec un nombre de colonnes specifiÅE

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
     @note                              EntrÈe originale du code.

     <hr width="100%" height="5">
*/
int voirbloc(unsigned int uTableauAfficher[],
    unsigned int uTaille, 
    unsigned int uNbBitsAfficher);



//c'est fini
#endif
/**********************************************************/

