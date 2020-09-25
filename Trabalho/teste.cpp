#include <iostream>
#include <string>
#include <sstream>

using namespace std;

main()
{
    string data1 = "20200918", data2 = "20200919";

    int valor1, valor2;

    istringstream(data1) >> valor1;
    istringstream(data2) >> valor2;

    cout << valor2 - valor1 << endl;

    string line = "uanderson",
           comece = "";

    size_t pos = 0;

    cin >> comece;

    pos = line.find(comece);

    if (pos != line.npos)
    {
        cout << pos << endl;
    }
    else
    {
        cout << "derrota" << endl;
    }

    return 0;
}
