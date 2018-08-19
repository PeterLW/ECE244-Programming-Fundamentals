#include "Node.h"
#include "Resistor.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Node::Node(){
    numRes=0;
    ifemp=true;
    }

Node::~Node(){}

bool Node::ifempty(){
return ifemp;
}

int Node::getNum(){
return numRes;
}
int Node::getID(int index){
return resIDArray[index];
}

bool Node::addResistor(int rIndex){
if(numRes<4){
        resIDArray[numRes]=rIndex;
        numRes++;
        //cout<<numRes<<endl;
        return true;}
else if(numRes==4){
        resIDArray[numRes]=rIndex;
        numRes++;
        //cout<<numRes<<endl;
        ifemp=false;
        return true;}
else{
    return false;
}
}


void Node::print(int nodeIndex){
cout<<"Connections at node "<<nodeIndex<<": "<<numRes<<" resistor(s)"<<endl;
}


//int main(){return 0;}
