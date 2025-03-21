#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "DFA.h"

using namespace std;

class Reader
{
public:
    // Function that reads the file
    static vector<DFA> read(string fileRoute);
};

#endif