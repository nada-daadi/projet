#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"RDV.h"

int specialite;
int specialitee;
char choix[50];

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
specialitee=1;
}


void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 


GtkWidget *input1,*input2,*input3;
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

RDV r;
input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"prenom");
input3=lookup_widget(objet,"ID");
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

strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

const char *id_n = gtk_entry_get_text(GTK_ENTRY(input3));
r.cin=atoi(id_n);
 if (strlen(id_n) != 8) {
        gtk_label_set_text(GTK_LABEL(error), "L'ID doit contenir exactement 8 chiffres !\n");
        return;
    }


r.DN.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
r.DN.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
r.DN.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(r.gouvernement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(r.ETS,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));


r.DRV.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
r.DRV.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
r.DRV.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));

strcpy(r.horaire,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

if(specialite==1)
strcpy(r.sexe,"HOMME");
if(specialitee==1);
strcpy(r.sexe,"FEMME");


int x=ajouter("RDV.txt",r);

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
GtkWidget *AjoutRdv ,*window_donneur;
AjoutRdv = lookup_widget(objet,"AjoutRdv");
gtk_widget_destroy(AjoutRdv);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);

}


void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonSupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

int id1,x;
GtkWidget *id ,*out;
RDV r;
id=lookup_widget(objet,"id");
out=lookup_widget(objet,"outsupp");
GtkWidget *supprimer_RDV ,*confirmerSupprimerRdv;
const char *id_n = gtk_entry_get_text(GTK_ENTRY(id));
 
if (strlen(id_n) != 8) {
        gtk_label_set_text(GTK_LABEL(out), "L'ID doit contenir exactement 8 chiffres !");
        return;
    }
id1=atoi(id_n);
 

if(choix[0]==1 )
{
x==supprimer(id1);
 supprimer_RDV= lookup_widget(objet,"supprimer_RDV");
gtk_widget_destroy(supprimer_RDV);
confirmerSupprimerRdv=lookup_widget(objet,"confirmerSupprimerRdv");
confirmerSupprimerRdv=create_confirmerSupprimerRdv();
gtk_widget_show(confirmerSupprimerRdv);
        return;
}

     
 else  {
        gtk_label_set_text(GTK_LABEL(out), "Choisissez confirmer, s'il vous plaît");
    


}
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


void
on_supprimerRdv_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *supprimer_RDV,*window_donneur;
window_donneur = lookup_widget(objet,"window_donneur");
gtk_widget_destroy(window_donneur);
supprimer_RDV=lookup_widget(objet,"supprimer_RDV");
supprimer_RDV=create_supprimer_RDV();
gtk_widget_show(supprimer_RDV);

}


void
on_historique_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *HISTORIQUE_rv,*window_donneur;
window_donneur = lookup_widget(objet,"window_donneur");
gtk_widget_destroy(window_donneur);
HISTORIQUE_rv=lookup_widget(objet,"HISTORIQUE_rv");
HISTORIQUE_rv=create_HISTORIQUE_rv();
gtk_widget_show(HISTORIQUE_rv);

}




void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_anuller1_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_RDV,*window_donneur;
supprimer_RDV = lookup_widget(objet,"supprimer_RDV");
gtk_widget_destroy(supprimer_RDV);
supprimer_RDV=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);

}


void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *confirmerSupprimerRdv ,*window_donneur;
confirmerSupprimerRdv = lookup_widget(objet,"confirmerSupprimerRdv");
gtk_widget_destroy(confirmerSupprimerRdv);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);


}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[0] = 1;
else
choix[0] = 0;

}


void
on_modif1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *modifRDV,*window_donneur;
window_donneur = lookup_widget(objet,"window_donneur");
gtk_widget_destroy(window_donneur);
modifRDV=lookup_widget(objet,"modifRDV");
modifRDV=create_modifRDV();
gtk_widget_show(modifRDV);


}


void
on_retour3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *HISTORIQUE_rv ,*window_donneur;
HISTORIQUE_rv = lookup_widget(objet,"HISTORIQUE_rv");
gtk_widget_destroy(HISTORIQUE_rv);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);


}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar  cin;
	RDV r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
		
	{
		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0,&nom, 1,&prenom, 2,&cin,-1);

		
		strcpy(r.nom,nom);
		strcpy(r.prenom,prenom);
		strcpy(r.cin,cin);
	}
}


void
on_buttonafficherr_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2,*HISTORIQUE_rv;
int id1;
GtkWidget *id ,*out;
RDV r;
id=lookup_widget(objet,"entry7");
out=lookup_widget(objet,"outaffich");
const char *id_n = gtk_entry_get_text(GTK_ENTRY(id));
 
if (strlen(id_n) != 8) {
        gtk_label_set_text(GTK_LABEL(out), "L'ID doit contenir exactement 8 chiffres !");
        return;
}
id1=atoi(id_n);

