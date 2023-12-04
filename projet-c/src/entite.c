#include <stdio.h>
#include <string.h>
#include"entite.h"

#define TAILLE_MAX_LIGNE 100

void historique(GtkWidget *list, int CIN) {
    FILE *fichierDonnees;
    FILE *fichierHistorique;
    char ligne[TAILLE_MAX_LIGNE];

    fichierDonnees = fopen("RDV.txt", "r"); 

    if (fichierDonnees == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier de donnees.\n");
        return;
    }

    fichierHistorique = fopen("historique_dons.txt", "w"); 

    if (fichierHistorique == NULL) {
        printf("Erreur : Impossible de creer le fichier d'historique.\n");
        fclose(fichierDonnees);
        return;
    }

    
    while (fgets(ligne, TAILLE_MAX_LIGNE, fichierDonnees) != NULL) {
        
        if (strstr(ligne, CIN) != NULL) {
           
            fprintf(fichierHistorique, "%s", ligne);
        }
    }

    printf("Historique des dons pour le donneur avec CIN '%s' a ete enregistre dans historique_dons.txt.\n", CIN);

    fclose(fichierDonnees);
    fclose(fichierHistorique);
}


int capacite(char nomFichier[], char ETS[]) {
    FILE *fichierETS;
    char ligne[TAILLE_MAX_LIGNE];
    char nomETS[TAILLE_MAX_LIGNE];
    int capaciteETS;
    int capaciteTrouvee = -1; // Valeur par défaut si l'ETS n'est pas trouvé

    fichierETS = fopen(nomFichier, "r"); // Ouvre le fichier contenant les informations sur les ETS en mode lecture

    if (fichierETS == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des ETS.\n");
        return capaciteTrouvee;
    }

    // Parcours du fichier des ETS ligne par ligne
    while (fgets(ligne, TAILLE_MAX_LIGNE, fichierETS) != NULL) {
        // Extraction du nom de l'ETS et de sa capacité à partir de la ligne
        if (sscanf(ligne, "%s %d", nomETS, &capaciteETS) == 2) {
            // Vérifie si le nom de l'ETS correspond à celui recherché
            if (strcmp(nomETS, ETS) == 0) {
                // Si l'ETS est trouvé, sauvegarde sa capacité et sort de la boucle
                capaciteTrouvee = capaciteETS;
                break;
            }
        }
    }

    fclose(fichierETS);

    if (capaciteTrouvee == -1) {
        printf("L'ETS '%s' n'a pas ete trouve dans le fichier des capacites.\n", ETS);
    } else {
        printf("La capacite de l'ETS '%s' est de %d.\n", ETS, capaciteTrouvee);
    }

    return capaciteTrouvee;
}




int HoraireDispo(char nomFichier[], char ETS[], int capacite, int jour, int mois, int annee, char horaire[]) {
    FILE *fichierRDV;
    char ligne[TAILLE_MAX_LIGNE];
    char nomETSRDV[TAILLE_MAX_LIGNE];
    int jourRDV, moisRDV, anneeRDV;
    char horaireRDV[TAILLE_MAX_LIGNE];
    int nombreRDVs = 0;

    fichierRDV = fopen(nomFichier, "r"); // Ouvre le fichier contenant les rendez-vous en mode lecture

    if (fichierRDV == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des RDV.\n");
        return -1; // Valeur d'erreur
    }

    // Parcours du fichier des RDV ligne par ligne
    while (fgets(ligne, TAILLE_MAX_LIGNE, fichierRDV) != NULL) {
        // Extraction des informations du rendez-vous à partir de la ligne
        if (sscanf(ligne, "%s %d/%d/%d %s", nomETSRDV, &jourRDV, &moisRDV, &anneeRDV, horaireRDV) == 5) {
            // Vérifie si l'ETS, la date et l'horaire correspondent aux critères spécifiés
            if (strcmp(nomETSRDV, ETS) == 0 && jourRDV == jour && moisRDV == mois && anneeRDV == annee &&
                strcmp(horaireRDV, horaire) == 0) {
                nombreRDVs++; // Incrémente le nombre de RDVs pour cet horaire et cette date
            }
        }
    }

    fclose(fichierRDV);

    int placesDispo = capacite - nombreRDVs;

    if (placesDispo > 0) {
        printf("Il reste %d place(s) disponible(s) pour l'ETS '%s' le %d/%d/%d a %s.\n",
               placesDispo, ETS, jour, mois, annee, horaire);
        return placesDispo;
    } else {
        printf("Il n'y a plus de places disponibles pour l'ETS '%s' le %d/%d/%d a %s.\n",
               ETS, jour, mois, annee, horaire);
        return 0;
    }
}




