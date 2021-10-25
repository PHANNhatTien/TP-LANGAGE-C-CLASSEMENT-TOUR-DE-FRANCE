#pragma once

#include <time.h>
#include <string.h>

struct coureur {
	char Nom[50];
	char Prénom[50];
	int dossard;
	char Equipe[50];
	//struct tm temps; // temps.tm_sec ; temps.tm_min ; temps.tm_hour , plus précise
	int temps;
};

struct coureur * Creer_Coureur(char* nom, char * prenom, int dossard, char* nom_équipe)
{
	struct coureur* coureur = malloc(sizeof(struct coureur));
	strcpy_s(coureur->Nom, 20, nom );
	strcpy_s(coureur->Prénom, 20 ,prenom);
	coureur->dossard = dossard;
	strcpy_s(coureur->Equipe, 20, nom_équipe);
	coureur->temps = 0;
	return coureur;
}

void Ajouter_temps(struct coureur* coureur, int temps)
{
	coureur->temps += temps;
}

void afficher_Coureur(struct coureur * coureur)
{
	printf("Nom du Coureur : %s \n", coureur->Nom);
	printf("Prenom du Coureur : %s \n", coureur->Prénom);
	printf("dossard du Coureur : %d \n", coureur->dossard);
	printf("Nom d'equipe du Coureur : %s \n", coureur->Equipe);
	printf("Temps cumule du Coureur : %d h %d m %d s \n", (coureur->temps)/3600, ((coureur->temps) % 3600) / 60, (((coureur->temps) % 3600) % 60));
	printf("\n ------------------- \n");
}

