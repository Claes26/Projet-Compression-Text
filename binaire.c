#include <stdio.h>

void bin_ecrit(FILE * sortie, int code);
int bin_lit(FILE * entree);

int en_trop = 0;
int bit_en_trop;

void bin_ecrit(FILE * sortie, int code) {
    if (en_trop > 0) {
        int pre_code = (bit_en_trop << 4) + (code >> 8);
        fputc(pre_code, sortie);
        fputc(code, sortie);
        
        en_trop = 0;
    }
    else {
        bit_en_trop = code & 0xF;
        en_trop = 1;
        fputc(code >> 4, sortie);
    }
}

int bin_lit(FILE * entree) {
    int code = fgetc(entree);    
    if (code == EOF) {
        return 0;
    }

    if (en_trop > 0) {
        code = (bit_en_trop << 8) + code;
        
        en_trop = 0;
    }
    else {
        int post_code = fgetc(entree);
        
        bit_en_trop = post_code & 0xF;
        en_trop = 1;
        
        code = (code << 4) + (post_code >> 4);
    }
    return code;
}
