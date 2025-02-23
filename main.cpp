#include <iostream>
using namespace std;

#include "DFA.h"
#include "Reader.h"

int main()
{

    // print beatifully interface in asscii

    // read file
    vector<DFA> cases = Reader::read("input.txt");

    cout << "Cases: " << cases.size() << endl;
    return 0;
}