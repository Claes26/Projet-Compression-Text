#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii()
{
    int n;
    int *ascii;                            // T pointeur sur des int
    scanf("%d",&n);
    ascii = (int*) malloc(n*sizeof(int));  // ou (int*) calloc(n, sizeof(int))
                                       // il faudrait tester si tout s'est bien passé T<>NULL
    int i;
    for(i=0;i<n;i++)
    {
        ascii[i]=i;
        if(i>256)
        {
            ascii[i]=0;
        }
        printf("%d - %c\n",i,ascii[i]);
    }
    free(ascii);                            // On libère l'espace utilisé par T lorsque T n'est plus utile




    return 0;
}
