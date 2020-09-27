#ifndef TYPES_H
#define TYPES_H
#include <string>
#include <vector>

using namespace std;

struct Node;
struct Data
{
    string cpf;
    string name;
    string surname;
    string birthday;
    string city;
};

struct DataNameDate
{
    pair<string, string> name;
    Node *node;
};

#endif