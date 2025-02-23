#include <iostream>
using namespace std;

#include "DFA.h"
#include "Reader.h"

int main()
{
    cout << "Welcome to the DFA Equivalence Checker" << endl;
    // print beatifully interface in asscii

    // read file
    vector<DFA> cases = Reader::read("input.txt");
    for (int i = 0; i < cases.size(); i++)
    {
        cout << "Case " << i + 1 << endl;
        cout << "States: ";
        cases[i].findEquivalentStates();
        cases[i].getEquivalentStates();
    }
    

    
    return 0;
}