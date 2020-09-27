#ifndef PESSOA_H
#define PESSOA_H
#include "avl.cpp"
#include "avl_name.cpp"
#include "avl_date.cpp"

using namespace std;

class Pessoa
{
private:
    /* data */
    Node *avl_data = NULL;
    NodeName *avl_data_name = NULL;
    NodeDate *avl_data_date = NULL;

    pair<string, string> par;
    Node *result;

    vector<string> split(string s, string delimiter);
    string addzero(string value);
    void print_data(vector<Data> data, string initial, int v);
    void print_data_name(vector<DataNameDate> data, string initial, int v);

public:
    // Pessoa();
    // ~Pessoa();

    void insert_data(string file);

    void consulta_unica(string cpf);
    void consulta_todas_comece(string name);
    void consulta_periodo_data(string date_initial, string date_final);
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

void Pessoa::print_data(vector<Data> data, string initial, int v)
{
    cout << endl;
    if (v == 1)
        cout << "Buscando pelo CPF [" << initial << "] " << endl;
    else if (v == 2)
        cout << "Pessoas que começam com [" << initial << "] " << endl;
    else
        cout << "Buscando pessoal por periódo de datas [" << initial << "] " << endl;

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "| CPF            | Nome       | Sobrenome  | Data de Nascimento | Cidade                    |" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    int total = data.size();
    for (int i = 0; i < total; i++)
    {
        printf("| %10s | %10s | %10s | %18s | %25s |", data[i].cpf.c_str(), data[i].name.c_str(), data[i].surname.c_str(), data[i].birthday.c_str(), data[i].city.c_str());
        cout << endl;
    }
    cout << "---------------------------------------------------------------------------------------------" << endl;
}

void Pessoa::print_data_name(vector<DataNameDate> data, string initial, int v)
{
    cout << endl;
    if (v == 1)
        cout << "Buscando pelo CPF [" << initial << "] " << endl;
    else if (v == 2)
        cout << "Pessoas que começam com [" << initial << "] " << endl;
    else
        cout << "Buscando pessoal por periódo de datas [" << initial << "] " << endl;

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "| CPF            | Nome       | Sobrenome  | Data de Nascimento | Cidade                    |" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    int total = data.size();
    for (int i = 0; i < total; i++)
    {
        printf("| %10s | %10s | %10s | %18s | %25s |", data[i].node->data.cpf.c_str(), data[i].node->data.name.c_str(), data[i].node->data.surname.c_str(), data[i].node->data.birthday.c_str(), data[i].node->data.city.c_str());
        cout << endl;
    }
    cout << "---------------------------------------------------------------------------------------------" << endl;
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
                result = avl_search_cpf(avl_data, data_local[0]);
                par.first = data_local[1];
                par.second = data_local[0];
                avl_data_name = avl_name_insert(avl_data_name, par, result);
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
    vector<Data> data;
    Node *result = avl_search_cpf(avl_data, cpf);
    data.push_back(result->data);
    print_data(data, result->data.cpf, 1);
}

void Pessoa::consulta_todas_comece(string name)
{
    vector<DataNameDate> data;
    avl_search_todas_comece(avl_data_name, name, &data);
    print_data_name(data, name, 2);
}

void Pessoa::consulta_periodo_data(string date_inicial, string date_final)
{
    cout << "Teste" << endl;
}

#endif
