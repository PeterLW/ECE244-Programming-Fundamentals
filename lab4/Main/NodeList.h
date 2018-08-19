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
    void insertNo(int,int,string,double,int,int);
    void insertNo2(Node* newN);
    void printNo(int);
    void deleteNo(string);
    void deleteallN();
    Node* searchNo(int ID);
    void print();
    bool nsetV(int,double);
    void unsetV(int);
    void solveV();
    void printV();
    void findresistor(string,double);
    void deleteresistor(string);
    Node* head();
    void freeN(Node*);
    void freeR(Resistor*);
};

#endif // NODELIST_H_INCLUDED
