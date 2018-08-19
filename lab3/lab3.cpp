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
//#define MAX_NODE_NUMBER 5000
#define MAX_RESISTORS_PERNODE 5
using namespace std;

int main(){

string line, command;
cout<<"> ";
getline(cin,line);
//set all floating point number to precision 2
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

while(!cin.eof()){

    //declare stringsteam and other variable
    stringstream lineStream(line);
    stringstream lineStream2(line);//use for checking error
    stringstream lineStream3(line);//use for checking error
    string name;
    string testname;//use for checking error
    double resistance;
    int node1,node2;
    int maxNodeNumber,maxResistors,minNodeNumber=0,MinResistors=0,resistorID;
    char flag;//use to get next char in stringstream
    bool again=false;
    lineStream>>command;
    Node* nodes;
    Resistor* resistors;

    //check invalid command
    if((command!="insertR"&&command!="modifyR"&&command!="printR"&&command!="printNode"&&command!="deleteR"&&command!="maxVal")|lineStream.fail()){
        cout<<"Error: invalid command"<<endl;
        }

    //if user only input command, it is too few arguments
    else if(lineStream.eof()){
        cout<<"Error: too few arguments"<<endl;
        }

    else{

    //the code below check if the user input contains errors and shows the corresponding output based on different situations
    if(command=="maxVal"&&again==false){
        lineStream>>maxNodeNumber;
        lineStream>>maxResistors;
        if(maxNodeNumber<=0|maxResistors<=0){cout<<"Error: maxVal arguments must be greater than 0"<<endl;}
        else{cout<<"New network: max node number is "<<maxNodeNumber<<"; max resistors is "<<maxResistors<<endl;

        nodes=new Node[maxNodeNumber+1];
        resistors=new Resistor[maxResistors];

        //for(int x=0;x<=maxNodeNumber;x++){nodes[x]=NULL;}
        //for(int y=0;y<maxResistors;y++){resistors[y]=NULL;}
        again=true;
        }
        }
    else if(command=="maxVal"&&again==true){
        //for(int i=0;i<=maxNodeNumber;i++){
                delete[] nodes;//}
        //for(int j=0;j<=maxResistors;j++){
            delete[] resistors;//}
        lineStream>>maxNodeNumber;
        lineStream>>maxResistors;
        if(maxNodeNumber<=0|maxResistors<=0){cout<<"Error: maxVal arguments must be greater than 0"<<endl;}
        else{cout<<"New network: max node number is "<<maxNodeNumber<<"; max resistors is "<<maxResistors<<endl;
        nodes=new Node[maxResistors+1];
        resistors=new Resistor[maxResistors];
        //for(int x=0;x<=maxNodeNumber;x++){nodes[x]=NULL;}
        //for(int y=0;y<maxResistors;y++){resistors[y]=NULL;}
        }
        }

    else if(command=="insertR"){
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

            if((flag<'0'|flag>'9')&&flag!=' '&&!lineStream.eof()){
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

            if((flag<'0'|flag>'9')&&flag!=' '&&!lineStream.eof()){
                cout<<"Error: invalid argument"<<endl;
                }

            else if(node1<0|node1>maxNodeNumber){
                cout<<"Error: node "<<node1<<" is out of permitted range "<<minNodeNumber<<"-"<<maxNodeNumber<<endl;
                }
            else if(!resistors[maxResistors-1].ifempty()){cout<<"Error: resistor array is full"<<endl;}
            else if(!nodes[node1].ifempty()){
                    cout<<"Error: node is full"<<endl;
            }
            else if(lineStream.eof()){
                cout<<"Error: too few arguments"<<endl;
                }

            else{
            lineStream>>node2;
            flag=lineStream.peek();

            if((flag<'0'|flag>'9')&&!lineStream.eof()&&flag!=' '){
                cout<<"Error: invalid argument"<<endl;
                }

            else if(node2<0|node2>maxNodeNumber){
                cout<<"Error: node "<<node2<<" is out of permitted range "<<minNodeNumber<<"-"<<maxNodeNumber<<endl;
                }
            else if(!resistors[maxResistors-1].ifempty()){cout<<"Error: resistor array is full"<<endl;}
            else if(!nodes[node2].ifempty()){cout<<"Error: node is full"<<endl;}

            else if(node1==node2){
                cout<<"Error: both terminals of resistor connect to node "<<node2<<endl;
                }

            else if(flag==' '&&!lineStream2.fail()){
                cout<<"Error: too many arguments"<<endl;
                }

            else {
                for(int y=0;y<maxResistors;y++){
                    if(!resistors[y].ifempty()&&resistors[y].getName()==name){cout<<"Error: resistor name already exists"<<endl;break;}
                    else if(resistors[y].ifempty()&&nodes[node1].ifempty()&&nodes[node2].ifempty()){
                    resistorID=y;
                    //cout<<"ID"<<resistorID<<endl;
                    resistors[y].setResistor(name,resistance,node1,node2,resistorID);
                    nodes[node1].addResistor(resistorID);
                    nodes[node2].addResistor(resistorID);
                    resistors[y].setempty();
                    cout<<"Inserted: resistor "<<name<<" "<<resistance<<" Ohms "<<node1<<" -> "<<node2<<endl;
                    break;}
                    //else if(!nodes[node1].addResistor()|!nodes[node2].addResistor()){cout<<"Error: node is full"<<endl;break}
                }
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

        if((flag<'0'|flag>'9')&&!lineStream.eof()&&flag!=' '){
            cout<<"Error: invalid argument"<<endl;
            }

        else if(resistance<0){
            cout<<"Error: negative resistance"<<endl;
            }

        else if(flag==' '&&!lineStream2.fail()){
            cout<<"Error: too many arguments"<<endl;
            }

        else{
            for(int y=0;y<maxResistors;y++){
            if(name==resistors[y].getName())
            {resistors[y].setResistance(resistance);
            cout<<"Modified: resistor "<<name<<" to "<<resistance<<" Ohms"<<endl;
            break;}
            else if(y==(maxResistors-1)&&name!=resistors[y].getName()){cout<<"Error: resistor name not found"<<endl;}
            }
            }
        }
    }


    else if(command=="printR"){
            lineStream>>name;
            lineStream2>>testname>>testname>>testname;

                if(name=="all"&&lineStream2.fail()){
                    for(int y=0;y<maxResistors;y++){
                    if(!resistors[y].ifempty())
                    resistors[y].printRe();
                    }
                    //cout<<"Print: all resistors"<<endl;
                    }

            else if(!lineStream2.fail()){
                cout<<"Error: too many arguments"<<endl;
            }
            else{
                for(int y=0;y<maxResistors;y++){
                if(name==resistors[y].getName()){
                        resistors[y].printRe();break;}
                else if(y==(maxResistors-1)&&name!=resistors[y].getName()){
                cout<<"Error: resistor name not found"<<endl;
                }
                //cout<<"Print: resistor "<<name<<endl;
                }
                }
    }


    else if(command=="printNode"){
        lineStream>>node1;
        flag=lineStream.peek();
        //first name is command,second name is argument
        lineStream2>>name>>name;
        lineStream3>>testname>>testname>>testname;

                if(name=="all"){
                    if(lineStream3.fail()){
                    cout<<"Print:"<<endl;
                    for(int j=0;j<=maxNodeNumber;j++){
                    nodes[j].print(j);
                    for(int i=0;i<nodes[j].getNum();i++){
                    resistors[nodes[j].getID(i)].printRe();
                    }
                    }

                    //cout<<"Print: all nodes"<<endl;
                    }

                    else{
                        cout<<"Error: too many arguments"<<endl;
                        }
                }

                else if((flag<'0'|flag>'9')&&!lineStream.eof()&&flag!=' '){
                    cout<<"Error: invalid argument"<<endl;
                    }

                else if(node1<0|node1>maxNodeNumber){
                    cout<<"Error: node "<<node1<<" is out of permitted range "<<minNodeNumber<<"-"<<maxNodeNumber<<endl;
                    }

                else if(!lineStream3.fail()){
                    cout<<"Error: too many arguments"<<endl;
            }

                else {
                    cout<<"Print:"<<endl;
                    nodes[node1].print(node1);
                    for(int i=0;i<nodes[node1].getNum();i++){
                        resistors[nodes[node1].getID(i)].printRe();
                    }
                    //cout<<"Print: node "<<node1<<endl;}

    }

    }
    else if(command=="deleteR"){
            lineStream>>name;
            lineStream3>>testname>>testname>>testname;
            flag=lineStream.peek();

                if(name=="all"&&lineStream3.fail()){
                    cout<<"Deleted: all resistors"<<endl;
                    }


            else if(!lineStream3.fail()){
                cout<<"Error: too many arguments"<<endl;
            }
            else{
                cout<<"Deleted: resistor "<<name<<endl;
                //for(int i=0;i<=maxNodeNumber;i++){
                delete[] nodes;//}
                //for(int j=0;j<=maxResistors;j++){
                delete[] resistors;//}
                }
    }

}
//ask user for next input
    cout<<"> ";
    getline(cin,line);
}

return 0;
}
