#include<gtk/gtk.h>


typedef struct date 
{
 int jour;
 int mois;
 int annee;
}Date;
typedef struct rendez_vous
{ 
char nom [256];
char prenom[256] ;
int cin;
Date DN;
char gouvernement[256] ;
char ETS[256];
Date DRV;
char horaire[256];
char sexe [256];
}RDV;

int ajouter(char *filename ,RDV r);
void modifier(  int, RDV);
int supprimer (int cin);
int Chercher (char *,int);
void sexes(int specialite, char msg[]);
void historique(GtkWidget *liste, int CIN);
