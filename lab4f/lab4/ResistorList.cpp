#include "Resistor.h"
#include "ResistorList.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
Resistorhead::~Resistorhead(){}
Resistorhead::Resistorhead(){
listhead=NULL;
listtail=NULL;
}
Resistor* Resistorhead::head(){return listhead;}
void Resistorhead::insertRe(Resistor* newR){

if(listhead==NULL){
    listhead=newR;
    newR->TonextR(NULL);
    listtail=newR;
}
else{
    listtail->TonextR(newR);
    newR->TonextR(NULL);
    listtail=newR;
}
}

void Resistorhead::modifyRe(Resistor* newR){
    Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==newR->getName()){
                cout<<"Modified: resistor "<<currentR->getName()<<" from "<<currentR->getResistance()<<" Ohms to "<<newR->getResistance()<<" Ohms"<<endl;
                findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
if(findR){currentR->setResistance(newR->getResistance());}
}

void Resistorhead::modifyRe2(Resistor* newR){
    Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==newR->getName()){
                //cout<<"Modified: resistor "<<currentR->getName()<<" from "<<currentR->getResistance()<<" Ohms to "<<newR->getResistance()<<" Ohms"<<endl;
                findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
if(findR){currentR->setResistance(newR->getResistance());}
}

bool Resistorhead::searchRe(Resistor* newR){
    Resistor* currentR=listhead;
    while(currentR!=NULL){
        if(currentR->getName()==newR->getName()){
                return true;}
        else{
            currentR=currentR->getnextR();
        }
    }
    return false;
}

void Resistorhead::printRe(Resistor* newR){
    Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==newR->getName()){
        cout<<"Print:"<<endl;
        cout<<currentR->getName()<<setw(20)<<" ";
        cout<<setw(8)<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;
        findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
    if(findR==false){cout<<"Error: resistor "<<newR->getName()<<" not found"<<endl;}
}

void Resistorhead::deleteall(){
        while(listhead!=NULL){
        Resistor* currentR=listhead;
        listhead=listhead->getnextR();
        delete currentR;
    }
}

bool Resistorhead::deleteRe(Resistor* newR){
        Resistor* currentR=listhead;
        Resistor* fcurrentR;
        bool findR=false;
        while(currentR!=NULL){
        if(currentR==listhead&&currentR->getName()==newR->getName()){
        listhead=currentR->getnextR();
        delete currentR;
        findR=true;break;
        }
        else if(currentR!=listhead&&currentR->getName()==newR->getName()){
            fcurrentR->TonextR(currentR->getnextR());
            delete currentR;
            findR=true;break;
        }
            fcurrentR=currentR;
            currentR=currentR->getnextR();
    }
    return findR;
}
bool Resistorhead::deleteRe2(Resistor* newR){
        Resistor* currentR=listhead;
        Resistor* fcurrentR;
        bool findR=false;
        while(currentR!=NULL){
        if(currentR==listhead&&currentR->getName()==newR->getName()){
        listhead=listhead->getnextR();
        delete currentR;
        currentR=listhead;
        //if(listhead==NULL){cout<<"null ";}
        findR=true;
        break;
        }
        else if(currentR!=listhead&&currentR->getName()==newR->getName()){
            fcurrentR->TonextR(currentR->getnextR());
            delete currentR;
            currentR=fcurrentR->getnextR();
            findR=true;
            break;
        }
        else{
            fcurrentR=currentR;
            currentR=currentR->getnextR();}
    }
    return findR;
}
void Resistorhead::print(){
    Resistor* currentR=listhead;
    while(currentR!=NULL){
    cout<<currentR->getName()<<" ";
    cout<<currentR->getResistance()<<endl;
    currentR=currentR->getnextR();
    }
}
void Resistorhead::printnode(){
    Resistor* currentR=listhead;
    while(currentR!=NULL){
    cout<<"  "<<currentR->getName()<<setw(20)<<" "<<setw(8)<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;
    currentR=currentR->getnextR();
    }
}
void Resistorhead::printallRe(){
    Resistor* currentR=listhead;
    while(currentR!=NULL){

        cout<<"Print:"<<endl;
        cout<<currentR->getName()<<setw(20)<<" ";
        cout<<setw(8)<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;

            currentR=currentR->getnextR();
    }
}
double Resistorhead::firstterm(){
Resistor* currentR=listhead;
double sum=0;
while(currentR!=NULL){
        sum+=1/currentR->getResistance();
        currentR=currentR->getnextR();
}
return sum;
}
