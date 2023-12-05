#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <gtk/gtk.h>
#include "personne.h" 

enum {
    NOM,
    PRENOM,
    CIN,
    DATE,
    ADRESSE,
    COLUMNS
};


void ajouter(Personne p) {
    FILE* f;
    f = fopen("personne.txt", "a");
    if (f == NULL) {
        f = fopen("personne.txt", "w"); 
        if (f == NULL) {
            return;
        }
        fclose(f);
        f = fopen("personne.txt", "a"); 
    }
    fprintf(f, "%s %s %s %s %s \n", p.nom, p.prenom,p.cin, p.date, p.adresse);
    fclose(f);
}



void afficher_personne(GtkWidget *treeview) {
    GtkListStore *store;
    FILE *file;
    char nom[30], prenom[30], cin[30], date[30], adresse[30];

    file = fopen("personne.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    while (fscanf(file, "%s %s %s %s %s \n", nom, prenom, cin, date, adresse) == 5) {
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, NOM, nom, PRENOM, prenom, CIN, cin, DATE, date, ADRESSE, adresse, -1);
    }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    
    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        
        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Nom");
        gtk_tree_view_column_add_attribute(column, renderer, "text", NOM);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);

        
        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Prenom");
        gtk_tree_view_column_add_attribute(column, renderer, "text", PRENOM);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);



        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Cin");
        gtk_tree_view_column_add_attribute(column, renderer, "text", CIN);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);


        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Date de naissance");
        gtk_tree_view_column_add_attribute(column, renderer, "text", DATE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);



        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "adresse");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 150);


        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);





    } else {
        
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}





void supprimer(Personne p) {
    char nom[30], prenom[30], date[30], adresse[30], cin[30];

    FILE *f, *g;
    g = fopen("personne1.txt", "w");
    f = fopen("personne.txt", "r");
    if (f == NULL || g == NULL)
        return;

    while (fscanf(f, "%s %s %s %s %s", cin, nom, prenom, date, adresse) == 5) {
        if (strcmp(p.cin, cin) != 0 || strcmp(p.nom, nom) != 0 || strcmp(p.prenom, prenom) != 0 ||
            strcmp(p.date, date) != 0 || strcmp(p.adresse, adresse) != 0) {
            fprintf(g, "%s %s %s %s %s\n", cin, nom, prenom, date, adresse);
        }
    }

    remove("personne.txt");
    rename("personne1.txt", "personne.txt");
    fclose(f);
    fclose(g);
}
