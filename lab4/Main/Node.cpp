#include "Node.h"
#include "Resistor.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Node::~Node(){}
//Node::Node(int nodeID_){nodeID=nodeID_;}
    Node::Node(int nodeID_,double Nvoltage_){
    nodeID=nodeID_;
    Nvotage=Nvoltage_;
    }
Node::Node(int nodeID_){
    nodeID=nodeID_;
    Nvotage=0;
    numRes=0;
    isunknown=true;}

void Node::addResistor(int resistorid,string name,double resistance,int node1,int node2){
resistorlist.insertRe(resistorid,name,resistance,node1,node2);
}
Resistorhead Node::getlist(){
return resistorlist;
}

void Node::TonextN(Node* next){nextN=next;}
Node* Node::getnextN(){return nextN;};

int Node::getID(){
return nodeID;
}



void Node::setVo(double voltage_){
Nvotage=voltage_;
}
double Node::getVo(){
return Nvotage;
}

void Node::setunknown(bool is){
isunknown=is;
}

bool Node::getunknown(){
return isunknown;
}
void Node::subsgetNum(){numRes--;}
void Node::addgetNum(){numRes++;}
int Node::getNum(){return numRes;}
