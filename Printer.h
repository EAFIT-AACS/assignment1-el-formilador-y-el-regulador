#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
#include "DFA.h"

using namespace std;

class Printer
{
public:
    static void printDFA(DFA dfa);
    static void printBar();
};

#endif