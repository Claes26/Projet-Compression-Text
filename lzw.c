#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_comp_et_decomp.c"

FILE *fichier_entree;
FILE *fichier_sortie;

int main(int n, char** arg) {
    if (n > 2) {
        if (strcmp(arg[1], "c") == 0) { 
            fichier_entree = fopen(arg[2], "r");
            fichier_sortie = fopen(strcat(arg[2], ".lzw"), "w+b");            
            if (fichier_sortie == NULL || fichier_entree == NULL) {
                printf("ouverture impossible\n'"); return 0;
            }
            
            compression(fichier_entree, fichier_sortie);
        } else {
            fichier_entree = fopen(arg[2], "rb");
            char t[20]; int len = strlen(arg[2])-4;
            strncpy(t, arg[2], len);
            t[len] = '\0';
            fichier_sortie = fopen(t, "w");            
            if (fichier_sortie == NULL || fichier_entree == NULL) {
                printf("ouverture impossible\n'"); return 0;
            }
            
            decompression(fichier_entree, fichier_sortie);
        }
        
        fclose(fichier_entree); fclose(fichier_sortie);
    }    
    return 0;
}
