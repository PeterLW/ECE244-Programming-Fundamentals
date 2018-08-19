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

bool Resistorhead::insertRe(int rIndex_,string name_,double resistance_,int endpoints0,int endpoints1){

    Resistor* resistors;
    bool find=false;
    resistors=new Resistor(rIndex_,name_,resistance_,endpoints0,endpoints1);
    if(!searchRe(resistors)){
        find=true;
             if(listhead==NULL){
    listhead=resistors;
    resistors->TonextR(NULL);
    listtail=resistors;
}
else{
    listtail->TonextR(resistors);
    resistors->TonextR(NULL);
    listtail=resistors;

}
                }
    else{find=false;}
                resistors=new Resistor(rIndex_,name_,resistance_,endpoints0,endpoints1);
    //Resistor** x=&(resistors);
                delete resistors;
                return find;
}

void Resistorhead::modifyRe(string name_, double resistance_){
    Resistor* resistors=new Resistor(name_,resistance_);
            if(searchRe(resistors))
            {
                 Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==resistors->getName()){
                cout<<"Modified: resistor "<<currentR->getName()<<" from "<<currentR->getResistance()<<" Ohms to "<<resistors->getResistance()<<" Ohms"<<endl;
                findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
if(findR){currentR->setResistance(resistors->getResistance());}
            }
            else
            {cout<<"Error: resistor "<<name_<<" not found"<<endl;}

                delete resistors;
}

void Resistorhead::modifyRe2(string name_,double resistance_){
    Resistor* resistors=new Resistor(name_,resistance_);
            if(searchRe(resistors))
            {
                 Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==resistors->getName()){
                findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
if(findR){currentR->setResistance(resistors->getResistance());}
            }

                delete resistors;
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

void Resistorhead::printRe(string name_){

            Resistor* resistors=new Resistor(name_);
    Resistor* currentR=listhead;
    bool findR=false;
    while(currentR!=NULL){
        if(currentR->getName()==resistors->getName()){
        cout<<"Print:"<<endl;
        cout<<currentR->getName()<<setw(20)<<" ";
        cout<<setw(8)<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;
        findR=true;break;}
        else{
            currentR=currentR->getnextR();
        }
    }
    if(findR==false){cout<<"Error: resistor "<<resistors->getName()<<" not found"<<endl;}
                delete resistors;
}



void Resistorhead::deleteall(){
        while(listhead!=NULL){
        Resistor* currentR=listhead;
        listhead=currentR->getnextR();
        delete currentR;
    }
}

bool Resistorhead::deleteRe(string name_){
        Resistor* resistors=new Resistor(name_);

        Resistor* currentR=listhead;
        Resistor* fcurrentR;
        bool findR=false;
        if(currentR==listhead&&currentR->getName()==resistors->getName()){
        listhead=listhead->getnextR();
        delete currentR;
        findR=true;
        return findR;
        }
        else{
            fcurrentR=currentR;
            currentR=currentR->getnextR();
        while(currentR!=NULL){
            if(currentR->getName()==resistors->getName()){
            fcurrentR->TonextR(currentR->getnextR());
            delete currentR;
            findR=true;
            return findR;}
            fcurrentR=currentR;
            currentR=currentR->getnextR();
        }
        }
        resistors=new Resistor(name_);
delete resistors;
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
    //cout<<"xx"<<currentR->getName();
    while(currentR!=NULL){
        //cout<<"xx";
        cout<<" "<<currentR->getName()<<setw(28);//" ";
        cout<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;

            currentR=currentR->getnextR();
    }
}
void Resistorhead::printallRe(){
    Resistor* currentR=listhead;
    if(currentR!=NULL){cout<<"Print:"<<endl;}

    while(currentR!=NULL){

        cout<<" "<<currentR->getName()<<setw(28);
        cout<<currentR->getResistance()<<" Ohms "<<currentR->getEndpoint0()<<" -> "<<currentR->getEndpoint1()<<endl;

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
