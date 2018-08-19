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


void Nodehead::insertNo(Node* newN,Resistor* newR){
Node* currentN=listhead;
Node* fcurrentN;
bool getN=false;
if(listhead==NULL){
    listhead=newN;
    newN->TonextN(NULL);
    listtail=newN;
    listhead->addResistor(newR);
    listhead->addgetNum();
}
else{
    while(currentN!=NULL){
    int ID=currentN->getID();
    if(ID==newN->getID()){
            currentN->addResistor(newR);
        currentN->addgetNum();
        getN=true;break;}
    else if(ID<newN->getID()){
        fcurrentN=currentN;
        currentN=currentN->getnextN();
    }
    else{
        if(currentN!=listhead){
        fcurrentN->TonextN(newN);
        newN->TonextN(currentN);
      newN->addResistor(newR);
        newN->addgetNum();
        getN=true;
        break;}
        else{
            newN->TonextN(listhead);
            listhead=newN;
            listhead->addResistor(newR);
            listhead->addgetNum();
            getN=true;
        break;
    }
    }
    }
  if(getN==false){
        listtail->TonextN(newN);
        newN->TonextN(NULL);
        listtail=newN;
        listtail->addResistor(newR);
        listtail->addgetNum();}
}
}

void Nodehead::insertNo(Node* newN){
Node* currentN=listhead;
Node* fcurrentN;
bool getN=false;
if(listhead==NULL){
    listhead=newN;
    newN->TonextN(NULL);
    listtail=newN;
}
else{
    while(currentN!=NULL){
    int ID=currentN->getID();
    if(ID==newN->getID()){
        getN=true;break;}
    else if(ID<newN->getID()){
        fcurrentN=currentN;
        currentN=currentN->getnextN();
    }
    else{
        if(currentN!=listhead){
        fcurrentN->TonextN(newN);
        newN->TonextN(currentN);
        getN=true;
        break;}
        else{
            newN->TonextN(listhead);
            listhead=newN;
            getN=true;
        break;
    }
    }
    }
  if(getN==false){
        listtail->TonextN(newN);
        newN->TonextN(NULL);
        listtail=newN;}
}
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
void Nodehead::printNo(Node* newN){
    Node* currentN=listhead;
    if(currentN!=NULL&&!0==currentN->getNum()){
    cout<<"Print:"<<endl;
    }
    while(currentN!=NULL){
        int ID=currentN->getID();
    if(ID==newN->getID()&&!currentN->getNum()==0){
    currentN->getlist().printallRe();break;}
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
void Nodehead::deleteresistor(Resistor* newR){
Node* currentN=listhead;
while(currentN!=NULL){
    if(currentN->getlist().deleteRe2(newR)){
        currentN->subsgetNum();
    }
    currentN=currentN->getnextN();
}
}
void Nodehead::findresistor(Resistor* newR){
Node* currentN=listhead;
while(currentN!=NULL){
currentN->getlist().modifyRe2(newR);
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
  cout<<"Node "<<currentN->getID()<<": "<<currentN->getVo()<<" V"<<endl;
  currentN=currentN->getnextN();
}
}
bool Nodehead::nsetV(Node* newN){
    Node* currentN=listhead;
    bool findV=false;
    while(currentN!=NULL){
        int ID=currentN->getID();
        double v=newN->getVo();
        if(ID==newN->getID()){
                currentN->setVo(v);
                currentN->setunknown(false);
                findV=true;
                break;}
       currentN=currentN->getnextN();
    }
   return findV;
}

void Nodehead::unsetV(Node* newN){
Node* currentN=listhead;
    while(currentN!=NULL){
        int ID=currentN->getID();
        if(ID==newN->getID()){
            currentN->setunknown(true);
        }
         currentN=currentN->getnextN();
}
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
//double change2;
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
printV();
}
}
/*
void Nodehead::solveV(){

Node* solu=listhead;
while(solu!=NULL&&solu->getunknown()){
    solu=solu->getnextN();}
if(solu==NULL){cout<<"Error: no nodes have their voltage set"<<endl;}
else{
    Node* currentN;
    double localV,finalV,firstterm=0.00,secondterm=0.00;

    Rname* currentR;
    bool change1=true;
    double change2;
while(change1){
    change1=false;
    currentN=listhead;
    firstterm=0.00;
    secondterm=0.00;
    //cout<<"ok";
    while(currentN!=NULL){
    //cout<<"node:"<<ID;
    firstterm=0.00;
    secondterm=0.00;
    if(currentN->getunknown()){
        int ID=currentN->getID();
         localV=currentN->getVo();

    double* resistanceArr=new double[currentN->getNum()];
    //int* idArr=new int[currentN->getNum()];
    double* volArr=new double[currentN->getNum()];
    int tempID;
    currentR=currentN->gethead();//list head of resistor array
    for(int i=0;i<currentN->getNum();i++){

    resistanceArr[i]=currentR->resistance;

    if(ID!=currentR->node1){
    tempID=currentR->node1;}
    else{tempID=currentR->node2;}

    Node* volplace;
    volplace=searchNo(tempID);
    volArr[i]=volplace->getVo();

    currentR=currentR->nextn;//cout<<"R:"<<resistanceArr[i];
    }
    for(int i=0;i<currentN->getNum();i++){
    firstterm+=(1/resistanceArr[i]);
    secondterm+=((volArr[i])/(resistanceArr[i]));
    }
    finalV=(secondterm)/(firstterm);

    change2=fabs(localV-finalV);//cout<<" localV:"<<localV<<" final V:"<<finalV<<" change:"<<change2<<endl;
    if(change2>0.0001){change1=true;}
    currentN->setVo(finalV);
    delete []resistanceArr;
    //delete []idArr;
    delete []volArr;
    }

    currentN=currentN->getnextN();
    }
    }
printV();
}
}
void Nodehead::print(){
    Node* currentN=listhead;
    //if(currentN!=NULL){
    cout<<"Print:"<<endl;
    //}
    while(currentN!=NULL){
    cout<<"Connections at node "<<currentN->getID()<<": "<<currentN->getNum()<<" resistor(s)"<<endl;
    currentN->printn();
    currentN=currentN->getnextN();
    }
}

void Nodehead::printNo(Node* newN){
    Node* currentN=listhead;
    //if(currentN!=NULL){
    cout<<"Print:"<<endl;
    //}
    while(currentN!=NULL){
        int ID=currentN->getID();
    if(ID==newN->getID()){
    cout<<"Connections at node "<<currentN->getID()<<": "<<currentN->getNum()<<" resistor(s)"<<endl;
    currentN->printn();break;}
    else{
    currentN=currentN->getnextN();}
    }
}

//string Nodehead::returnID(){

void Nodehead::nsetV(Node* newN){
    Node* currentN=listhead;
    while(currentN!=NULL){
        int ID=currentN->getID();
        double v=newN->getVo();
        if(ID==newN->getID()){
                currentN->setVo(v);
                currentN->setunknown(false);break;}
            currentN=currentN->getnextN();

    }
}
void Nodehead::unsetV(Node* newN){
Node* currentN=listhead;
    while(currentN!=NULL){
        int ID=currentN->getID();
        if(ID==newN->getID()){
            currentN->setunknown(true);
        }
         currentN=currentN->getnextN();
}
}
Node* Nodehead::searchNo(int ID){
    Node* currentN=listhead;
    while(currentN!=NULL){
        if(ID==currentN->getID()){
                return currentN;}
            currentN=currentN->getnextN();
    }
}
/*
void Nodehead::solveV(){

Node* solu=listhead;
while(solu!=NULL&&solu->getunknown()){
    solu=solu->getnextN();}
if(solu==NULL){cout<<"Error: no nodes have their voltage set"<<endl;}
else{
    Node* currentN;
    double localV,finalV,firstterm=0.00,secondterm=0.00;

    Rname* currentR;
    bool change1=true;
    double change2;
while(change1){
    change1=false;
    currentN=listhead;
    firstterm=0.00;
    secondterm=0.00;
    //cout<<"ok";
    while(currentN!=NULL){
    //cout<<"node:"<<ID;
    firstterm=0.00;
    secondterm=0.00;
    if(currentN->getunknown()){
        int ID=currentN->getID();
         localV=currentN->getVo();

    double* resistanceArr=new double[currentN->getNum()];
    //int* idArr=new int[currentN->getNum()];
    double* volArr=new double[currentN->getNum()];
    int tempID;
    currentR=currentN->gethead();//list head of resistor array
    for(int i=0;i<currentN->getNum();i++){

    resistanceArr[i]=currentR->resistance;

    if(ID!=currentR->node1){
    tempID=currentR->node1;}
    else{tempID=currentR->node2;}

    Node* volplace;
    volplace=searchNo(tempID);
    volArr[i]=volplace->getVo();

    currentR=currentR->nextn;//cout<<"R:"<<resistanceArr[i];
    }
    for(int i=0;i<currentN->getNum();i++){
    firstterm+=(1/resistanceArr[i]);
    secondterm+=((volArr[i])/(resistanceArr[i]));
    }
    finalV=(secondterm)/(firstterm);

    change2=fabs(localV-finalV);//cout<<" localV:"<<localV<<" final V:"<<finalV<<" change:"<<change2<<endl;
    if(change2>0.0001){change1=true;}
    currentN->setVo(finalV);
    delete []resistanceArr;
    //delete []idArr;
    delete []volArr;
    }

    currentN=currentN->getnextN();
    }
    }
printV();
}
}
void Nodehead::printV(){
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
Node* currentN;
currentN=listhead;
while(currentN!=NULL){
  cout<<"Node "<<currentN->getID()<<": "<<currentN->getVo()<<" V"<<endl;
  currentN=currentN->getnextN();
}
}

void Nodehead::findresistor(string name, double resistance){
Node* currentN;
currentN=listhead;
Rname* currentR;
while(currentN!=NULL){
    currentR=currentN->gethead();
    while(currentR!=NULL){
        if(name==currentR->name){currentR->resistance=resistance;}
        currentR=currentR->nextn;
    }
    currentN=currentN->getnextN();
}
}
void Nodehead::deleteresistor(string name){
Node* currentN;
currentN=listhead;
Rname* currentR;
Rname* fcurrentR;
while(currentN!=NULL){
    currentR=currentN->gethead();
    while(currentR!=NULL){
        if(currentR==currentN->gethead()&&name==currentR->name){
              currentN->headpoint();delete currentR;
              currentN->subsgetNum();
              }
        else if(currentR!=currentN->gethead()&&name==currentR->name){
            fcurrentR->nextn=currentR->nextn;
            delete currentR;
            currentN->subsgetNum();
        }
        fcurrentR=currentR;
        currentR=currentR->nextn;
    }
    currentN=currentN->getnextN();
}
}

void Nodehead::deleteallN(){
        while(listhead!=NULL){
        Node* currentN=listhead;
        listhead=listhead->getnextN();
        delete currentN;
    }
}
    /*currentR=currentN->gethead();
    for(int i=0;i<currentN->getNum();i++){
    if(ID!=currentR->node1){
    idArr[i]=currentR->node1;}
    else{idArr[i]=currentR->node2;}
    //cout<<" id:"<<idArr[i];
    currentR=currentR->nextn;
    }

    currentR=currentN->gethead();
    for(int i=0;i<currentN->getNum();i++){
     Node* volplace;
     volplace=searchNo(idArr[i]);
     volArr[i]=volplace->getVo();//cout<<" V:"<<volArr[i];
    }*/

/*void Nodehead::printNo(Node* newN){
    Node* currentN=listhead;
    bool findN=false;
    while(currentN!=NULL){
        if(currentN->getID()==newN->getID()){
        cout<<"Print:"<<endl;
        cout<<currentR->getName()<<setw(20)<<" ";
        cout<<setw(8)<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;
        findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
    if(findR==false){cout<<"Error: resistor "<<newR->getName()<<" not found"<<endl;}
}*/
