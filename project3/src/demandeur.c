#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <gtk/gtk.h>
#include "demandeur.h"
#include "support.h"

enum {
    ETAB,
    SERVICE,
    URGENCE,
    TYPE,
    QUANTITE,
    DATE,
    COLUMNS
};


void ajouterPoches(Demande d) {
    FILE* f = fopen("demande.txt", "a");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(f, "%s %s %s %s %s %s\n", d.etab, d.service, d.urgence, d.type, d.quantite, d.date);
    fclose(f);
}




void supprimerPoches(const char *etab) {
    char etab_read[30], service[30], urgence[30], type[30], quantite[30],date[30];
    
    FILE *f, *g;
    g = fopen("demande1.txt", "w");
    f = fopen("demande.txt", "r");
    if (f == NULL || g == NULL)
        return;

    Demande d;
    strcpy(d.etab, etab); 

    while (fscanf(f, "%s %s %s %s %s %s ", etab_read, service, urgence, type, quantite, date) == 6) {
        if (strcmp(d.etab, etab_read) != 0) {
            fprintf(g, "%s %s %s %s %s %s \n", etab_read, service, urgence, type, quantite, date);
        }
    }

    remove("demande.txt");
    rename("demande1.txt", "demande.txt");
    fclose(f);
    fclose(g);
}


void modifierPoches(const char *etab, Demande d1) {
    char etab_read[30], service[30], urgence[30], type[30], quantite[30],date[30];
    

    FILE *f, *temp;
    f = fopen("demande.txt", "r");
    temp = fopen("temp.txt", "w");

    if (f == NULL || temp == NULL) {
        return;
    }

    while (fscanf(f, "%s %s %s %s %s %s ", etab_read, service, urgence, type, quantite, date) == 6) {
        if (strcmp(etab, etab_read) == 0) {
            fprintf(temp, "%s %s %s %s %s %s \n", d1.etab, d1.service, urgence,d1.type, d1.quantite, date);
        } else {
            fprintf(temp, "%s %s %s %s %s %s \n", etab_read, service, urgence, type, quantite, date);
        }
    }

    fclose(f);
    fclose(temp);

    remove("demande.txt");
    rename("temp.txt", "demande.txt");
}








float pourcentage(char etab1[]) {
    char etab[30], service[30], urgence[30], type[30], quantite[30], date[30];
    int s, d;
    s = 0;
    d = 0;

    FILE *f;
    f = fopen("demande.txt", "r");
    if (f == NULL)
        return 0.0; 

    while (fscanf(f, "%s %s %s %s %s %s ", etab, service, urgence, type, quantite, date) == 6) {
        s++;
        if (strcmp(etab, etab1) == 0) {
            d++;
        }
    }

    fclose(f);

    if (s == 0) {
        return 0.0; 
    }

    return ((float)d / s) * 100.0;
}
void message4(char *msg) {
    char etab_read[30], service[30], urgence[30], type_sang[30], quantite[30], date[30];
    int count_Ap = 0, count_An = 0, count_Bp = 0, count_Bn = 0, count_ApBp = 0, count_ApBn = 0, count_OP = 0, count_ON = 0;
    int max_count = 0; 
    FILE *f;

    f = fopen("demande.txt", "r");
    if (f == NULL) {
        return;
    }

    while (fscanf(f,"%29s %29s %29s %29s %29s %29s ", etab_read, service, urgence, type_sang, quantite, date) == 6 ) {
        if (strcmp(type_sang, "A+") == 0) {
            count_Ap++;
        } else if (strcmp(type_sang, "A-") == 0) {
            count_An++;
        } else if (strcmp(type_sang, "B+") == 0) {
            count_Bp++;
        } else if (strcmp(type_sang, "B-") == 0) {
            count_Bn++;
        } else if (strcmp(type_sang, "AB+") == 0) {
            count_ApBp++;
        } else if (strcmp(type_sang, "AB-") == 0) {
            count_ApBn++;
        } else if (strcmp(type_sang, "O+") == 0) {
            count_OP++;
        } else if (strcmp(type_sang, "O-") == 0) {
            count_ON++;
        }
    }

    fclose(f);

    if (count_Ap >= count_An && count_Ap >= count_Bp && count_Ap >= count_Bn && count_Ap >= count_ApBp && count_Ap >= count_ApBn && count_Ap >= count_OP && count_Ap >= count_ON) {
        max_count = count_Ap;
        strcpy(msg, "A+");
    } else if (count_An >= count_Ap && count_An >= count_Bp && count_An >= count_Bn && count_An >= count_ApBp && count_An >= count_ApBn && count_An >= count_OP && count_An >= count_ON) {
        max_count = count_An;
        strcpy(msg, "A-");
    } else if (count_Bp >= count_Ap && count_Bp >= count_An && count_Bp >= count_Bn && count_Bp >= count_ApBp && count_Bp >= count_ApBn && count_Bp >= count_OP && count_Bp >= count_ON) {
        max_count = count_Bp;
        strcpy(msg, "B+");
    } else if (count_Bn >= count_Ap && count_Bn >= count_An && count_Bn >= count_Bp && count_Bn >= count_ApBp && count_Bn >= count_ApBn && count_Bn >= count_OP && count_Bn >= count_ON) {
        max_count = count_Bn;
        strcpy(msg, "B-");
    } else if (count_ApBp >= count_Ap && count_ApBp >= count_An && count_ApBp >= count_Bp && count_ApBp >= count_Bn && count_ApBp >= count_ApBn && count_ApBp >= count_OP && count_ApBp >= count_ON) {
        max_count = count_ApBp;
        strcpy(msg, "AB+");
    } else if (count_ApBn >= count_Ap && count_ApBn >= count_An && count_ApBn >= count_Bp && count_ApBn >= count_Bn && count_ApBn >= count_ApBp && count_ApBn >= count_OP && count_ApBn >= count_ON) {
        max_count = count_ApBn;
        strcpy(msg, "AB-");
    } else if (count_OP >= count_Ap && count_OP >= count_An && count_OP >= count_Bp && count_OP >= count_Bn && count_OP >= count_ApBp && count_OP >= count_ApBn && count_OP >= count_ON) {
        max_count = count_OP;
        strcpy(msg, "O+");
    } else {
        max_count = count_ON;
        strcpy(msg, "Type O-");
    }

    if (max_count == 0) {
        strcpy(msg, "rien");
    }
}


