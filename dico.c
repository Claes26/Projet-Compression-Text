#include <stdio.h>
#include <stdlib.h>

enum {
    prefixe_init = -1 
};

struct noeud_dico {
    int pos;
    int prefixe;
    int carac;
    struct noeud_dico *next;
};

void initialisation_dico();
void ajout_noeud(struct noeud_dico *noeud);
void reset_dico();
int check_dico(int prefixe, int carac);
int prefixe_dico(int pos);
int carac_dico(int pos);
void ajout_dico(int prefixe, int carac, int pos);

struct noeud_dico *dico, *tail;

void initialisation_dico() {
    int k;
    struct noeud_dico *noeud;
    for (k = 0; k < 256; k++) {
        noeud = (struct noeud_dico *)malloc(sizeof(struct noeud_dico));
        noeud->prefixe = prefixe_init;
        noeud->carac = k;
        ajout_noeud(noeud);
    }       
}

void ajout_noeud(struct noeud_dico *noeud) {
    if (dico != NULL) {
        tail->next = noeud;
    }
    else {
        dico = noeud;
    }
    tail = noeud;
    noeud->next = NULL;
}

void reset_dico() {
    while (dico != NULL) {
        dico = dico->next;
    }
}

int check_dico(int prefixe, int carac) {
    struct noeud_dico *noeud;
    for (noeud = dico; noeud != NULL; noeud = noeud->next) {
        if (noeud->prefixe == prefixe && noeud->carac == carac) {
            return noeud->pos;
        }
    }
    return prefixe_init;
}

int prefixe_dico(int pos) {
    struct noeud_dico *noeud;
    for (noeud = dico; noeud != NULL; noeud = noeud->next) {
        if (noeud->pos == pos) {
            return noeud->prefixe;
        }
    }
    return -1;
}

int carac_dico(int pos) {
    struct noeud_dico *noeud;
    for (noeud = dico; noeud != NULL; noeud = noeud->next) {
        if (noeud->pos == pos) {
            return noeud->carac;
        }
    }
    return -1;
}

void ajout_dico(int prefixe, int carac, int pos) {
    struct noeud_dico *noeud;
    noeud = (struct noeud_dico *)malloc(sizeof(struct noeud_dico));
    noeud->pos = pos;
    noeud->prefixe = prefixe;
    noeud->carac = carac;
    ajout_noeud(noeud);
}
