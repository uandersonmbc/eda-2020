#ifndef AVL_NAME_H
#define AVL_NAME_H
#include "types.h"

struct NodeDate;

void avl_search_periodo_data(NodeDate *node, pair<string, string> dates, vector<DataNameDate> *data);

int avl_date_balance(NodeDate *node);
int avl_date_height(NodeDate *node);

NodeDate *avl_date_rightRotation(NodeDate *node);
NodeDate *avl_date_leftRotation(NodeDate *node);
NodeDate *avl_date_alocateNode(Data data, Node *avl_node);
NodeDate *avl_date_fixup_node(NodeDate *node, string name);

NodeDate *avl_date_insert(NodeDate *node, string name, Node *avl_node);

#endif
