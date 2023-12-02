#include <gtk/gtk.h>

void
on_utilisateur_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnuller_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour__clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_RDV_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_administrateur_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_infermier_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_medcin_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ets_clicked                         (GtkButton       *button,
                                        gpointer         user_data);
