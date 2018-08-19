#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
#include "Resistor.h"
#include "ResistorList.h"
using namespace std;
//#define MAX_RESISTORS_PER_NODE 5
//#define MIN_RESISTORS_PER_NODE 5
class Node
{
private:

   int numRes; // number of resistors currently connected

   Resistorhead resistorlist;

   Node* nextN;
   int nodeID;

   double Nvotage;
   bool isunknown;
//   int resIDArray[MAX_RESISTORS_PER_NODE]; // stores the index of each resistor connected

public:
   //Node(string name_,int nodeID_,int connectNode_,double resistance_,Resistor* newR);
   // void printx();
   Node(int nodeID_);
   Node(int nodeID_,double Nvoltage_);
   ~Node();
   Node* getnextN();
   //string getname();
   void TonextN(Node* next);
   void addR(int node_);
   //void printn();
   //void printns(Node* newN);
//   Rname* gethead();
   //Rname* gettail();
   void setunknown(bool is);
   bool getunknown();
  // void headpoint();
   //int getnode1();
   //int getnode2();
   //double getresistance();
   int getNum();
   void addgetNum();
   void subsgetNum();
   int getID();
   void setVo(double voltage_);
   double getVo();
   Resistorhead getlist();
   //int compareID(Rname* R);
   // prints the whole node
   // nodeIndex is the position of this node in the node array.
   //void print (int nodeIndex);
   // Updates resIDArray to show the resistor in position rIndex in
   // the resistor array is now connected to this node.
   // Returns true if successful
   void addResistor (int resistorid,string name,double resistance,int node1,int node2);
   //void setID(int resID);
   //void setempty();
   //bool ifempty();
};

#endif  /* NODE_H */
