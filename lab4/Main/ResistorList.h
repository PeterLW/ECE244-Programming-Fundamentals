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
    bool insertRe(int rIndex_,string name_,double resistance_,int endpoints0,int endpoints1);
    void modifyRe(string,double);
    void modifyRe2(string,double);
    void printRe(string);
    bool deleteRe(string);

    void deleteall();
    bool searchRe(Resistor* newR);
    void print();
    void printnode();
    void printallRe();
    void printallReforN();
    double firstterm();
    Resistor* head();

};

#endif // RESISTORLIST_H_INCLUDED
