#ifndef AVL_H
#define AVL_H
#include "types.h"

struct Node;

Node *avl_search_cpf(Node *node, string cpf);
void avl_search_todas_comece(Node *node, string name, vector<Data> *data);
// Node *avl_search_period(Node *node, string date_inicial, string date_final);

int balance(Node *node);
int avl_height(Node *node);
Node *rightRotation(Node *node);
Node *leftRotation(Node *node);
Node *alocateNode(Data data);
Node *fixup_node(Node *node, string cpf);

Node *avl_insert(Node *node, Data data);

#endif
