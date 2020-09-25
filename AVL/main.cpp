#include <iostream>
#include <sstream>
#include "avl.h"
#include "avl.cpp"

using namespace std;

void menu()
{
    cout << "----------------------------------" << endl;
    cout << "MENU : Implementacao da Arvore AVL" << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Inserir elemento na arvore" << endl;
    cout << "2. Percurso em pre-ordem" << endl;
    cout << "3. Percurso em in-ordem" << endl;
    cout << "4. Percurso em pos-ordem" << endl;
    cout << "5. Altura da arvore" << endl;
    cout << "6. Buscar" << endl;
    cout << "7. Apagar todos" << endl;
    cout << "8. Sair" << endl;
}

int main()
{
    Node *avl1 = NULL;
    Node *avl2 = NULL;
    string key, value;
    menu();

    while (true)
    {
        cout << "Escolha uma das opcoes listada no menu: ";
        string cmd;
        cin >> cmd;

        if (cmd == "1")
        {
            cout << "Digite a key: ";
            cin >> key;
            cout << "Digite o value: ";
            cin >> value;
            avl1 = avl_insert(avl1, key, value);
        }
        else if (cmd == "2")
        {
            cout << "Pre-ordem: " << endl;
            avl_preorder(avl1);
        }
        else if (cmd == "3")
        {
            cout << "In-ordem: " << endl;
            avl_inorder(avl1);
        }
        else if (cmd == "4")
        {
            cout << "Pos-ordem: " << endl;
            avl_posorder(avl1);
        }
        else if (cmd == "5")
        {
            cout << "A altura da árvore: " << avl_height(avl1) << endl;
        }
        else if (cmd == "6")
        {
            cout << "Digite a chave desejada: ";
            cin >> key;
            Node *a = avl_search(avl1, key);
            cout << "Key: " + a->key << " Value: " + a->value << endl;
        }
        else if (cmd == "7")
        {
            avl1 = avl_clear(avl1);
            cout << "Limpeza de arvore concluida" << endl;
        }
        else if (cmd == "8")
        {
            break;
        }
        else
        {
            cout << "Comando invalido, digit apenas o numero de referencia da acao." << endl;
        }
    }
}
