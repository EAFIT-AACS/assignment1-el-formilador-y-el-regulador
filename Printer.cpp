#include "Printer.h"

void Printer::printDFA(DFA dfa)
{
    
    
    cout << "+" << string(20, '-') << "+\n";

    // Print the States
    cout << "| States: { ";
    for (int i = 0; i < dfa.getStates().size(); i++)
    {
        cout << dfa.getStates()[i] << " ";
    }
    cout << "}\n";

    cout << "+" << string(20, '-') << "+\n";

    // Print Final States
    cout << "| Final States: { ";
    for (int i = 0; i < dfa.getFinals().size(); i++)
    {
        cout << dfa.getFinals()[i] << " ";
    }
    cout << "}\n";

    cout << "+" << string(20, '-') << "+\n";

    // Print the Alphabet
    cout << "| Alphabet: { ";
    for (int i = 0; i < dfa.getAlphabet().size(); i++)
    {
        cout << dfa.getAlphabet()[i] << " ";
    }
    cout << "}\n";

    cout << "+" << string(20, '-') << "+\n";

    // Print the Transition Function
    cout << "| Transition Function: \n";
    for (int i = 0; i < dfa.getStates().size(); i++)
    {
        for (int j = 0; j < dfa.getAlphabet().size(); j++)
        {
            cout << "| " << dfa.getStates()[i] << " -> " << dfa.getAlphabet()[j] << " -> " << dfa.transitionFunction(dfa.getStates()[i], dfa.getAlphabet()[j]) << endl;
        }
    }

    cout << "+" << string(20, '-') << "+\n";

    // Print the Equivalent States
    dfa.getEquivalentStates();
}

void Printer::printBar()
{
    cout << endl << "--------------------------------"  << endl; 
}