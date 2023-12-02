#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"RDV.h"

int specialite=1;

void
on_utilisateur_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_donneur ,*aceuil;
aceuil = lookup_widget(objet,"aceuil");
gtk_widget_destroy(aceuil);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);


}
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 specialite=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 specialite=2;
}


void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 


GtkWidget *nom,*prenom, *ID;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *AjoutRdv ,*ajout_Avec_Sucsess;
GtkWidget *error;
int i,n;
char Gouvernement [50];
char ets [50][10];
char msg[50]="";
RDV r;
nom=lookup_widget(objet,"nom");
prenom=lookup_widget(objet,"prenom");
ID=lookup_widget(objet,"ID");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet ,"mois");
annee=lookup_widget(objet,"annee");
combobox1=lookup_widget(objet,"combobox1");
combobox2=lookup_widget(objet,"combobox2");
jour1=lookup_widget(objet,"jour1");
mois1=lookup_widget(objet,"mois1");
annee1=lookup_widget(objet,"annee1");
combobox3=lookup_widget(objet,"combobox3");
error=lookup_widget(objet,"error");

strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
 r.cin = atoi ( gtk_entry_get_text(GTK_ENTRY(ID))) ;

r.DN.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
r.DN.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
r.DN.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(Gouvernement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
r.gouvernement = Gouvernement[0];

r.DRV.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
r.DRV.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
r.DRV.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));

if(strcmp("8H-->9H",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)))==0)
r.horaire=1;
else
r.horaire=2;


for(i=0;i<n;i++){
   gtk_combo_box_append_text(GTK_COMBO_BOX(combobox3),_(ets[i]));
}
strcpy(r.ETS,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));



int x=ajouter("RDV.txt",r);
sexes(specialite, msg);
AjoutRdv = lookup_widget(objet,"AjoutRdv");
gtk_widget_destroy(AjoutRdv);
ajout_Avec_Sucsess=lookup_widget(objet,"ajout_Avec_Sucsess");
ajout_Avec_Sucsess=create_ajout_Avec_Sucsess();
gtk_widget_show(ajout_Avec_Sucsess);
   
}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAnuller_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{ 

}


void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour__clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout_Avec_Sucsess ,*window_donneur;
ajout_Avec_Sucsess = lookup_widget(objet,"ajout_Avec_Sucsess");
gtk_widget_destroy(ajout_Avec_Sucsess);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);

}


void
on_RDV_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *AjoutRdv,*window_donneur;
window_donneur = lookup_widget(objet,"window_donneur");
gtk_widget_destroy(window_donneur);
AjoutRdv=lookup_widget(objet,"AjoutRdv");
AjoutRdv=create_AjoutRdv();
gtk_widget_show(AjoutRdv);

}





void
on_administrateur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_infermier_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_medcin_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ets_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{

}

