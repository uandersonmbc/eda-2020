#ifndef AVL_NAME_H
#define AVL_NAME_H
#include "types.h"

struct NodeName;

void avl_search_todas_comece(NodeName *node, string name, vector<DataNameDate> *data);

int avl_name_balance(NodeName *node);
int avl_name_height(NodeName *node);

NodeName *avl_name_rightRotation(NodeName *node);
NodeName *avl_name_leftRotation(NodeName *node);
NodeName *avl_name_alocateNode(Data data, Node *avl_node);
NodeName *avl_name_fixup_node(NodeName *node, string name);

NodeName *avl_name_insert(NodeName *node, string name, Node *avl_node);

#endif
