#include <stdio.h>
#include <string.h>

void enregistrer(int specialite, char *msg) {
    switch (specialite) {
        case 1:
            strcpy(msg, "informatique");
            break;
        case 2:
            strcpy(msg, "génie civile");
            break;
        case 3:
            strcpy(msg, "électromécanique");
            break;
        default:
            strcpy(msg, "Autre spécialité"); 
    }
}

