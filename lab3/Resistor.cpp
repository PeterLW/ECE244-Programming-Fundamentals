#include "Resistor.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Resistor::Resistor(int rIndex_,string name_,double resistance_,int endpoints_[2]){
name=name_;
resistance=resistance_;
endpointNodeIDs[0]=endpoints_[0];
endpointNodeIDs[1]=endpoints_[1];
rIndex=rIndex_;
}

Resistor::Resistor(){ifemp=1;}

Resistor::~Resistor(){}

void Resistor::setResistance(double resistance_){
resistance=resistance_;
}

void Resistor::setEndpoint0(int endpoint0){
endpointNodeIDs[0]=endpoint0;
}

void Resistor::setEndpoint1(int endpoint1){
    endpointNodeIDs[1]=endpoint1;
}

void Resistor::setrIndex(int rIndex_){
rIndex=rIndex_;
}
void Resistor::setName(string name_){
name=name_;
}

void Resistor::setResistor(string name_,double resistance_,int endpoints0,int endpoints1,int rIndex_){
name=name_;
resistance=resistance_;
endpointNodeIDs[0]=endpoints0;
endpointNodeIDs[1]=endpoints1;
rIndex=rIndex_;
}

void Resistor::setempty(){
ifemp=false;
}

bool Resistor::ifempty(){
return ifemp;
}

string Resistor::getName() const{
 return name;
 }

 double Resistor::getResistance() const{
 return resistance;;
 }

 int Resistor::getEndpoint0(){
 return endpointNodeIDs[0];
 }

 int Resistor::getEndpoint1(){
 return endpointNodeIDs[1];
 }

 int Resistor::getrIndex(){
 return rIndex;
 }

 void Resistor::printRe(){
cout<<name<<setw(20)<<" ";
cout<<setw(8)<<resistance<<" Ohms "<<endpointNodeIDs[0]<<" -> "<<endpointNodeIDs[1]<<endl;
 }

//void Resistor::print(){
//}
