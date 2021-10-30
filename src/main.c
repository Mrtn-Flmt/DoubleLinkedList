#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

int main()
{
    int Key;
    node *Arbre = NULL;

    ajouterNode(&Arbre, 30);
    ajouterNode(&Arbre, 20);
    ajouterNode(&Arbre, 50);
    ajouterNode(&Arbre, 45);
    // can add more

    printf("------------tree-------------\n");
    afficherTree(Arbre);
    printf("--------tree inversé---------\n");
    afficherTreeInverse(Arbre);
    printf("-------------------------------\n");
    
    Key = 30;
    if(chercherNode(Arbre, Key)) { // Si le node est présent
        printf("La cle %d existe.\n", Key); // Afficher
    } else { 
        printf("La cle %d n'existe pas.\n", Key);
    }
    
    printf("-------------------------------\n");
    viderTree(&Arbre);
    return 0;
}