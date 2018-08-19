#ifndef RESISTORLIST_H_INCLUDED
#define RESISTORLIST_H_INCLUDED
#include "Resistor.h"
#include <string>
#include <iostream>
using namespace std;

class Resistorhead
{
    private:
    Resistor* listhead;
    Resistor* listtail;
    public:
    Resistorhead();
    ~Resistorhead();
    void insertRe(Resistor* newR);
    void modifyRe(Resistor* newR);
    void modifyRe2(Resistor* newR);
    void printRe(Resistor* newR);
    bool deleteRe(Resistor* newR);
    bool deleteRe2(Resistor* newR);
    void deleteall();
    bool searchRe(Resistor* newR);
    void print();
    void printnode();
    void printallRe();
    double firstterm();
    Resistor* head();

};

#endif // RESISTORLIST_H_INCLUDED
