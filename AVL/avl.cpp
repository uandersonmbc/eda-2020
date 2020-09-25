#include <iostream>
#include <cstddef>
#include <queue>
#include "avl.h"
#include "item.h"
using std::cout;
using std::endl;
using std::max;

struct Node
{
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

Tkey avl_getKey(Node *node)
{
    return node->key;
}

Tvalue avl_getValue(Node *node)
{
    return node->value;
}

Node *avl_search(Node *node, Tkey key)
{
    if (node == NULL)
        return NULL;
    if (key < node->key)
        return avl_search(node->left, key);
    else if (key > node->key)
        return avl_search(node->right, key);
    else
        return node;
}

void avl_preorder(Node *node)
{
    if (node != NULL)
    {
        cout << "(" << node->key << ", " << node->value << ")" << endl;
        avl_preorder(node->left);
        avl_preorder(node->right);
    }
}

void avl_inorder(Node *node)
{
    if (node != NULL)
    {
        avl_inorder(node->left);
        cout << "(" << node->key << ", " << node->value << ")" << endl;
        avl_inorder(node->right);
    }
}

void avl_posorder(Node *node)
{
    if (node != NULL)
    {
        avl_posorder(node->left);
        avl_posorder(node->right);
        cout << "(" << node->key << ", " << node->value << ")" << endl;
    }
}

int avl_height(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int avl_size(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + avl_size(node->left) +
               avl_size(node->right);
}

int balance(Node *node)
{
    if (node == NULL)
        return 0;
    return avl_height(node->right) - avl_height(node->left);
}

bool avl_empty(Node *node)
{ //Verifica se a árvore está vazia.
    return (node == NULL);
}

Node *avl_clear(Node *node)
{
    if (node != NULL)
    {
        node->left = avl_clear(node->left);
        node->right = avl_clear(node->right);
        cout << "Removendo Key: " << node->key << endl;
        delete node;
    }
    return NULL;
}

Node *rightRotation(Node *node)
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

Node *leftRotation(Node *node)
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

Node *alocateNode(Tkey key, Tvalue value)
{ //Aloca um nó
    Node *node = new Node;
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *fixup_node(Node *node, Tkey key)
{
    int bal = balance(node); //obtem balanco de node

    if (bal < -1 && key < node->left->key)
        return rightRotation(node);
    else if (bal < -1 && key > node->left->key)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    else if (bal > 1 && key > node->right->key)
        return leftRotation(node);
    else if (bal > 1 && key < node->right->key)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

Node *avl_insert(Node *node, Tkey key, Tvalue value)
{
    if (node == NULL)
        return alocateNode(key, value);
    if (key < node->key)
        node->left = avl_insert(node->left, key, value);
    else if (key > node->key)
        node->right = avl_insert(node->right, key, value);
    else
        return node; //nao permite chaves repetidas

    //atualiza altura deste ancestral p
    node->height = 1 + std::max(avl_height(node->left), avl_height(node->right));
    node = fixup_node(node, key); //Regula o no
    return node;
}

Node *delete_all(Node *node)
{
    if (node == NULL)
        return NULL; //verifica se não é nulo
    if (node->left == NULL && node->right == NULL)
    { //verifica se ele é apenas uma folha
        delete node;
        return NULL;
    }
    delete_all(node->left);  //delete o lado esquerdo dele
    delete_all(node->right); //delete o lado direito dele
    delete node;             //deleta ele agora já que é uma folha
    return NULL;
}