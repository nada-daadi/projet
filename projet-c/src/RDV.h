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
char gouvernement ;
char ETS[256];
Date DRV;
char horaire;
char sexe [256];
}RDV;

int ajouter(char *filename ,RDV r);
int modifier( char *, int, RDV);
int supprimer (char *, int);
RDV chercher (char *,int);
void sexes(int specialite, char msg[]);
