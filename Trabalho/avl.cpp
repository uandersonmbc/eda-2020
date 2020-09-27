#include <iostream>
#include <cstddef>
#include <queue>
#include <algorithm>
#include <cctype>
#include "avl.h"
#include "types.h"
// #include "avl_name.h"

struct Node
{
    Data data;
    int height;
    Node *left;
    Node *right;
};

Node *avl_search_cpf(Node *node, string cpf)
{
    if (node == NULL)
        return NULL;
    if (cpf < node->data.cpf)
        return avl_search_cpf(node->left, cpf);
    else if (cpf > node->data.cpf)
        return avl_search_cpf(node->right, cpf);
    else
        return node;
}

int avl_balance(Node *node)
{
    if (node == NULL)
        return 0;
    return avl_height(node->right) - avl_height(node->left);
}

int avl_height(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

Node *avl_alocateNode(Data data)
{ //Aloca um nó
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node *avl_rightRotation(Node *node)
{ //Rotação Direita
    Node *u = node->left;
    node->left = u->right;
    u->right = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_height(node->left), avl_height(node->right));
    u->height = 1 + max(avl_height(u->left),
                        avl_height(u->right));

    return u; // nova raiz
}

Node *avl_leftRotation(Node *node)
{ //Rotação Esquerda
    Node *u = node->right;
    node->right = u->left;
    u->left = node;
    // atualiza alturas dos nós
    node->height = 1 + max(avl_height(node->left),
                           avl_height(node->right));
    u->height = 1 + max(avl_height(u->left),
                        avl_height(u->right));

    return u; // nova raiz
}

Node *avl_fixup_node(Node *node, string cpf)
{
    int bal = avl_balance(node); //obtem balanco de node

    if (bal < -1 && cpf < node->left->data.cpf)
        return avl_rightRotation(node);
    else if (bal < -1 && cpf > node->left->data.cpf)
    {
        node->left = avl_leftRotation(node->left);
        return avl_rightRotation(node);
    }
    else if (bal > 1 && cpf > node->right->data.cpf)
        return avl_leftRotation(node);
    else if (bal > 1 && cpf < node->right->data.cpf)
    {
        node->right = avl_rightRotation(node->right);
        return avl_leftRotation(node);
    }
    return node;
}

Node *avl_insert(Node *node, Data data)
{
    if (node == NULL)
        return avl_alocateNode(data);
    if (data.cpf < node->data.cpf)
        node->left = avl_insert(node->left, data);
    else if (data.cpf > node->data.cpf)
        node->right = avl_insert(node->right, data);
    else
        return node; //nao permite chaves repetidas

    //atualiza altura deste ancestral p
    node->height = 1 + std::max(avl_height(node->left), avl_height(node->right));
    node = avl_fixup_node(node, data.cpf); //Regula o no
    return node;
}