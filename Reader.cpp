#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

#include "DFA.cpp"



class Reader {
    public:

        static vector<DFA> read(string fileRoute){
            
            vector<DFA> cases;  
            int numCases;

            ifstream file;
            string line;

            try {
                file.open(fileRoute);

                if (!file) {
                    throw "Could not open the file. Please check if the txt file exists.";
                }


                //Procces file

                //Number of cases
                if (getline(file, line)) {
                    numCases = stoi(line);
                }

                while (std::getline(file, line)) {
                    cout << line << endl;
                }

                file.close();
            } catch (const char* errorMsg) {
                cerr << "Exception: " << errorMsg << endl;
            } catch (...) {
                cerr << "An unknown error occurred." << endl;
            }



            return cases;
        }
};