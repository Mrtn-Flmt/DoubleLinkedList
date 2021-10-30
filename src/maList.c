#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

void ajouterNode(node **tree, unsigned int key)
{
    // init
    node *tmpNode;
    node *tmpTree = *tree;
    node *elem = malloc(sizeof(node));
    
    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if (tmpTree) {
        do { // tant qu'il y a des tree à ajouter
            tmpNode = tmpTree;
            if (key > tmpTree->key) { // Si la valeur de la nouvelle clée est suppérieur à la valeur de clée de l'abre
                tmpTree = tmpTree->right; // ajouter dans la branche droite
                if (!tmpTree) // allocation mémoire node
                    tmpNode->right = elem;
            } else { // Si la valeur de la nouvelle clée est suppérieur à la valeur de clée de l'abre
                tmpTree = tmpTree->left; // // ajouter dans la branche gauche
                if (!tmpTree) tmpNode->left = elem;
            }
        } while (tmpTree);
    } else { 
        *tree = elem;
    }
}

int chercherNode(node *tree, unsigned int key)
{
    while (tree) // Parcourir le tree
    {
        if (key == tree->key) // Si la clée correspond: return 1
            return 1;
        if (key > tree->key) { // Si la clée est suppérieur à la clée de l'arbre: go sur la branche de droite 
            tree = tree->right;
        } else { // Si la clée est inférieur à la clée de l'arbre: go sur la branche de gauche
            tree = tree->left;
        }
    }
    return 0;
}

void afficherTree(node *tree)
{
    if (!tree) // Si c'est la fin du tree: return
        return;
    if (tree->left) // Si c'est la branche de gauche: afficher arbre branche gauche
        afficherTree(tree->left);
    printf("Cle = %d\n", tree->key);
    if (tree->right) // Si c'est la branche de droite: afficher arbre branche droit
        afficherTree(tree->right);
}

void afficherTreeInverse(node *tree)
{
    if (!tree) // Si c'est la fin du tree: return
        return;
    if (tree->right) // Si c'est la branche de gauche: afficher arbre branche gauche
        afficherTreeInverse(tree->right);
    printf("Cle = %d\n", tree->key);
    if (tree->left) // Si c'est la branche de droite: afficher arbre branche droit
        afficherTreeInverse(tree->left);
}

void viderTree(node **tree)
{
    node *tmpTree = *tree;
    if (!tree) // Si le tree est vide return
        return;
    if (tmpTree->left) // vider la branche de gauche
        viderTree(&tmpTree->left);
    if (tmpTree->right) // vider la branche de droite
        viderTree(&tmpTree->right);
    free(tmpTree);
    *tree = NULL;
}