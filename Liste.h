#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "coureur.h"
#include <stdbool.h>

//-------------------------- Structure une liste de coureur -----------------------------//
	struct Liste_coureur
	{
		struct cellule_coureur* coureur_1er;
		struct cellule_coureur* coureur_fin;
	};

		struct cellule_coureur
		{
			struct coureur infor;
			struct cellule_coureur* coureur_après;
		};
//----------------------------------------------------------------------------------------//

// ---------------------------structure une classement equipe ---------------------------//

	struct equipe 
	{
		char nom[50];
		int nombre_coureur_arrivé;
		int nombre_meilleur_coeur;
		int temps_cumulé;
	};

		struct cellule_equipe
		{
			struct equipe equipe;
			struct cellule_equipe* equipe_suivant;
		};

			struct classe_equipe
			{
				struct cellule_equipe* equipe_1er;
				struct cellule_equipe* equipe_fin;
			};

//------------------------------------------------------------------------------------//

// ------------------fonction pour initialiser un cellule coureur-------------------------//

	struct cellule_coureur* initialiser_cellule_coureur()
	{
		struct cellule_coureur* cellule_coureur = malloc(sizeof(struct cellule_coureur));
		return cellule_coureur;
	}

//----------------------------------------------------------------------------------------//

//--------------------Fonction ajouter un coureur en fin de liste--------------------- //

	void ajouter_coureur_en_fin(struct Liste_coureur * liste, struct coureur coureur)
	{
	
		struct cellule_coureur * coureur_entrer = malloc(sizeof(struct cellule_coureur));
		coureur_entrer->infor = coureur;

		if (liste->coureur_1er == NULL)
			{
			liste->coureur_fin = coureur_entrer;
			liste->coureur_fin->coureur_après = NULL;
			liste->coureur_1er = liste->coureur_fin;
			}
		else
			{
				liste->coureur_fin->coureur_après = coureur_entrer ;
				coureur_entrer->coureur_après = NULL;
				liste->coureur_fin = coureur_entrer ;
			}	
	}

//---------------------------------------------------------------------------------------//

//--------------------------- Fonctions de parcourir la liste ---------------------------//

	struct cellule_coureur* aller_début(struct Liste_coureur* liste)
	{
		if (liste->coureur_1er == NULL)
		{
			printf("liste des coureur est Vide !");
			return 0;
		}
		else return liste->coureur_1er;
	}

	struct cellule_coureur* avancer(struct cellule_coureur* courant)
	{
		return courant->coureur_après;
	}

	int courant_en_Fin(struct cellule_coureur* courant)
	{
		if (courant == NULL)
			return 1;
		else
			return 0;
	}
//---------------------------------------------------------------------------------------//

// ------------ fonction de retourner le coureur qui est pointé ------------- //

	struct coureur coureur_pointé(struct cellule_coureur * courant)
	{
		return courant->infor;
	}

//----------------------------------------------------------------------------//

// --------------------------- Fonction d'effacer un coureur dans la liste ---------------------------//

	void effacer_coureur_pointée(struct Liste_coureur* liste, struct cellule_coureur* courant)
	{
		if (liste->coureur_1er == NULL)
		{
			printf("liste des coureur est Vide !");
			return ;
		}

		if (courant == liste->coureur_1er)
		{
			liste->coureur_1er = liste->coureur_1er->coureur_après;
			courant = aller_début(liste);
		}

		else
		{
			struct cellule_coureur* temp = aller_début(liste);
			while (temp->coureur_après != courant)
			{
				temp = avancer(temp);
			}

			temp->coureur_après = courant->coureur_après;
			courant = temp->coureur_après;
		}
	}
//--------------------------------------------------------------------------------------------//

//---- classer les coureur en maniere du temps cumulée -------- //

	struct Liste_coureur * trier_liste(struct Liste_coureur * liste)
	{
		struct cellule_coureur* courant1 = initialiser_cellule_coureur();
		for (courant1 = aller_début(liste);!courant_en_Fin(courant1);courant1 = courant1->coureur_après)
		{
			struct cellule_coureur* courant2;
			for (courant2 = avancer(courant1); !courant_en_Fin(courant2);courant2 = courant2->coureur_après)
			{
					if (courant1->infor.temps > courant2->infor.temps)
					{
						struct cellule_coureur* temp = initialiser_cellule_coureur();
						temp->infor = courant1->infor;
						courant1->infor = courant2->infor;
						courant2->infor = temp->infor;
					}
				
			}
		}
		return	liste;
	}
//------------------------------------------------------------------//


// -------------classer les équipes en maniere du temps------------- //

	struct classe_equipe* trier_classe_equipe(struct classe_equipe* classe)
	{
		struct cellule_equipe* courant1 = malloc(sizeof(struct cellule_equipe));
		for (courant1 = classe->equipe_1er; courant1 != NULL ; courant1 = courant1->equipe_suivant)
		{

			struct cellule_equipe* courant2;
			for (courant2 = courant1->equipe_suivant; courant2 != NULL; courant2 = courant2->equipe_suivant)
			{
				if (courant1->equipe.temps_cumulé > courant2->equipe.temps_cumulé)
				{
					struct cellule_equipe* temp = malloc(sizeof(struct cellule_equipe));
					temp->equipe = courant1->equipe;
					courant1->equipe = courant2->equipe;
					courant2->equipe = temp->equipe;
				}
			}
		}
		return	classe;
	}
//-------------------------------------------------------------------------//

//------------------------------ effacer un equipe ------------------------//

	void effacer_equipe_pointée(struct classe_equipe* liste, struct cellule_equipe* courant)
	{
		if (liste->equipe_1er == NULL)
		{
			printf("liste des coureur est Vide !");
			return;
		}

		if (courant == liste->equipe_1er)
		{
			liste->equipe_1er = liste->equipe_1er->equipe_suivant;
			courant = liste->equipe_1er;
			return;
		}
		else 
		{
			struct cellule_equipe* temp = liste->equipe_1er;
			while (temp->equipe_suivant != courant)
			{
				temp = temp->equipe_suivant;
			}

			temp->equipe_suivant = courant->equipe_suivant;
			courant = temp->equipe_suivant;
		}

	}
//---------------------------------------------------------------------------------------------//


// ---------------- Afficher la liste des coureurs ------------------------//

	void afficher_liste_coureur(struct Liste_coureur* liste)
	{
		struct cellule_coureur* courant = aller_début(liste);
		while (courant != NULL)
		{
			printf("\n ------------------- \n");
			afficher_Coureur(&(courant->infor));
			courant = avancer(courant);
		}
	}

//-----------------------------------------------------------------------------//































