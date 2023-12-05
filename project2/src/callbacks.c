#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "inscription.h"

int specialite = 1 ;

void on_buttonEnvoyer_clicked(GtkWidget *objet, gpointer user_data) {

    char nom[30];
    char prenom[30];
    char msg[30]; 
    char nomComplet[60];
    GtkWidget *input1, *input2;
    GtkWidget *output1, *output2;
    
    input1 = lookup_widget(objet, "entryNom");
    input2 = lookup_widget(objet, "entryPrenom");
    output1 = lookup_widget(objet, "nomprenom");
    output2 = lookup_widget(objet, "specialite");
    
    strcpy(nom, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
    sprintf(nomComplet, "%s %s", nom, prenom);

    
    enregistrer(specialite, msg); 
    
    gtk_label_set_text(GTK_LABEL(output1), nomComplet);
    gtk_label_set_text(GTK_LABEL(output2), msg);
}



void on_radiobutton1_toggled(GtkToggleButton *togglebutton, gpointer user_data) {

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton))) {
        specialite = 1; 
    }
}


void on_radiobutton2_toggled(GtkToggleButton *togglebutton, gpointer user_data) {

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton))) {
        specialite = 2; 
    }
}

void on_radiobutton3_toggled(GtkToggleButton *togglebutton, gpointer user_data) {

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton))) {
        specialite = 3; 
    }
}

