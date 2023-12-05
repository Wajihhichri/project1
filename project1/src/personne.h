#include <gtk/gtk.h>

typedef struct  
{
    char cin[30];
    char nom[30];
    char prenom[30];
    char date[30];
    char adresse[30];
} Personne;
void ajouter(Personne p);
void afficher_personne(GtkWidget *list);
void supprimer(Personne p);
