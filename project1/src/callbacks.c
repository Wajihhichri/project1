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
#include "personne.h"


void on_buttonAjouter_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *input1, *input2, *input3, *input4, *input5;
    Personne p;

    input1 = lookup_widget(objet, "entryNom");
    input2 = lookup_widget(objet, "entryPrenom");
    input3 = lookup_widget(objet, "entryCin");
    input4 = lookup_widget(objet, "entryDate");
    input5 = lookup_widget(objet, "entryAdresse");

    const gchar *nom = gtk_entry_get_text(GTK_ENTRY(input1));
    const gchar *prenom = gtk_entry_get_text(GTK_ENTRY(input2));
    const gchar *cin = gtk_entry_get_text(GTK_ENTRY(input3));
    const gchar *date = gtk_entry_get_text(GTK_ENTRY(input4));
    const gchar *adresse = gtk_entry_get_text(GTK_ENTRY(input5));

    if (strlen(nom) == 0 || strlen(prenom) == 0 || strlen(cin) == 0 || strlen(date) == 0 || strlen(adresse) == 0) {
       
        return;
    }

    strcpy(p.nom, nom);
    strcpy(p.prenom, prenom);
    strcpy(p.cin, cin);
    strcpy(p.date, date);
    strcpy(p.adresse, adresse);

    ajouter(p);
}

void on_buttonAfficher_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_ajouter = lookup_widget(objet, "fenetre_ajouter");
    if (fenetre_ajouter != NULL) {
        gtk_widget_destroy(fenetre_ajouter);
    }

    GtkWidget *fenetre_afficher = create_fenetre_afficher();
    gtk_widget_show(fenetre_afficher);

    GtkWidget *treeview1 = lookup_widget(fenetre_afficher, "treeview1");
    afficher_personne(treeview1);
}


void on_treeview1_row_activated(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    GtkTreeIter iter;
    gchar *nom, *prenom, *cin, *date, *adresse;
    Personne p;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &date, 4, &adresse, -1);

        strcpy(p.cin, cin);
        strcpy(p.nom, nom);
        strcpy(p.prenom, prenom);
        strcpy(p.date, date);
        strcpy(p.adresse, adresse);

        supprimer(p);
        afficher_personne(treeview);
    }
}

void on_buttonRetourner_clicked(GtkWidget *objet, gpointer user_data) {
    GtkWidget *fenetre_afficher = lookup_widget(objet, "fenetre_afficher");
    if (fenetre_afficher != NULL) {
        gtk_widget_destroy(fenetre_afficher);
    }

    GtkWidget *fenetre_ajouter = create_fenetre_ajouter();
    gtk_widget_show(fenetre_ajouter);
}

