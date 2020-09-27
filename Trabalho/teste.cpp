#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>
#include "avl_name.cpp"

using namespace std;

main()
{
    // string data1 = "20200918", data2 = "20200919";

    // int valor1, valor2;

    // istringstream(data1) >> valor1;
    // istringstream(data2) >> valor2;

    // cout << valor2 - valor1 << endl;

    // string line = "uanderson",
    //        comece = "";

    // size_t pos = 0;

    // cin >> comece;

    // pos = line.find(comece);

    // if (pos != line.npos)
    // {
    //     cout << pos << endl;
    // }
    // else
    // {
    //     cout << "derrota" << endl;
    // }

    // string name = "anderson", a = "andersonn";

    pair<string, string> par1, par2, par3, par4, par5;

    par1.first = "uanderson";
    par1.second = "123.456.789-10";

    par2.first = "Tiago";
    par2.second = "388.624.732-57";

    par3.first = "Tiago";
    par3.second = "880.249.282-48";

    par4.first = "Tiago";
    par4.second = "324.920.068-91";

    par5.first = "Tiago";
    par5.second = "783.748.506-80";

    // par2.first = "uanderson";
    // par2.second = "123";

    // // cout << name.substr(0, a.size()) << endl;

    // if (par2 < par1)
    // {
    //     cout << "Verdade";
    // }
    // else
    // {
    //     cout << "Falso";
    // }

    // char s[50];

    // istringstream(name) >> s;

    // // std::string data = "Abc";
    // std::transform(name.begin(), name.end(), name.begin(),
    //                [](unsigned char c) { return std::tolower(c); });

    // printf("%8s %8d %8d", name.c_str(), 20, 30);

    NodeName *teste = NULL;

    teste = avl_name_insert(teste, par1);
    teste = avl_name_insert(teste, par2);
    teste = avl_name_insert(teste, par3);
    teste = avl_name_insert(teste, par4);
    teste = avl_name_insert(teste, par5);

    cout << teste->data.name.first << " - " << teste->data.name.second << endl;
    cout << teste->right->data.name.first << " - " << teste->right->data.name.second << endl;

    cout << teste->left->data.name.first << " - " << teste->left->data.name.second << endl;
    cout << teste->left->left->data.name.first << " - " << teste->left->left->data.name.second << endl;
    cout << teste->left->right->data.name.first << " - " << teste->left->right->data.name.second << endl;

    vector<DataNameDate> data;
    avl_search_todas_comece(teste, "Tia", &data);

    cout << data.size() << endl;
    cout << data[0].name.second << endl;
    cout << data[1].name.second << endl;
    cout << data[2].name.second << endl;

    return 0;
}
