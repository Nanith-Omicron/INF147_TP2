/*
COURS INF147
TP	  #2
REMIS A PIERRE BELISLE

Fonctions.cpp
Programme du module externe, contenant les sous-fonctions du projet

PARTICIPANTS:
- BENOIT HOULE
- ERIC MALOUIN
-
-

Ecole de Technologie Superieure (ETS) © 2021
Ete 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <constantes.h>

#include "mtwister.h"
#include "t_arrangement.h"
#include "t_permutation.h"

/*
fonction qui sollicite l'utilisateur pour la clee
*/
unsigned int solicitationClee()
{
	unsigned int clee;// valeur a retourner
	
	do
	{
		printf("Entrez la clee!!!:\n");
		scanf("%u", &clee);
	}
	while (clee > 0 && clee < MAX_UINT)

	return clee;
}

