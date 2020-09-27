#include <iostream>
#include <cstddef>
#include <queue>
#include <algorithm>
#include <cctype>
#include "avl.h"
#include "types.h"

struct NodeName
{
    DataNameDate data;
    int height;
    NodeName *left;
    NodeName *right;
};

void avl_search_todas_comece(NodeName *node, string name, vector<DataNameDate> *data)
{

    if (node == NULL)
        return;

    size_t pos = 0;
    string name_local = name, data_name = node->data.name.first;
    std::transform(name_local.begin(), name_local.end(), name_local.begin(), [](unsigned char c) { return std::tolower(c); });
    std::transform(data_name.begin(), data_name.end(), data_name.begin(), [](unsigned char c) { return std::tolower(c); });

    if (name_local < data_name.substr(0, name_local.size()))
        avl_search_todas_comece(node->left, name_local, data);
    else if (name_local > data_name.substr(0, name_local.size()))
        avl_search_todas_comece(node->right, name_local, data);
    else
    {
        avl_search_todas_comece(node->left, name, data);
        avl_search_todas_comece(node->right, name, data);
    }

    pos = data_name.find(name_local);

    if (pos != data_name.npos && pos == 0)
    {
        (*data).push_back(node->data);
    }
}

int avl_name_height(NodeName *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int avl_name_balance(NodeName *node)
{
    if (node == NULL)
        return 0;
    return avl_name_height(node->right) - avl_name_height(node->left);
}

NodeName *avl_name_alocateNode(pair<string, string> name, Node *avl_node)
{ //Aloca um nó
    NodeName *node = new NodeName;
    node->data.name = name;
    node->data.node = avl_node;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

NodeName *avl_name_rightRotation(NodeName *node)
{ //Rotação Direita
    NodeName *u = node->left;
    node->left = u->right;
    u->right = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_name_height(node->left), avl_name_height(node->right));
    u->height = 1 + max(avl_name_height(u->left),
                        avl_name_height(u->right));

    return u; // nova raiz
}

NodeName *avl_name_leftRotation(NodeName *node)
{ //Rotação Esquerda
    NodeName *u = node->right;
    node->right = u->left;
    u->left = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_name_height(node->left),
                           avl_name_height(node->right));
    u->height = 1 + max(avl_name_height(u->left),
                        avl_name_height(u->right));

    return u; // nova raiz
}

NodeName *avl_name_fixup_node(NodeName *node, pair<string, string> name)
{
    int bal = avl_name_balance(node); //obtem balanco de node

    if (bal < -1 && name < node->left->data.name)
        return avl_name_rightRotation(node);
    else if (bal < -1 && name > node->left->data.name)
    {
        node->left = avl_name_leftRotation(node->left);
        return avl_name_rightRotation(node);
    }
    else if (bal > 1 && name > node->right->data.name)
        return avl_name_leftRotation(node);
    else if (bal > 1 && name < node->right->data.name)
    {
        node->right = avl_name_rightRotation(node->right);
        return avl_name_leftRotation(node);
    }
    return node;
}

NodeName *avl_name_insert(NodeName *node, pair<string, string> name, Node *avl_node)
{
    if (node == NULL)
        return avl_name_alocateNode(name, avl_node);
    if (name < node->data.name)
        node->left = avl_name_insert(node->left, name, avl_node);
    else if (name > node->data.name)
        node->right = avl_name_insert(node->right, name, avl_node);
    else
        return node; //nao permite chaves repetidas

    //atualiza altura deste ancestral p
    node->height = 1 + std::max(avl_name_height(node->left), avl_name_height(node->right));
    node = avl_name_fixup_node(node, name); //Regula o no
    return node;
}