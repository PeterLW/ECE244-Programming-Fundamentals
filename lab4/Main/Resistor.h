#ifndef RESISTOR_H
#define RESISTOR_H
//#include "ResistorList.h"
#include <string>
#include <iostream>
using namespace std;

class Resistor
{
private:
   double resistance; // resistance (in Ohms)
   string name; // C++ string holding the label
   int endpointNodeIDs[2]; // IDs of nodes it attaches to
   int rIndex;
   Resistor* nextR;

   //bool ifemp;
public:
  Resistor();
  Resistor(int rIndex_,string name_,double resistance_,int endpoints0,int endpoints1);
  Resistor(string name_,double resistance_);
  Resistor(string name_);

   // rIndex_ is the index of this resistor in the resistor array
   // endpoints_ holds the node indices to which this resistor connects

   ~Resistor();
   Resistor* getnextR();
   void TonextR(Resistor* next);
   void setResistor(string name_,double resistance_,int endpoints0,int endpoints1int,int rIndex_);
   string getName() const; // returns the name
   double getResistance() const; // returns the resistance
   void setResistance (double resistance_);
   void setName(string);
   void setEndpoint0(int);
   void setEndpoint1(int);
   void setrIndex(int);
   int getEndpoint0();
   int getEndpoint1();
   int getrIndex();
   void setempty();
   bool ifempty();
   void printRe();
   // you *may* create either of the below to print your resistor
   //void print ();

   friend ostream& operator<<(ostream&,const Resistor&);
};

ostream& operator<<(ostream&,const Resistor&);

#endif  /* RESISTOR_H */
