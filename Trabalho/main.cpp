#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>
#include <sstream>

#include "Pessoa.h"

using namespace std;

void menu()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "MENU:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "[1] - Consultar por CPF" << endl;
    cout << "[2] - Consultar por cadeias de caracteres" << endl;
    cout << "[3] - Consultar por periodo de datas" << endl;
    cout << "[4] - Sair" << endl;
    cout << endl;
    cout << "Sempre que for usar alguma ação lembre de seguir esse template" << endl;
    cout << "Template para 1 e 2 ----- [COMANDO] [DADOS DE ENTRADA]" << endl;
    cout << "Template para o 3 ------- [COMANDO] [YYYY/MM/DD] [YYYY/MM/DD]" << endl;
    cout << "Template para o 4 ------- [COMANDO]" << endl;
}

vector<string> split(string s, string delimiter)
{
    vector<string> tokens;

    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos)
    {
        // pega a substring da string S, usando o delimitador que é uma vírgula.
        token = s.substr(0, pos);
        // add o valor da substring no vetor de strings T
        tokens.push_back(token);
        // retira a substring que foi add no vetor de strings T
        s.erase(0, pos + delimiter.length());
    }
    // add a ultima substring da string S no vetor T
    tokens.push_back(s);

    // retorna o valor do vetor
    return tokens;
}

string addzero(string value)
{
    int new_value;
    istringstream(value) >> new_value;
    if (new_value < 10)
    {
        return "0" + value;
    }
    return value;
}

int main()
{
    Pessoa pessoa;

    // passe o nome do arquivo como parametro
    pessoa.insert_data("data.csv");

    menu();

    while (true)
    {
        string line, date1, date2, value;
        int cmd;
        getline(cin, line);
        stringstream ui(line);
        ui >> cmd;
        if (cmd == 1)
        {
            ui >> value;
            pessoa.consulta_unica(value);
        }
        else if (cmd == 2)
        {
            ui >> value;
            pessoa.consulta_todas_comece(value);
        }
        else if (cmd == 3)
        {
            ui >> date1;
            ui >> date2;
            cout << "comando -> " << date1 << " - " << date2 << endl;
        }
        else if (cmd == 4)
        {
            break;
        }
        else
        {
            cout << "Comando inválido" << endl;
        }
    }

    return 0;
}