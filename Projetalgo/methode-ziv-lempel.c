#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ZivLempel(int argc, char * argv[])
{
    FILE* fichier = NULL;

    fichier = fopen("/home/etudiants/caronne2/Documents/Programmation et Algorithmique/Projetalgo/test.txt", "r");

    //if (fichier != NULL)
    //{
        // On peut lire et écrire dans le fichier
    //}
    //else
    //{
        // On affiche un message d'erreur si on veut
        //printf("Impossible d'ouvrir le fichier test.txt");
    //}

    argc--;   argv++;
    if ( argc == 0 ) {
    printf( "Usage: sample filename...\n" );
    exit( 0 );
    }
    fichier = fopen( "/home/etudiants/caronne2/Documents/Programmation et Algorithmique/Projetalgo/test.txt", "r" );
    if ( fichier == NULL ) {
    printf("Cannot open file %s\n", "/home/etudiants/caronne2/Documents/Programmation et Algorithmique/Projetalgo/test.txt");
    exit( 0 );
    }
    while ( ! feof( fichier ) ) {
    fputc( fgetc( fichier ), stdout );
    }

    fclose(fichier);
    return 0;
}
