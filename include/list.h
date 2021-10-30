#ifndef H_BTREE
#define H_BTREE

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node ;

void ajouterNode(node **tree, unsigned int key);
int chercherNode(node *tree, unsigned int key);
void afficherTree(node *tree);
void afficherTreeInverse(node *tree);
void viderTree(node **tree);

void marquerVoisins(int **adjacence, int ordre, int s);

#endif //H_BTREE