void afficher_demande(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
    char etab[30], service[30], urgence[30], type[30], quantite[30], date[30];

    file = fopen("demande.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    while (fscanf(file, "%s %s %s %s %s %s\n", etab, service, urgence, type,
                  quantite, date) == 6) {
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ETAB, etab, SERVICE, service, URGENCE, urgence,
                           TYPE, type, QUANTITE, quantite, DATE, date, -1);
    }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Etablissement");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ETAB);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);
        
   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Service medicale");
       gtk_tree_view_column_add_attribute(column, renderer, "text", SERVICE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Urgence");
       gtk_tree_view_column_add_attribute(column, renderer, "text", URGENCE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Type de sang");
       gtk_tree_view_column_add_attribute(column, renderer, "text", TYPE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Quantité");
       gtk_tree_view_column_add_attribute(column, renderer, "text", QUANTITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Date");
       gtk_tree_view_column_add_attribute(column, renderer, "text", DATE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


         


        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}





void affichePoches(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
    char etab[30], service[30], urgence[30], type[30], quantite[30], date[30];
    float p;
    file = fopen("demande.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_FLOAT);

    while (fscanf(file, "%s %s %s %s %s %s\n", etab, service, urgence, type, quantite, date) == 6) {
        GtkTreeIter iter;
        p = pourcentage(etab); 
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, etab, 1, p, -1);
    }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Etablissement");
        gtk_tree_view_column_add_attribute(column, renderer, "text", 0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 300);

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Pourcentage");
        gtk_tree_view_column_add_attribute(column, renderer, "text", 1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 300);

        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}

void Trouver(const char *Motcle, const char *cle, GtkWidget *treeview) {
    GtkListStore *store;
    FILE *file;
    char etab_read[30], service[30], urgence[30], type[30], quantite[30], date[30];

    file = fopen("demande.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    GtkTreeIter iter;

    while (fscanf(file, "%s %s %s %s %s %s\n", etab_read, service, urgence,
                  type, quantite, date) == 6) {
        if (strcmp(cle, "Établissement") == 0 && strcmp(Motcle, etab_read) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ETAB, etab_read,SERVICE,service,URGENCE,urgence,TYPE,type,QUANTITE,quantite,DATE,date, -1);
        } else if (strcmp(cle, "Service_medicale") == 0 && strcmp(Motcle, service) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ETAB, etab_read, SERVICE, service,URGENCE,urgence,TYPE,type,QUANTITE,quantite,DATE,date, -1);
        } else if (strcmp(cle, "Urgence") == 0 && strcmp(Motcle, urgence) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ETAB, etab_read, SERVICE, service, URGENCE, urgence,TYPE,type,QUANTITE,quantite,DATE,date, -1);
        } else if (strcmp(cle, "Type_de_sang") == 0 && strcmp(Motcle, type) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ETAB, etab_read, SERVICE, service, URGENCE, urgence, TYPE, type,QUANTITE,quantite,DATE,date, -1);
        } else if (strcmp(cle, "Quantité") == 0 && strcmp(Motcle, quantite) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ETAB, etab_read, SERVICE, service, URGENCE, urgence, TYPE, type, QUANTITE, quantite,DATE,date, -1);
        } else if (strcmp(cle, "Date_de_la_demande") == 0 && strcmp(Motcle, date) == 0) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ETAB, etab_read, SERVICE, service, URGENCE, urgence, TYPE, type, QUANTITE, quantite, DATE, date, -1);
        }
        
    }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        const char *titles[6] = {"Etablissement", "Service medicale", "Urgence",
                                  "Type de sang", "Quantité", "Date"};

        for (int i = 0; i < 6; ++i) {
            column = gtk_tree_view_column_new();
            renderer = gtk_cell_renderer_text_new();
            gtk_tree_view_column_pack_start(column, renderer, TRUE);
            gtk_tree_view_column_set_title(column, titles[i]);
            gtk_tree_view_column_add_attribute(column, renderer, "text", i);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
            gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
            gtk_tree_view_column_set_fixed_width(column, 200);
        }

        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}




void vider(GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    if (model != NULL) {
        GtkTreeStore *store = GTK_TREE_STORE(model);
        gtk_tree_store_clear(store);
    }
}






