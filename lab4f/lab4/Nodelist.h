#ifndef NODELIST_H_INCLUDED
#define NODELIST_H_INCLUDED
#include "ResistorList.h"
#include "Resistor.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

class Nodehead
{
    private:
    Node* listhead;
    Node* listtail;

    public:
    Nodehead();
    void printallnode();
    void insertNo(Node* newN,Resistor* newR);
    void insertNo(Node* newN);
    void printNo(Node* newN);
    void deleteNo(Node* newN);
    void deleteallN();
    Node* searchNo(int ID);
    void print();
    bool nsetV(Node* newN);
    void unsetV(Node* newN);
    void solveV();
    void printV();
    void findresistor(Resistor* newR);
    void deleteresistor(Resistor* newR);
    //void printNo(Node* newN);
};

#endif // NODELIST_H_INCLUDED
