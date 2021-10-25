#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
#include "coureur.h"

int main()
{
	struct Classement_Tour_de_France* Tournament1;
	struct coureur* coureur1 = Creer_Coureur("PHAN", "Nhat Tien", 60, "LANGAGE C");
	//Tournament1->coureur_1er = coureur1;
	Ajouter_temps(coureur1, 3600);
	afficher_Coureur(coureur1);
	free(coureur1);
	return 0;
}
