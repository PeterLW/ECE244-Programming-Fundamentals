#include <iostream>
#include <sstream>
#include <string>
#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"
using namespace std;

int main()
{

    string line, command;

    string name,status;

    unsigned int IPaddress;

    bool active=false;

    DBentry* dbentrys;

    TreeDB treedbs;

    cout<<"> ";

    getline(cin,line);

//set all floating point number to precision 2
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);


    while(!cin.eof())
    {
        stringstream lineStream(line);

        lineStream>>command;





        if(command=="insert"){

            lineStream>>name>>IPaddress>>status;

            if(status=="active"){active=true;}

            else{active=false;}

            dbentrys=new DBentry(name,IPaddress,active);

            treedbs.insert(dbentrys);

            dbentrys=NULL;

           // delete dbentrys;
        }







        if(command=="find"){

            lineStream>>name;

            dbentrys=treedbs.find(name);

        if(dbentrys==NULL){cout<<"Error: entry does not exist"<<endl;}

        else{
                if(dbentrys->getActive()){status="active";}

                else{status="inactive";}

                cout<<dbentrys->getName()<<" : "<<dbentrys->getIPaddress()<<" : "<<status<<endl; }

        }






        if(command=="remove"){

            bool judge;

            lineStream>>name;

            judge=treedbs.remove(name);

            if(judge==true){cout<<"Success"<<endl;}

            else{cout<<"Error: entry does not exist"<<endl;}
        }






        if(command=="printall"){

        cout<<treedbs;
        }






        if(command=="printprobes"){

        lineStream>>name;

        dbentrys=treedbs.find(name);

        if(dbentrys==NULL){cout<<"Error: entry does not exist"<<endl;}

        else{
        treedbs.printProbes();
        }

        }







        if(command=="removeall"){

            treedbs.clear();
            cout<<"Success"<<endl;

        }







        if(command=="countactive"){

            treedbs.countActive();
        }







        if(command=="updatestatus"){

        lineStream>>name>>status;

        dbentrys=treedbs.find(name);

        if(dbentrys==NULL){cout<<"Error: entry does not exist"<<endl;}

        else{
                if(status=="active"){active=true;}

                else{active=false;}

                dbentrys->setActive(active);

                cout<<"Success"<<endl;}
                }




        //treedbs.resetprobe();

        cout<<"> ";

        getline(cin,line);


    }

    return 0;
}
