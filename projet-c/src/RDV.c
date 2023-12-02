#ifdef HAVE_COONFIG_H
#include<config.h>
#endif
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"RDV.h"
#include <gtk/gtk.h>

int ajouter(char *filename, RDV r) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%s %s %d %d %d %d %d %s %d %d %d %d %s \n", r.nom, r.prenom, r.cin, r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee,r.horaire, r.sexe);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}

/*int modifier(char *filename, int id, RDV nouv) {
    RDV r;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    else {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d %d %s %s \n", r.nom, r.prenom, &(r.cin), &(r.DN.jour), &(r.DN.mois), &(r.DN.annee), r.gouvernement, r.ETS, &(r.DRV.jour), &(r.DRV.mois), &(r.DRV.annee),r.horaire, r.sexe) != EOF) {
            if (r.cin != id)
                fprintf(f2, "%s %s %d %s %d %d %d %d %s %d %d %d %s\n", r.nom, r.prenom, r.cin,  r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee, r.sexe);
            else
                fprintf(f2, "%s %s %d %s %d %d %d %d %s %d  %d %s\n", nouv.nom, nouv.prenom, nouv.cin, nouv.DN.jour, nouv.DN.mois, nouv.DN.annee, nouv.gouvernement, nouv.ETS, nouv.DRV.jour, nouv.DRV.mois, nouv.DRV.annee,r.horaire, nouv.sexe);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("aux.txt", filename);
        return 1;
    }
}

int supprimer(char *filename, int cin) {
int tr;
    RDV r;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL && f2 == NULL)
        
    {
        while (fscanf(f, "%d %d %d %d %d %d %d %d %d %d %d %d \n", r.nom, r.prenom, &(r.cin), &(r.DN.jour), &(r.DN.mois), &(r.DN.annee), r.gouvernement, r.ETS, &(r.DRV.jour), &(r.DRV.mois), &(r.DRV.annee), r.sexe) != EOF) {
            if (r.cin == cin)
                
  tr=1;
            else
                fprintf(f2, "%d %d %d %d %d %d %d %d %d %d %d \n", r.nom, r.prenom, r.cin, r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee);
        }
}
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("aux.txt", filename);
        return tr;
    }


RDV chercher(char *filename, int cin) {
    RDV r;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, "%d %d %d\n", &(r.DRV.jour), &(r.DRV.mois), &(r.DRV.annee)) != EOF && tr == 0) {
            if (r.cin == cin) {
                tr = 1;
            }
        }
    }
    if (tr == 0) {
        r.cin = -1;
    }
    return r;
}*/
void sexes(int specialite,char msg[])
{
if(specialite ==1)
 
 strcpy(msg,"Homme");
else 
  if(specialite==2)
  
strcpy(msg,"Femme");
}

