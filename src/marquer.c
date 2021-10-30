#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

void marquerVoisins(int **adjacence, int ordre, int s)
{
    int *marques;
    int x;
    int y;

    marques = malloc(sizeof(int) * s);

    for (x = 0; x < ordre; x++) { // initialisation des marques à 0
        marques[x] = 0;
    }
    marques[s] = 1; // init de la marques[s] à 1

    for (x = 0; x < ordre; x++) { 
        if (marques[x])
            for(y = 0; y < ordre; y++) {
                if (adjacence[x][y] && !marques[x]) {
                    marques[y] = 1;
                }
            }
    }
}