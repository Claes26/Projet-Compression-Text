#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.c"
#include "binaire.c"
#include "array.c"

enum {
    taille_dico = 4095,
    len_code = 12,
    max = taille_dico - 1
};

void compression(FILE *fichier_entree, FILE *fichier_sortie);
void decompression(FILE *fichier_entree, FILE *fichier_sortie);
int decode(int code, FILE * fichier_sortie);

// compression
void compression(FILE *fichier_entree, FILE *fichier_sortie) {    
    int prefixe = getc(fichier_entree);
    if (prefixe == EOF) {
        return;
    }
    int carac;
    int post_code;
    int index;
    
    post_code = 256;
    initialisation_dico();
    
    while ((carac = getc(fichier_entree)) != (unsigned)EOF) {        
        if ((index = check_dico(prefixe, carac)) != -1) {
            prefixe = index;
        }
        else {
            bin_ecrit(fichier_sortie, prefixe);
            if (post_code < taille_dico) {
                ajout_dico(prefixe, carac, post_code++);
            }
            prefixe = carac;
        }
    }
    bin_ecrit(fichier_sortie, prefixe);
    
    if (en_trop > 0) {
        fputc(bit_en_trop << 4, fichier_sortie);
    }
    reset_dico();
}

void decompression(FILE * fichier_entree, FILE * fichier_sortie) {
    int pre_code; int act_code;
    int post_code = 256;
    int prem_carac;
    
    pre_code = bin_lit(fichier_entree);
    if (pre_code == 0) {
        return;
    }
    fputc(pre_code, fichier_sortie);
    
    while ((act_code = bin_lit(fichier_entree)) > 0) {
    
        if (act_code >= post_code) {
            fputc(prem_carac = decode(pre_code, fichier_sortie), fichier_sortie);
        } else prem_carac = decode(act_code, fichier_sortie);
        
        if (post_code < taille_dico) {
            ajout_dico_array(pre_code, prem_carac, post_code++);
        }
        pre_code = act_code;
    }
}

int decode(int code, FILE * fichier_sortie) {
    int carac; int t;

    if (code > 255) {
        carac = carac_dico_array(code);
        t = decode(prefixe_dico_array(code), fichier_sortie);
    } else {
        carac = code;
        t = code;
    }
    fputc(carac, fichier_sortie);
    return t;
}