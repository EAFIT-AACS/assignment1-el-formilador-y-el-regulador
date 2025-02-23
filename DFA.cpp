#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class DFA {
    private:
        vector<string> states;
        vector<string> finals;
        vector<char> alphabet;
        vector<pair<string, string>> equivalentStates;
        
    
    public: 
        DFA(vector<string> q, vector<string> f, vector<char> sigma) {
            states = q;
            finals = f;
            alphabet = sigma;
        }
      
        
        /*
        void addState(string state) {
            states.push_back(state);
        }
        
        void addFinal(string final) {
            finals.push_back(final);
        }

        void addAlphabet(char letter) {
            alphabet.push_back(letter);
        } 
        */ 

        vector<string> getStates() {
            return states;
        }
        
        vector<string> getFinals() {
            return finals;
        }

        vector<char> getAlphabet() {
            return alphabet;
        }

        /*
        vector<string> getEquivalentStates() {
            return equivalentStates;
        }
        */

        void findEquivalentStates() {
            vector<string, string> statePairs;

            // Paso 0: Crear todas las parejas posibles entre estados
            for (auto iterador1 = states.begin(); iterador1 != states.end(); ++iterador1) {
                for (auto iterador2 = next(iterador1); iterador2 != states.end(); ++iterador2) {
                    if (find(finals.begin(), finals.end(), *iterador1) != finals.end() || 
                        find(finals.begin(), finals.end(), *iterador2) != finals.end()) {
                        continue;
                    }
                    statePairs.push_back(make_pair(*iterador1, *iterador2));
                }
            }

            // Paso 1: Eliminar de la vectora las parejas donde hay SOLO un estado final
            // Solucioado en el paso 0

            // Paso 2: Eliminar todas las parejas que nos lleven a una pareja marcada tras recibir alguna cadena
            
            // Paso 3: Repetir el Paso 2 hasta que no se marquen mas parejas

            // Paso 4: Llenar la vectora del atributo "equivalentStates" con las parejas no marcadas
        }
};