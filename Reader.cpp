#include "Reader.h"

vector<DFA> Reader::read(string fileRoute)
{

    vector<DFA> cases;
    int numCases;

    ifstream file;
    string line;
    string word;

    try
    {
        file.open(fileRoute);

        if (!file)
        {
            throw "Could not open the file. Please check if the txt file exists.";
        }

        // Procces file

        // Number of cases
        if (getline(file, line))
        {
            numCases = stoi(line);
        }

        for (int i = 0; i < numCases; i++)
        {

            // set states
            getline(file, line);
            int numStates = stoi(line);
            vector<string> states;
            
            //     states.push_back(word);

            

            // set alphabet
            getline(file, line);
            vector<char> alphabet;
            istringstream iss3(line);
            word;
            while (iss3 >> word)
            {
                alphabet.push_back(word[0]);
            }


            // set finals
            getline(file, line);
            vector<string> finals;
            istringstream iss2(line);
            word;

            while (iss2 >> word)
            {
                finals.push_back(word);
            }



            // set transitions
            vector<tuple<string, string, string>> transitions;


            // loop for states
            for (int k = 0; k < numStates; k++)
            {

                // get the raw line and set it in a vector
                getline(file, line);
                vector<string> rawTransitions;
                istringstream iss4(line);
                word;
                while (iss4 >> word)
                {
                    rawTransitions.push_back(word);
                }

                //loop for alphabet
                for (int j = 0; j < alphabet.size(); j++)
                {   string s(1, alphabet[j]);
                    tuple<string, string, string> insert = make_tuple(rawTransitions[0], s, rawTransitions[j + 1]);
                    
                    transitions.push_back(insert);
                }
                states.push_back(rawTransitions[0]);

            }


            //Fill states


            DFA newDFA = DFA(states, finals, alphabet, transitions);
            cases.push_back(newDFA);
        }

        

        file.close();
    }
    catch (const char *errorMsg)
    {
        cerr << "Exception: " << errorMsg << endl;
    }
    catch (...)
    {
        cerr << "An unknown error occurred." << endl;
    }

    return cases;
}