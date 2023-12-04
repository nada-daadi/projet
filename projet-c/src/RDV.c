#ifdef HAVE_COONFIG_H
#include<config.h>
#endif
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"RDV.h"
#include <gtk/gtk.h>

enum{
	ENOM,
	EPRENOM,
	ECIN,
	EDN,
	EGOUVERNEMENT,
	EETS,	
	EDRV,
	EHORAIRE,
	ESEXE,
	COLUMNS,
};

int ajouter(char *filename, RDV r) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%s %s %d %d %d %d %s %s %d %d %d %s %s \n", r.nom, r.prenom, r.cin, r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee,r.horaire, r.sexe);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}

void modifier(int ID, RDV newRdv) {
    FILE *f1 = fopen("RDV.txt", "r");
    FILE *f2 = fopen("newFile.txt", "w");

    RDV r;

    if (f1 != NULL && f2 != NULL) {
        int found = 0;

        while (fscanf(f1, " %d %d %d %s %s\n",&r.DRV.jour, &r.DRV.mois, &r.DRV.annee,r.gouvernement,r.horaire ) != EOF) {
            if (r.cin == ID) {
                fprintf(f2, "%d %s %s %s %s %s\n", r.DRV.jour, r.DRV.mois, r.DRV,r.gouvernement,r.horaire );
                found = 1; 
            } else {
                fprintf(f2, "%d %d %d %s %s\n",&r.DRV.jour, &r.DRV.mois, &r.DRV.annee,r.gouvernement,r.horaire );
            }
        }

        fclose(f1);
        fclose(f2);

        if (found) {
            remove("RDV.txt");
            rename("newFile.txt", "RDV.txt");
        } else {
            remove("newFile.txt");  
        }
    }
}

int supprimer(int cin) {
int tr;
    RDV r;
    FILE *f = fopen("RDV.txt", "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL && f2 == NULL)
        
    {
        while (fscanf(f, "%s %s %d %d %d %d %s %s %d %d %d %s %s \n", r.nom, r.prenom, &(r.cin), &(r.DN.jour), &(r.DN.mois), &(r.DN.annee), r.gouvernement, r.ETS, &(r.DRV.jour), &(r.DRV.mois), &(r.DRV.annee), r.horaire,r.sexe) != EOF) {
            if (r.cin == cin)
                
  tr=1;
            else
                fprintf(f2, "%s %s %d %d %d %d %s %s %d %d %d %s %s \n", r.nom, r.prenom, r.cin, r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee,r.horaire,r.sexe);
        }
}
        fclose(f);
        fclose(f2);
        remove("RDV.txt");
        rename("aux.txt", "RDV.txt");
        return tr;
    }


int Chercher(char *nomFichier, int ID) {
    RDV r;
    int found = 0;
    FILE *f1 = fopen(nomFichier, "r");
    FILE *f2 = fopen("cherche.txt", "w");

    if (f1 != NULL && f2 != NULL) {
        while (fscanf(f1, "%s %s %d %s %d %d %d %s %s %d %d %d %s %s\n", r.nom, r.prenom, &(r.cin), &(r.DN.jour), &(r.DN.mois), &(r.DN.annee), r.gouvernement, r.ETS, &(r.DRV.jour), &(r.DRV.mois), &(r.DRV.annee),r.horaire, r.sexe) != EOF) {
            if (r.cin == ID) {
                found = 1;
                fprintf(f2,"%s %s %d %s %d %d %d %s %s %d %d %d %s\n", r.nom, r.prenom, r.cin,  r.DN.jour, r.DN.mois, r.DN.annee, r.gouvernement, r.ETS, r.DRV.jour, r.DRV.mois, r.DRV.annee,r.horaire);
            }
        }
        fclose(f1);
        fclose(f2);
    }

    return found;
}

void historique(GtkWidget *liste, int CIN) {
  GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
char nom [256];
char prenom[256] ;
int cin;
char DN;
char gouvernement[256] ;
char ETS[256];
char DRV;
char horaire[256];
char sexe [256];

RDV r;
FILE *f;

store = gtk_tree_view_get_model(liste);

if(r.cin==CIN)
{
 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("DN", renderer, "text", EDN, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("gouvernement", renderer, "text", EGOUVERNEMENT, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ETS", renderer, "text", EETS, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("DRV", renderer, "text", EDRV, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("horaire", renderer, "text", EHORAIRE, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text", ESEXE, NULL);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_POINTER ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("RDV.txt","r");
if(f==NULL)
{
   	return;
}
else


{
	f = fopen("utilisateur.txt","a+");
	while(fscanf(f,"%s %s %d %s %s %s %s %s %s\n",nom,prenom,cin,DN,gouvernement,ETS,DRV,horaire,sexe)!=EOF)
{
gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,EDN,DN,EGOUVERNEMENT,gouvernement,EETS,ETS,
EHORAIRE,horaire,ESEXE,sexe,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
}
}

