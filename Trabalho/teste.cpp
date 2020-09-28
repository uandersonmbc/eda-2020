#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>
#include "avl_name.cpp"

using namespace std;

string addzero(string value)
{
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

main()
{
    string teste = "03";
    cout << addzero("003");
    return 0;
}
