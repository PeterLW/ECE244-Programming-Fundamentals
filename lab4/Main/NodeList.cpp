#include "Node.h"
#include "NodeList.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include "ResistorList.h"
#include "Resistor.h"
using namespace std;

Nodehead::Nodehead(){listhead=NULL;listtail=NULL;}
Node* Nodehead::head(){return listhead;}

void Nodehead::insertNo(int nodeid, int resistorid,string name,double resistance,int node1,int node2){
    Node* nodes=new Node(nodeid);

Node* currentN=listhead;
Node* fcurrentN;
bool getN=false;
if(listhead==NULL){
    listhead=nodes;
    nodes->TonextN(NULL);
    listtail=nodes;
    listhead->addResistor(resistorid,name,resistance,node1,node2);
    listhead->addgetNum();
}
else{
    while(currentN!=NULL){
    int ID=currentN->getID();
    if(ID==nodes->getID()){
            currentN->addResistor(resistorid,name,resistance,node1,node2);
        currentN->addgetNum();
        getN=true;break;}
    else if(ID<nodes->getID()){
        fcurrentN=currentN;
        currentN=currentN->getnextN();
    }
    else{
        if(currentN!=listhead){
        fcurrentN->TonextN(nodes);
        nodes->TonextN(currentN);
      nodes->addResistor(resistorid,name,resistance,node1,node2);
        nodes->addgetNum();
        getN=true;
        break;}
        else{
            nodes->TonextN(listhead);
            listhead=nodes;
            listhead->addResistor(resistorid,name,resistance,node1,node2);
            listhead->addgetNum();
            getN=true;
        break;
    }
    }
    }
  if(getN==false){
        listtail->TonextN(nodes);
        nodes->TonextN(NULL);
        listtail=nodes;
        listtail->addResistor(resistorid,name,resistance,node1,node2);
        listtail->addgetNum();}
}
nodes=new Node(nodeid);
delete nodes;
}


void Nodehead::printallnode(){
Node* currentN=listhead;
    cout<<"Print:"<<endl;
while(currentN!=NULL){

    if(currentN!=NULL&&!currentN->getNum()==0){
   cout<<"Connections at node "<<currentN->getID()<<": "<<currentN->getNum()<<" resistor(s)"<<endl;
   currentN->getlist().printnode();}
   currentN=currentN->getnextN();}
}

void Nodehead::printNo(int node1){
    Node* currentN=listhead;
    //if(currentN!=NULL&&!0==currentN->getNum()){

    while(currentN!=NULL){
    int ID=currentN->getID();
    if(ID==node1&&!currentN->getNum()==0){
    cout<<"Print:"<<endl;
    cout<<"Connections at node "<<currentN->getID()<<": "<<currentN->getNum()<<" resistor(s)"<<endl;
    currentN->getlist().printnode();break;}
    else{
    currentN=currentN->getnextN();}
    }

}

void Nodehead::deleteallN(){
        while(listhead!=NULL){
        Node* currentN=listhead;
        listhead=listhead->getnextN();
        currentN->getlist().deleteall();
        delete currentN;
    }
}
void Nodehead::deleteresistor(string name){
    //Resistor* resistors=new Resistor(name);
Node* currentN=listhead;
Resistorhead rhead;
while(currentN!=NULL){
    if(currentN->getlist().deleteRe(name)){
        currentN->subsgetNum();
    }
    currentN=currentN->getnextN();
}
}

void Nodehead::findresistor(string name,double resistance){
Node* currentN=listhead;
while(currentN!=NULL){
currentN->getlist().modifyRe2(name,resistance);
currentN=currentN->getnextN();
}
}
void Nodehead::printV(){
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
Node* currentN;
currentN=listhead;
while(currentN!=NULL){
  cout<<"  Node "<<currentN->getID()<<": "<<currentN->getVo()<<" V"<<endl;
  currentN=currentN->getnextN();
}
}
bool Nodehead::nsetV(int id,double vol){
    Node* nodes=new Node(id,vol);
    Node* currentN=listhead;
    bool findV=false;
    while(currentN!=NULL){
        int ID=currentN->getID();
        double v=nodes->getVo();
        if(ID==nodes->getID()){
                currentN->setVo(v);
                currentN->setunknown(false);
                findV=true;
                break;}
       currentN=currentN->getnextN();
    }
    if(!findV){
Node* currentN2=listhead;
Node* fcurrentN;
bool getN=false;
if(listhead==NULL){
    listhead=nodes;
    nodes->TonextN(NULL);
    listtail=nodes;
}
else{
    int ID=currentN2->getID();
    if(currentN2==listhead&&nodes->getID()<listhead->getID()){
        nodes->TonextN(listhead);
        listhead=nodes;
    }
    else{
    while(currentN2!=NULL){
    int ID=currentN2->getID();
   if(ID<nodes->getID()){
              nodes->TonextN(currentN2);
       fcurrentN->TonextN(nodes);
            getN=true;
        break;
    }
            fcurrentN=currentN2;
        currentN2=currentN2->getnextN();
    }
    }
    }
  if(getN==false){
        listtail->TonextN(nodes);
        nodes->TonextN(NULL);
        listtail=nodes;
}
}
nodes=new Node(id,vol);
delete nodes;
return findV;
}

void Nodehead::unsetV(int id){
    Node* nodes=new Node(id);
Node* currentN=listhead;
    while(currentN!=NULL){
        int ID=currentN->getID();
        if(ID==nodes->getID()){
            currentN->setunknown(true);
        }
         currentN=currentN->getnextN();
}
delete nodes;
}

Node* Nodehead::searchNo(int ID){
    Node* currentN=listhead;
    while(currentN!=NULL){
        if(ID==currentN->getID()){
                return currentN;}
            currentN=currentN->getnextN();
    }
}

void Nodehead::solveV(){
Node* solu=listhead;
bool change=true;
while(solu!=NULL&&solu->getunknown()){
    solu=solu->getnextN();}
if(solu==NULL){cout<<"Error: no nodes have their voltage set"<<endl;}

else{
Node* currentN;
double presentV=0,finalV=0,firstterm=0,secondterm=0;
int ID,tempID;
while(change){
        currentN=listhead;
        change=false;

while(currentN!=NULL){
firstterm=0,secondterm=0;
if(currentN->getunknown()){
    ID=currentN->getID();
    presentV=currentN->getVo();
    firstterm=currentN->getlist().firstterm();
    Resistor* currentR=currentN->getlist().head();

    while(currentR!=NULL){
            //cout<<"x";
        double resistance=currentR->getResistance();
        if(ID!=currentR->getEndpoint0()){tempID=currentR->getEndpoint0();}
        else{tempID=currentR->getEndpoint1();}
        Node* volplace=searchNo(tempID);
        secondterm+=volplace->getVo()/resistance;
        currentR=currentR->getnextR();
    }
finalV=secondterm/firstterm;
currentN->setVo(finalV);
if(fabs(finalV-presentV)>0.0001){change=true;}
}
currentN=currentN->getnextN();
}
}
cout<<"Solve:"<<endl;
printV();
}
}
