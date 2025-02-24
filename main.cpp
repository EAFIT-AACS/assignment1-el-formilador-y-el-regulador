#include <iostream>
using namespace std;

#include "DFA.h"
#include "Reader.h"

int main()
{
    // Print beautiful interface in ascii
    cout << R"(
███████╗ ██████╗     ███████╗████████╗ █████╗ ████████╗███████╗███████╗
██╔════╝██╔═══██╗    ██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝██╔════╝██╔════╝
█████╗  ██║   ██║    ███████╗   ██║   ███████║   ██║   █████╗  ███████╗
██╔══╝  ██║▄▄ ██║    ╚════██║   ██║   ██╔══██║   ██║   ██╔══╝  ╚════██║
███████╗╚██████╔╝    ███████║   ██║   ██║  ██║   ██║   ███████╗███████║
╚══════╝ ╚══▀▀═╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚══════╝
            )" << std::endl;

    cout << "Welcome to the DFA Equivalence Checker" << endl << endl;

    // Read file
    vector<DFA> cases = Reader::read("input.txt");

    // Iterate over the cases
    for (int i = 0; i < cases.size(); i++)
    {
        cout << "Case " << i + 1 << endl;
        cases[i].findEquivalentStates();
        cases[i].getEquivalentStates();
        cout << endl;
    }

    return 0;
}