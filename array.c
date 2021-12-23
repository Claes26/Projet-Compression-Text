typedef struct{
    int prefixe;
    int carac;
} x_dico;

void ajout_dico_array(int prefixe, int carac, int pos);
int prefixe_dico_array(int pos);
int carac_dico_array(int pos);

x_dico dico_array[4095];

void ajout_dico_array(int prefixe, int carac, int pos) {
    dico_array[pos].prefixe = prefixe;
    dico_array[pos].carac = carac;
}

int prefixe_dico_array(int pos) {
    return dico_array[pos].prefixe;
}

int carac_dico_array(int pos) {
    return dico_array[pos].carac;
}