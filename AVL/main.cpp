#include <iostream>
#include <sstream>

using namespace std;

void menu(){
    cout << "---------------------------" << endl;
    cout << "Implementação da Árvore AVL" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Inserir elemento na árvore" << endl;
    cout << "2. Percurso em pre-ordem" << endl;
    cout << "3. Percurso em in-ordem" << endl;
    cout << "4. Percurso em pos-ordem" << endl;
    cout << "5. Altura da árvore" << endl;
    cout << "6. Número de folhas da árvore" << endl;
    cout << "7. Valor máximo e minimo da árvore" << endl;
    cout << "8. Sair" << endl;
}

int main(){
    
    menu();

    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ui(line);
        ui >> cmd;
        if(cmd == "1"){
        }else if(cmd == "2"){
        }else if(cmd == "3"){
        }else if(cmd == "4"){
        }else if(cmd == "5"){
        }else if(cmd == "6"){
        }else if(cmd == "7"){
        }else if(cmd == "8"){
            break;
        }else{
            cout << "Comando inválido, digit apenas o número de referencia da ação ." << endl;
        }
    }
}

