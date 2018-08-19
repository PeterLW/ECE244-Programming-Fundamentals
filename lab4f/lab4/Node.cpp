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

void Node::addResistor(Resistor* newR){
resistorlist.insertRe(newR);
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


/*
int Node::getnode1(){
return node1x;
}

int Node::getnode2(){
return node2x;
}

double Node::getresistance(){
return resistancex;
}
    Node::Node(int nodeID_,double Nvoltage_){
    nodeID=nodeID_;
    Nvotage=Nvoltage_;
    }
void Node::headpoint(){
listhead=listhead->nextn;
}
void Node::addR(string nname,int node1_,int node2_,double resistance_){
Rname* dum=new Rname;
dum->name=nname;
dum->node1=node1_;
dum->node2=node2_;
dum->resistance=resistance_;
if(listhead==NULL){
    listhead=dum;
    dum->nextn=NULL;
    listtail=dum;}
else{
        listtail->nextn=dum;
        dum->nextn=NULL;
        listtail=dum;
        }
}

string Node::getname(){return name;}

void Node::printn(){
    Rname* currentN=listhead;
    while(currentN!=NULL){
    cout<<"  "<<currentN->name<<setw(20)<<" "<<setw(8)<<currentN->resistance<<" Ohms "<<currentN->node1<<" -> "<<currentN->node2<<endl;
    currentN=currentN->nextn;
    }
}

Rname* Node::gethead(){return listhead;}
Rname* Node::gettail(){return listtail;}
void Node::subsgetNum(){numRes--;}
void Node::addgetNum(){numRes++;}
int Node::getNum(){return numRes;}

/*void Node::printns(Node* newN){
    Rname* currentN=listhead;
    while(currentN!=NULL){
    int ID=currentN->getID();
    if(ID==newN->getID()){
    cout<<"  "<<currentN->name<<setw(20)<<" "<<setw(8)<<currentN->resistance<<" Ohms "<<currentN->node1<<" -> "<<currentN->node2<<endl;break;}
    else{
    currentN=currentN->nextn;}
    }
}*/
/*Node::Node(){
    numRes=0;
    ifemp=true;
    }
bool Node::ifempty(){
return ifemp;
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
}*/
