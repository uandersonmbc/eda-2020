
#ifndef PESSOA_H
#define PESSOA_H
#include "avl.cpp"

using namespace std;

class Pessoa
{
private:
    /* data */
    Node *avl_data = NULL;
    vector<string> split(string s, string delimiter);
    string addzero(string value);

public:
    // Pessoa();
    // ~Pessoa();

    void insert_data(string file);

    void consulta_unica(string cpf);
    void consulta_todas_comece(string name);
    // void consulta_periodo_data();
};

vector<string> Pessoa::split(string s, string delimiter)
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

string Pessoa::addzero(string value)
{
    int new_value;
    istringstream(value) >> new_value;
    if (new_value < 10)
    {
        return "0" + value;
    }
    return value;
}

void Pessoa::insert_data(string file)
{
    cout << "Carregando os dados" << endl;
    Data data;
    string line, date1;
    int linha = 0;
    vector<string> date;

    vector<string> data_local;
    // abre o aquivo
    ifstream myfile(file);

    // verifica se o arquivo está aberto
    if (myfile.is_open())
    {
        // vai lendo linha por linha do arquivo que foi aberto
        while (getline(myfile, line))
        {
            // verifica se é a primeira linha do arquivo
            if (linha)
            {
                // chama a função teste e add o valor retornado para a variavel dados
                data_local = split(line, ",");
                data.cpf = data_local[0];
                data.name = data_local[1];
                data.surname = data_local[2];
                data.birthday = data_local[3];
                data.city = data_local[4];
                avl_data = avl_insert(avl_data, data);
            }
            linha++;
        }

        // fecha o arquivo que foi aberto
        myfile.close();
    }
    cout << linha << " dados foram Inseridos" << endl;
}

void Pessoa::consulta_unica(string cpf)
{
    Node *result = avl_search_cpf(avl_data, cpf);

    cout << "Nome: " << result->data.name << endl;
}

void Pessoa::consulta_todas_comece(string name)
{
    vector<Data> data;
    avl_search_todas_comece(avl_data, name, data);

    cout << data.size() << endl;
}

// Pessoa::consulta_periodo_data(string data1, string data2)
// {
// }

#endif
