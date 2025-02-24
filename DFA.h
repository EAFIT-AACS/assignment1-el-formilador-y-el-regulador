#ifndef DFA_H
#define DFA_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class DFA
{
private:
    // Vector that contains all the states of the Automaton
    vector<string> states;

    // Vector that stores the Acceptance States of the Automaton
    vector<string> finals;

    // Vector filled with the characters that make up the alphabet
    vector<char> alphabet;

    // Vector made of pairs of states that are Equivalent
    vector<pair<string, string>> equivalentStates;

    // Tuple formed by State, String Processed, Arrival State
    vector<tuple<string, string, string>> transition;

public:
    // Constructor
    DFA(vector<string> q, vector<string> f, vector<char> sigma, vector<tuple<string, string, string>> phi);

    // Getters for each of the attributes
    vector<string> getStates();
    vector<string> getFinals();
    vector<char> getAlphabet();
    void getEquivalentStates();

    // Function to check for Equivalence between two states and store them on the respective attribute
    void findEquivalentStates();
    string transitionFunction(string state, char symbol);
};

#endif