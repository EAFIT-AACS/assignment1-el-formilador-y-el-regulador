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

void DFA::getEquivalentStates()
{
    cout << "Equivalent States: " << endl;
    for (int i = 0; i < equivalentStates.size(); i++)
    {
        cout << "( " + equivalentStates[i].first + ", " + equivalentStates[i].second + " )" << endl;
    }
}

void DFA::findEquivalentStates()
{
    vector<pair<string, string>> statePairs;
    // Step 1: Create a vector filled with all the pairs that don't contain EXACTLY
    // one Acceptance State. Both are final or both are not final
    for (int i = 0; i < states.size(); i++)
    {
        for (int j = i + 1; j < states.size(); j++)
        {
            if (find(finals.begin(), finals.end(), states[i]) != finals.end() ^
                find(finals.begin(), finals.end(), states[j]) != finals.end())
            {
                continue;
            }
            statePairs.push_back(make_pair(states[i], states[j]));
        }
    }

    // Step 2: Erase all the pairs that transition into another pair that isn't included
    // into the vector 'statePairs'
    vector<pair<string, string>> prevPairs = statePairs;

    pair<string, string> pairToDisect;

    // This is done with a 'do-while' loop, that uses another vector called 'prevPairs'
    // to store and modify the previous state of the vector 'statePairs'
    do
    {
        statePairs = prevPairs;
        for (int i = 0; i < prevPairs.size(); i++)
        {

            bool destroy = false;
            for (int j = 0; j < alphabet.size(); j++)
            {
                pairToDisect = make_pair(transitionFunction(prevPairs[i].first, alphabet[j]), transitionFunction(prevPairs[i].second, alphabet[j]));
                if ((find(prevPairs.begin(), prevPairs.end(), pairToDisect) == prevPairs.end()))
                {

                    destroy = true;

                    if ((find(prevPairs.begin(), prevPairs.end(), make_pair(pairToDisect.second, pairToDisect.first)) != prevPairs.end()))
                    {
                        destroy = false;
                    }

                    if (pairToDisect.first == pairToDisect.second)
                    {
                        destroy = false;
                    }
                }
            }
            if (destroy)
            {
                prevPairs.erase(prevPairs.begin() + i);
                --i;
            }
        }
    } while (prevPairs != statePairs);

    // The loop will keep going as long as 'prevPairs' and 'statePairs' are different

    // Step 3: Insert the remaining pairs into the attribute 'equivalentStates'
    equivalentStates = statePairs;
}

string DFA::transitionFunction(string state, char symbol)
{
    char transit;
    for (int i = 0; i < transition.size(); i++)
    {
        transit = get<1>(transition[i])[0];
        if (get<0>(transition[i]) == state && transit == symbol)
        {
            string newState = get<2>(transition[i]);
            return newState;
        }
    }
    return "Error";
}