HISTORIQUE_rv =  lookup_widget(objet, "HISTORIQUE_rv");
treeview2=lookup_widget(HISTORIQUE_rv,"treeview2");
historique(treeview2,id1);



}


void
on_Anuller11_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifRDV ,*window_donneur;
modifRDV = lookup_widget(objet,"modifRDV");
gtk_widget_destroy(modifRDV);
window_donneur=lookup_widget(objet,"window_donneur");
window_donneur=create_window_donneur();
gtk_widget_show(window_donneur);

}


void
on_button43_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
int id,x;
RDV r;


GtkWidget *input1=lookup_widget(objet,"entry48");
GtkWidget *input2=lookup_widget(objet,"combobox4");
GtkWidget *input3=lookup_widget(objet,"combobox5");
GtkWidget *input4=lookup_widget(objet,"spinbutton20");
GtkWidget *input5=lookup_widget(objet,"spinbutton21");
GtkWidget *input6=lookup_widget(objet,"spinbutton22");
GtkWidget *input7=lookup_widget(objet,"spinbutton23");
GtkWidget *input8=lookup_widget(objet,"entry49");
GtkWidget *input9=lookup_widget(objet,"entry51");
GtkWidget *input10=lookup_widget(objet,"combobox6");
GtkWidget *input11=lookup_widget(objet,"entry50");
GtkWidget *input12=lookup_widget(objet,"spinbutton24");
GtkWidget *input13=lookup_widget(objet,"spinbutton25");
GtkWidget *output1=lookup_widget(objet,"label141");
GtkWidget *output2=lookup_widget(objet,"label142");
GtkWidget *output3=lookup_widget(objet,"heuree");
GtkWidget *output4=lookup_widget(objet,"label145");
GtkWidget *output5=lookup_widget(objet,"label146");
GtkWidget *output6=lookup_widget(objet,"label147");
GtkWidget *output7=lookup_widget(objet,"label148");
GtkWidget *output8=lookup_widget(objet,"label149");
GtkWidget *output9=lookup_widget(objet,"label150");

const char *id_n=gtk_entry_get_text(GTK_ENTRY(input1));

if(strlen(id_n)!=8) {
        gtk_label_set_text(GTK_LABEL(output4), "L'ID doit contenir exactement 8 chiffres !");
        return;
    }

id=atoi(id_n);
if(Chercher("RDV.txt",id)==0){
	
        gtk_label_set_text(GTK_LABEL(output4), "Rendez-vous non trouvé. Veuillez vérifier l'ID, s'il vous plaît !\n");}
	else 
		if(Chercher("RDV.txt", id) == 1) {
	gtk_label_set_text(GTK_LABEL(output4),"Veuillez entrer vos modifications.");
	
	
	gtk_editable_set_editable(GTK_EDITABLE(input1), FALSE);
	
	gtk_widget_set_visible(input2, TRUE);
        gtk_widget_set_visible(input3, TRUE);
        gtk_widget_set_visible(input4, TRUE);
        gtk_widget_set_visible(input5, TRUE);
        gtk_widget_set_visible(input6, TRUE);
        gtk_widget_set_visible(input7, TRUE);
	gtk_widget_set_visible(input8, TRUE);
	gtk_widget_set_visible(input9, TRUE);
	gtk_widget_set_visible(input10, TRUE);
	gtk_widget_set_visible(input11, TRUE);
	gtk_widget_set_visible(input12, TRUE);
	gtk_widget_set_visible(input13, TRUE);
        gtk_widget_set_visible(output1, TRUE);
        gtk_widget_set_visible(output2, TRUE);
        gtk_widget_set_visible(output3, TRUE);
	gtk_widget_set_visible(output5, TRUE);
	gtk_widget_set_visible(output6, TRUE);
	gtk_widget_set_visible(output7, TRUE);
	gtk_widget_set_visible(output8, TRUE);
	gtk_widget_set_visible(output9, TRUE);
}

}


void
on_modif11_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
int ID,x ;RDV   new;
GtkWidget *input1=lookup_widget(objet,"entry48");
GtkWidget *input2=lookup_widget(objet,"combobox4");
GtkWidget *input3=lookup_widget(objet,"combobox5");
GtkWidget *input4=lookup_widget(objet,"spinbutton20");
GtkWidget *input5=lookup_widget(objet,"spinbutton21");
GtkWidget *input6=lookup_widget(objet,"spinbutton22");
GtkWidget *input7=lookup_widget(objet,"spinbutton22");

ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
new.DN.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
new.DN.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
new.DN.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(new.gouvernement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(new.horaire,gtk_entry_get_text(GTK_ENTRY(input3)));
modifier( ID,  new);

}

