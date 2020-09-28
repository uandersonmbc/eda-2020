#include <iostream>
#include <cstddef>
#include <queue>
#include <algorithm>
#include <cctype>
#include "avl.h"
#include "types.h"

struct NodeDate
{
    DataNameDate data;
    int height;
    NodeDate *left;
    NodeDate *right;
};

void avl_search_periodo_data(NodeDate *node, pair<string, string> dates, vector<DataNameDate> *data)
{

    if (node == NULL)
        return;
    if (dates.second < node->data.name.first)
        avl_search_periodo_data(node->left, dates, data);
    else if (dates.first > node->data.name.first)
        avl_search_periodo_data(node->right, dates, data);
    else
    {
        avl_search_periodo_data(node->left, dates, data);
        avl_search_periodo_data(node->right, dates, data);
    }

    string date = node->data.name.first;

    if (dates.first <= date && dates.second >= date)
    {
        // cout << dates.first << " - " << dates.second << " - " << date << endl;
        (*data).push_back(node->data);
    }
}

int avl_date_height(NodeDate *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int avl_date_balance(NodeDate *node)
{
    if (node == NULL)
        return 0;
    return avl_date_height(node->right) - avl_date_height(node->left);
}

NodeDate *avl_date_alocateNode(pair<string, string> name, Node *avl_node)
{ //Aloca um nó
    NodeDate *node = new NodeDate;
    node->data.name = name;
    node->data.node = avl_node;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

NodeDate *avl_date_rightRotation(NodeDate *node)
{ //Rotação Direita
    NodeDate *u = node->left;
    node->left = u->right;
    u->right = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_date_height(node->left), avl_date_height(node->right));
    u->height = 1 + max(avl_date_height(u->left),
                        avl_date_height(u->right));

    return u; // nova raiz
}

NodeDate *avl_date_leftRotation(NodeDate *node)
{ //Rotação Esquerda
    NodeDate *u = node->right;
    node->right = u->left;
    u->left = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_date_height(node->left),
                           avl_date_height(node->right));
    u->height = 1 + max(avl_date_height(u->left),
                        avl_date_height(u->right));

    return u; // nova raiz
}

NodeDate *avl_date_fixup_node(NodeDate *node, pair<string, string> name)
{
    int bal = avl_date_balance(node); //obtem balanco de node

    if (bal < -1 && name < node->left->data.name)
        return avl_date_rightRotation(node);
    else if (bal < -1 && name > node->left->data.name)
    {
        node->left = avl_date_leftRotation(node->left);
        return avl_date_rightRotation(node);
    }
    else if (bal > 1 && name > node->right->data.name)
        return avl_date_leftRotation(node);
    else if (bal > 1 && name < node->right->data.name)
    {
        node->right = avl_date_rightRotation(node->right);
        return avl_date_leftRotation(node);
    }
    return node;
}

NodeDate *avl_date_insert(NodeDate *node, pair<string, string> name, Node *avl_node)
{
    if (node == NULL)
        return avl_date_alocateNode(name, avl_node);
    if (name < node->data.name)
        node->left = avl_date_insert(node->left, name, avl_node);
    else if (name > node->data.name)
        node->right = avl_date_insert(node->right, name, avl_node);
    else
        return node; //nao permite chaves repetidas

    //atualiza altura deste ancestral p
    node->height = 1 + std::max(avl_date_height(node->left), avl_date_height(node->right));
    node = avl_date_fixup_node(node, name); //Regula o no
    return node;
}