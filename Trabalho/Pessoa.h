#ifndef PESSOA_H
#define PESSOA_H
#include "avl.cpp"
#include "avl_name.cpp"
#include "avl_date.cpp"

using namespace std;

class Pessoa
{
private:
    /* declarações de métodos e váriaveis privadas */
    Node *avl_data = NULL;
    NodeName *avl_data_name = NULL;
    NodeDate *avl_data_date = NULL;

    pair<string, string> par;
    Node *result;

    vector<string> split(string s, string delimiter);
    string addzero(string value);
    string format_date(string date, int format);
    void print_data(vector<Data> data, string initial);
    void print_data_name(vector<DataNameDate> data, string initial);

public:
    // declaração dos métodos público
    void insert_data(string file);
    void consulta_unica(string cpf);
    void consulta_todas_comece(string name);
    void consulta_periodo_data(string date_initial, string date_final);
};

// Private

vector<string> Pessoa::split(string s, string delimiter)
{

    // Função pora dividir os dados da linha do arquivo lido
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
    // Função para colocar 0 na frente se o valor for menor que 10
    int new_value;
    istringstream(value) >> new_value;
    stringstream ss;
    if (new_value < 10)
    {
        ss << "0" << new_value;
        return ss.str();
    }
    return value;
}

void Pessoa::print_data(vector<Data> data, string initial)
{
    cout << endl;

    // Criação da tabela de informações da pessoa

    cout << "Buscando pelo CPF [" << initial << "] " << endl;

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

void Pessoa::print_data_name(vector<DataNameDate> data, string initial)
{
    cout << endl;

    // Criação da tabela de informações da pessoa

    cout << initial << endl;

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

string Pessoa::format_date(string date, int format)
{
    vector<string> _format;
    stringstream ss;

    _format = split(date, "/");
    if (format == 1)
    {
        // padrão do americano
        ss << addzero(_format[2]) << addzero(_format[0]) << addzero(_format[1]);
        return ss.str();
    }
    else if (format == 2)
    {
        // padrão padrão brasileiro com barras
        ss << addzero(_format[1]) << "/" << addzero(_format[0]) << "/" << addzero(_format[2]);
        return ss.str();
    }
    else
    {
        // padrão padrão brasileiro sem barras
        ss << addzero(_format[2]) << addzero(_format[1]) << addzero(_format[0]);
        return ss.str();
    }
}

// Puclic

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
                data.birthday = format_date(data_local[3], 2);
                data.city = data_local[4];
                avl_data = avl_insert(avl_data, data);
                result = avl_search_cpf(avl_data, data_local[0]);
                par.first = data_local[1];
                par.second = data_local[0];
                avl_data_name = avl_name_insert(avl_data_name, par, result);
                par.first = format_date(data_local[3], 1);
                avl_data_date = avl_date_insert(avl_data_date, par, result);
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
    // padrão
    data.push_back(result->data);
    print_data(data, result->data.cpf);
}

void Pessoa::consulta_todas_comece(string name)
{
    vector<DataNameDate> data;
    // chamando a função de busca por string informada pelo usuário
    avl_search_todas_comece(avl_data_name, name, &data);
    stringstream ss;
    ss << "Foram encontrados " << data.size() << " pessoas que começam com [" << name << "]";
    print_data_name(data, ss.str());
}

void Pessoa::consulta_periodo_data(string date_inicial, string date_final)
{
    // declarando as várias locais da função
    vector<DataNameDate> data;
    stringstream ss;
    pair<string, string> dates;

    // criando o titulo da tabela
    ss << "Foram encontrados " << data.size() << " pessoas que estão entre esse período [" << date_inicial << " - " << date_final << "]";
    date_inicial = format_date(date_inicial, 3);
    date_final = format_date(date_final, 3);

    // verifica se as datas não foram colocadas invertidas
    if (date_inicial < date_final)
    {
        dates.first = date_inicial;
        dates.second = date_final;
    }
    else
    {
        dates.first = date_final;
        dates.second = date_inicial;
    }
    avl_search_periodo_data(avl_data_date, dates, &data);
    print_data_name(data, ss.str());
}

#endif
