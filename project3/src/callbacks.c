#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "demandeur.h"

int etat = 1 ;


void on_buttonAjouterPoch_clicked   (GtkWidget *objet, gpointer user_data) {
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
    Demande d;
    char msg[30];

    input1 = lookup_widget(objet, "entryEtablissement");
    input2 = lookup_widget(objet, "entryService");
    input3 = lookup_widget(objet, "comboboxType");
    input4 = lookup_widget(objet, "entryQuantite");
    input5 = lookup_widget(objet, "entryUrgence");
    input6 = lookup_widget(objet, "entryDate");

    strcpy(d.etab, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(d.service, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(d.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
    strcpy(d.quantite, gtk_entry_get_text(GTK_ENTRY(input4)));
    strcpy(d.urgence, gtk_entry_get_text(GTK_ENTRY(input5)));
    strcpy(d.date, gtk_entry_get_text(GTK_ENTRY(input6)));

    ajouterPoches(d);
}


void on_buttonAfficherstat_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_ajouter = lookup_widget(objet, "fenetre_ajouter");

    if (fenetre_ajouter != NULL) {
        gtk_widget_destroy(fenetre_ajouter);
    }

    GtkWidget *fenetre_afficher_stat = create_fenetre_afficher_stat();
    gtk_widget_show(fenetre_afficher_stat);

    GtkWidget *msg_label = lookup_widget(fenetre_afficher_stat, "msg5");

    if (msg_label != NULL) {
        GtkWidget *treeviewAffStat = lookup_widget(fenetre_afficher_stat, "treeviewAffStat");
        affichePoches(GTK_TREE_VIEW(treeviewAffStat));

        char msg[30];
        message4(msg);

        gtk_label_set_text(GTK_LABEL(msg_label), msg);
    }
}







void on_buttonSupprimerPoch_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *etab;
    char msg[30];
    
    etab = lookup_widget(objet, "entrySupprimer");
    strcpy(msg, gtk_entry_get_text(GTK_ENTRY(etab)));
    
    
    supprimerPoches(msg);   
}




void on_buttonModifierPoch_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *etab, *nom, *service, *type, *quantite;
    Demande d;

    etab = lookup_widget(objet, "entryModifier");
    nom = lookup_widget(objet, "entryNouveauNom");
    service = lookup_widget(objet, "entryNouveauService");
    type = lookup_widget(objet, "comboboxNouveauType");
    quantite = lookup_widget(objet, "entryNouvelleQuantite");

    const char *etab_text = gtk_entry_get_text(GTK_ENTRY(etab));

    strcpy(d.etab, gtk_entry_get_text(GTK_ENTRY(nom))); 
    strcpy(d.service, gtk_entry_get_text(GTK_ENTRY(service)));
    strcpy(d.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
    strcpy(d.quantite, gtk_entry_get_text(GTK_ENTRY(quantite)));
    
   
    strcpy(d.date, "05/12/2023");
    strcpy(d.urgence, "standard");

    modifierPoches(etab_text, d);
}




void on_buttonAfficherPoch_clicked (GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_ajouter = lookup_widget(objet, "fenetre_ajouter");
    if (fenetre_ajouter != NULL) {
        gtk_widget_destroy(fenetre_ajouter);
    }

    GtkWidget *fenetre_afficher = create_fenetre_afficher();
    gtk_widget_show(fenetre_afficher);

    GtkWidget *treeviewAff = lookup_widget(fenetre_afficher, "treeviewAff");
    afficher_demande(GTK_TREE_VIEW(treeviewAff));
}





void on_buttonTrouver_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *etab_entry, *cle_combobox, *treeview;
    const char *etab;
    const char *cle;

    etab_entry = lookup_widget(objet, "entryMot");
    cle_combobox = lookup_widget(objet, "comboboxcle");

    etab = gtk_entry_get_text(GTK_ENTRY(etab_entry));
    cle = gtk_combo_box_get_active_text(GTK_COMBO_BOX(cle_combobox));

    treeview = lookup_widget(objet, "treeviewAff"); 

    Trouver(etab, cle, treeview);

    g_free((gpointer)cle);
}

void on_treeview1_row_activated(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    GtkTreeIter iter;
    gchar etab[30], service[30], urgence[30], type[30], quantite[30], date[30];
    Demande d;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 0, &etab, 1, &service, 2, &urgence, 3, &type, 4, &quantite, 5, &date, -1);

        strcpy(d.etab, etab);
        strcpy(d.service, service);
        strcpy(d.urgence, urgence);
        strcpy(d.type, type);
        strcpy(d.quantite, quantite);
        strcpy(d.date, date);

        supprimerPoches(d.etab);
        GtkWidget *widget = GTK_WIDGET(treeview);
        afficher_demande(GTK_TREE_VIEW(widget));
    }
}


void on_buttonRetourner1_clicked(GtkWidget *objet, gpointer user_data) {
    
    GtkWidget *fenetre_afficher , *fenetre_ajouter ; 
    fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
	gtk_widget_hide(fenetre_afficher) ;
	fenetre_ajouter=create_fenetre_ajouter() ;    
	gtk_widget_show(fenetre_ajouter) ;    

   
    
}




void on_buttonActualiser1_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_afficher, *w1;
    GtkTreeView *treeviewAff;

    w1 = lookup_widget(objet, "fenetre_afficher");
    fenetre_afficher = create_fenetre_afficher();
    gtk_widget_show(fenetre_afficher);
    gtk_widget_hide(w1);

    treeviewAff = GTK_TREE_VIEW(lookup_widget(fenetre_afficher, "treeviewAff"));

    vider(GTK_WIDGET(treeviewAff));
    afficher_demande(treeviewAff);
}

void on_buttonRetourner2_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_afficher_stat, *fenetre_ajouter; 
    fenetre_afficher_stat = lookup_widget(objet, "fenetre_afficher_stat");
    gtk_widget_hide(fenetre_afficher_stat);
    fenetre_ajouter = create_fenetre_ajouter();
    gtk_widget_show(fenetre_ajouter);
}







void on_buttonActualiser2_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_afficher_stat, *w1, *treeviewAffStat;
    w1 = lookup_widget(objet, "fenetre_afficher_stat");
    fenetre_afficher_stat = create_fenetre_afficher_stat();
    gtk_widget_show(fenetre_afficher_stat);
    gtk_widget_hide(w1);

    treeviewAffStat = lookup_widget(fenetre_afficher_stat, "treeviewAffStat");

    vider(treeviewAffStat);
    affichePoches(GTK_TREE_VIEW(treeviewAffStat));

}





 




