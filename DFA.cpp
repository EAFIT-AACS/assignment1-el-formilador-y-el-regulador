#include <list>
#include <iostream>

using namespace std;

class DFA {
    private:
        list<string> states;
        list<string> finals;
        list<char> alphabet;
        list<string> equivalentStates;
    
    public:
        void setStates() {
            
        }

        void setFinals() {

        }

        void setAlphabet() {

        }

        void setEquivalentStates() {

        }
        
        list<string> getStates() {
            return states;
        }
        
        list<string> getFinals() {
            return finals;
        }

        list<char> getAlphabet() {
            return alphabet;
        }

        list<string> getEquivalentStates() {
            return equivalentStates;
        }
              
};