//Programmer: Wei Lin
//Student#:999595193
//Short description : the program get user input, check input error, then output corresponding outputs
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Resistor.h"
#include "Node.h"
#include <iomanip>
#include "ResistorList.h"
#include "NodeList.h"
//#define MAX_RESISTORS_PERNODE 5
using namespace std;

int main(){

string line, command;
cout<<"> ";
getline(cin,line);
//set all floating point number to precision 2
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
//Node* nodes;
//Resistor* resistors;
int resistorID=0;
//bool again=false;
Resistorhead resistorlist;
Nodehead nodelist;
while(!cin.eof()){

    //declare stringsteam and other variable
    stringstream lineStream(line);
    stringstream lineStream2(line);//use for checking error
    stringstream lineStream3(line);//use for checking error
    string name;
    string testname;//use for checking error
    double resistance;
    int node1,node2;
    double voltage;
    //int testnode,testresistor;
    char flag;//use to get next char in stringstream
    lineStream>>command;


    //check invalid command
    if((command!="insertR"&&command!="modifyR"&&command!="printR"&&command!="printNode"&&command!="deleteR"&&command!="setV"&&command!="unsetV"&&command!="solve"/*&&command!="maxVal"*/)|lineStream.fail()){
        cout<<"Error: invalid command"<<endl;
        }

    //if user only input command, it is too few arguments
    else if(lineStream.eof()&&command!="solve"){
        cout<<"Error: too few arguments"<<endl;
        }

    else{
    if(command=="solve"){
            nodelist.solveV();
    }
     else if(command=="setV"){
            bool findV;
        lineStream>>node1;
        lineStream>>voltage;
        //nodes=new Node(node1,voltage);
        findV=nodelist.nsetV(node1,voltage);
        //if(!findV){nodelist.insertNo2(nodes);}
        //if(!findV){nodelist.insertNo(nodes);}
        cout<<"Set: node "<<node1<<" to "<<voltage<<" Volts"<<endl;
        //delete nodes;
    }
    else if(command=="unsetV"){
    lineStream>>node1;
        //nodes=new Node(node1);
        nodelist.unsetV(node1);
        cout<<"Unset: the solver will determine the voltage of node "<<node1<<endl;
        //delete nodes;
    }
     if(command=="insertR"){
        lineStream>>name;
        lineStream2>>testname>>testname>>testname>>testname>>testname>>testname;

        if(name=="all"){
            cout<<"Error: resistor name cannot be the keyword \"all\""<<endl;
            }

        else if(lineStream.eof()){
            cout<<"Error: too few arguments"<<endl;
            }

         else {
            lineStream>>resistance;
            flag=lineStream.peek();

            if((flag<'0'||flag>'9')&&flag!=' '&&!lineStream.eof()){
                cout<<"Error: invalid argument"<<endl;
                }

            else if(resistance<0){
                cout<<"Error: negative resistance"<<endl;
                }

            else if(lineStream.eof()){
                cout<<"Error: too few arguments"<<endl;
                }

            else{
            lineStream>>node1;
            flag=lineStream.peek();

            if((flag<'0'||flag>'9')&&flag!=' '&&!lineStream.eof()){
                cout<<"Error: invalid argument"<<endl;
                }
            else if(lineStream.eof()){
                cout<<"Error: too few arguments"<<endl;
                }

            else{
            lineStream>>node2;
            flag=lineStream.peek();

            if((flag<'0'||flag>'9')&&!lineStream.eof()&&flag!=' '){
                cout<<"Error: invalid argument"<<endl;
                }
            else if(node1==node2){
                cout<<"Error: both terminals of resistor connect to node "<<node2<<endl;
                }

            else if(flag==' '&&!lineStream2.fail()){
                cout<<"Error: too many arguments"<<endl;
                }
            else{
                bool find;
                find=resistorlist.insertRe(resistorID,name,resistance,node1,node2);
                nodelist.insertNo(node1,resistorID,name,resistance,node1,node2);
                nodelist.insertNo(node2,resistorID,name,resistance,node1,node2);
                              if(find){cout<<"Inserted: resistor "<<name<<" "<<resistance<<" Ohms "<<node1<<" -> "<<node2<<endl;}
                else{cout<<"Error: resistor "<<name<<" already exists"<<endl;}
                /*
                resistors=new Resistor(resistorID,name,resistance,node1,node2);
                if(!resistorlist.searchRe(resistors)){
                cout<<"Inserted: resistor "<<name<<" "<<resistance<<" Ohms "<<node1<<" -> "<<node2<<endl;
                resistorlist.insertRe(resistors);

                nodes=new Node(node1);

                resistors=new Resistor(resistorID,name,resistance,node1,node2);

                nodelist.insertNo(nodes,resistors);

                nodes=new Node(node2);

                resistors=new Resistor(resistorID,name,resistance,node1,node2);
                nodelist.insertNo(nodes,resistors);

                }

                else{cout<<"Error: resistor "<<name<<" already exists"<<endl;}*/
                resistorID++;

            }
         }
      }
   }
}

    else if(command=="modifyR"){

        lineStream>>name;
        lineStream2>>testname>>testname>>testname>>testname;

        if(name=="all"){
            cout<<"Error: resistor name cannot be the keyword \"all\""<<endl;
            }

        else if(lineStream.eof()){
            cout<<"Error: too few arguments"<<endl;
            }

        else{
        lineStream>>resistance;
        flag=lineStream.peek();

        if((flag<'0'||flag>'9')&&!lineStream.eof()&&flag!=' '){
            cout<<"Error: invalid argument"<<endl;
            }

        else if(resistance<0){
            cout<<"Error: negative resistance"<<endl;
            }

        else if(flag==' '&&!lineStream2.fail()){
            cout<<"Error: too many arguments"<<endl;
            }
        else{
            resistorlist.modifyRe(name,resistance);
            nodelist.findresistor(name,resistance);
            /*resistors=new Resistor(name,resistance);
            if(resistorlist.searchRe(resistors))
            {resistorlist.modifyRe(resistors);
            nodelist.findresistor(resistors);
            }
            else
            {cout<<"Error: resistor "<<name<<" not found"<<endl;}
            delete resistors;*/
        }
        }
    }


    else if(command=="printR"){
            lineStream>>name;
            lineStream2>>testname>>testname>>testname;
            if(!lineStream2.fail()){
                cout<<"Error: too many arguments"<<endl;
            }
            else{
                resistorlist.printRe(name);
            /*
            resistors=new Resistor(name);
            resistorlist.printRe(resistors);
            delete resistors;*/
            }
    }


    else if(command=="printNode"){
        lineStream>>node1;
        flag=lineStream.peek();
        //first name is command,second name is argument
        lineStream2>>name>>name;
        lineStream3>>testname>>testname>>testname;

        if(name=="all"){
            nodelist.printallnode();
        }
            else{
            nodelist.printNo(node1);
            /*
              nodes=new Node(node1);//pass nodeID
            nodelist.printNo(nodes);
            delete nodes;*/
            }
    }
    else if(command=="deleteR"){
            lineStream>>name;
            lineStream3>>testname>>testname>>testname;
            flag=lineStream.peek();

           if(name=="all"){

           cout<<"Deleted: all resistors"<<endl;
           resistorlist.deleteall();
           nodelist.deleteallN();
           }
           else if(!lineStream3.fail()){
                cout<<"Error: too many arguments"<<endl;
            }
            else{

               if(resistorlist.deleteRe(name)){
               cout<<"Deleted: resistor "<<name<<endl;
               nodelist.deleteresistor(name);}
               else{cout<<"Error: resistor "<<name<<" not found"<<endl;}
               /* resistors=new Resistor(name);
                if(resistorlist.deleteRe(resistors)){
                nodelist.deleteresistor(resistors);
                cout<<"Deleted: resistor "<<name<<endl;}
                else{cout<<"Error: resistor "<<name<<" not found"<<endl;}
                delete resistors;*/
                }
    }

}
//ask user for next input
    cout<<"> ";
    getline(cin,line);
}
if(resistorlist.head()!=NULL){
resistorlist.deleteall();}
if(nodelist.head()!=NULL){
nodelist.deleteallN();}


return 0;
}
