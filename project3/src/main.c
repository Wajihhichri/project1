/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"


#include <gtk/gtk.h>

// Vos déclarations de fonctions vont ici

int main(int argc, char *argv[]) {
    GtkWidget *fenetre_ajouter;
    GtkWidget *fenetre_afficher;
    GtkWidget *fenetre_afficher_stat;

    gtk_set_locale();
    gtk_init(&argc, &argv);

    add_pixmap_directory(PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

    // Création des fenêtres
    fenetre_ajouter = create_fenetre_ajouter();
    fenetre_afficher = create_fenetre_afficher();
    fenetre_afficher_stat = create_fenetre_afficher_stat();

    // Connexions des signaux, par exemple :
    // g_signal_connect(G_OBJECT(fenetre_ajouter), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Masquer les fenêtres sauf fenetre_ajouter
    gtk_widget_show(fenetre_ajouter);
    gtk_widget_hide(fenetre_afficher);
    gtk_widget_hide(fenetre_afficher_stat);

    gtk_main();

    return 0;
}

// Définitions de vos fonctions ici


