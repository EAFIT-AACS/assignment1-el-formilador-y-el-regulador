#include "DFA.h"

DFA::DFA(vector<string> q, vector<string> f, vector<char> sigma, vector<tuple<string, string, string>> phi)
{
    states = q;
    finals = f;
    alphabet = sigma;
    transition = phi;
}

vector<string> DFA::getStates()
{
    return states;
}

vector<string> DFA::getFinals()
{
    return finals;
}

vector<char> DFA::getAlphabet()
{
    return alphabet;
}

/*
vector<string> DFA::getEquivalentStates() {
    return equivalentStates;
}
*/

/*
vector<tuple<string, string, string>> DFA::getTransition() {
    return transition;
}
*/

void DFA::findEquivalentStates() 
{
    vector<pair<string, string>> statePairs;
    // Step 1: Create a vector filled with all the pairs that don't contain EXACTLY
    // one Acceptance State
    for (int i = 0; i < states.size(); i++)
    {
        for (int j = i + 1; j < states.size(); j++)
        {
            if (find(finals.begin(), finals.end(), states[i]) != finals.end() ||
                find(finals.begin(), finals.end(), states[j]) != finals.end())
            {
                continue;
            }
            statePairs.push_back(make_pair(states[i], states[j]));
        }
    }

    // Paso 2: Eliminar todas las parejas que nos lleven a una pareja marcada tras recibir alguna cadena
    vector<pair<string, string>> prevPairs = statePairs;

    // Tomar una pareja de 'statePairs', y eliminarla de prevPairs si, al aplicar la transicion, termina en alguna pareja que no este en
    // 'statePairs'
    do {
        statePairs = prevPairs;
        for (int i = 0; i < prevPairs.size(); i++) {
            for (int j = 0; j < alphabet.size(); j++) {
                if(find(prevPairs.begin(), prevPairs.end(), make_pair(transitionFunction(prevPairs[i].first, alphabet[j]), transitionFunction(prevPairs[i].second, alphabet[j]))) != prevPairs.end()) {
                    prevPairs.erase(prevPairs.begin() + i);
                }
            }
        }
    } while (prevPairs != statePairs);
    // Paso 3: Repetir el Paso 2 hasta que no se marquen mas parejas

    // Paso 4: Llenar el vector del atributo "equivalentStates" con las parejas no marcadas
}

string DFA::transitionFunction(string state, char symbol) {
    char transit;
    for (int i = 0; i < transition.size(); i++) {
        transit = get<1>(transition[i])[0];
        if (get<0>(transition[i]) == state && transit == symbol) {
            return get<2>(transition[i]);
        }
    }
}
