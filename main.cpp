#include <iostream>
using namespace std;

#include "DFA.h"
#include "Reader.h"
#include "Printer.h"
int main()
{

    cout << "Welcome to the DFA Equivalence Checker" << endl << endl;

    // Read file
    vector<DFA> cases = Reader::read("input.txt");

    // Print the DFA
    for (int i = 0; i < cases.size(); i++)
    {
        Printer::printBar();
        cout << endl << "Case" << i + 1 << endl;
        cases[i].findEquivalentStates();
        Printer::printDFA(cases[i]);
        Printer::printBar();

    }
    return 0;
}