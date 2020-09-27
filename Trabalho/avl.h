#ifndef AVL_H
#define AVL_H
#include "types.h"

struct Node;

Node *avl_search_cpf(Node *node, string cpf);

int avl_balance(Node *node);
int avl_height(Node *node);
Node *avl_rightRotation(Node *node);
Node *avl_leftRotation(Node *node);
Node *avl_alocateNode(Data data);
Node *avl_fixup_node(Node *node, string cpf);

Node *avl_insert(Node *node, Data data);

#endif
