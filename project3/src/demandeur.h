#include <gtk/gtk.h>


typedef struct {
    char etab[30];
    char service[30];
    char urgence[30];
    char type[30];
    char quantite[30];
    char date[30];
} Demande;


void ajouterPoches(Demande d);
void supprimerPoches(const char *etab);
void modifierPoches(const char *etab, Demande d1) ;
float pourcentage(char etab1[]);
void message4 (char *msg);
void afficher_demande(GtkTreeView *treeview);
void Trouver(const char *etab, const char *cle, GtkWidget *treeview);
void vider(GtkWidget *treeview);
void affichePoches(GtkTreeView *treeview) ;
