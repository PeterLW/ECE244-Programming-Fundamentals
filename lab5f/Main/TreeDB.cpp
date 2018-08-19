#include <iostream>
#include <string.h>
#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"
using namespace std;

TreeDB::~TreeDB(){
clear();
}
//**************************************************************************************************************************
TreeDB::TreeDB(){

root=NULL;

probesCount=0;
}


//helper function of insert************************************************************************************************************
bool TreeDB::insert_bst(TreeNode* n, TreeNode* r){

if(n->getEntry()->getName()==r->getEntry()->getName()){

        return false;
}

else if(strcmp(n->getEntry()->getName().c_str(),r->getEntry()->getName().c_str())<0){

    if(r->getLeft()==NULL){

        r->setLeft(n);

        n->setParent(r);

        //n->setLeft(NULL);

        //n->setRight(NULL);

        return true;
    }
    else{

       return insert_bst(n,r->getLeft());
    }
}

else if(strcmp(n->getEntry()->getName().c_str(),r->getEntry()->getName().c_str())>0){

    if(r->getRight()==NULL){

        r->setRight(n);

        n->setParent(r);

        //n->setLeft(NULL);

        //n->setRight(NULL);

        return true;
    }
    else{

       return insert_bst(n,r->getRight());
    }
}
}
//insert nodes ***************************************************************************************************************
bool TreeDB::insert(DBentry* newEntry){

TreeNode* treenodes=new TreeNode(newEntry);

if(treenodes==NULL){return false;}

if(root==NULL){

root=treenodes;

//treenodes->setLeft(NULL);

//treenodes->setRight(NULL);

cout<<"Success"<<endl;

//treenodes=NULL;

//delete treenodes;

return true;
}



bool success;

success=insert_bst(treenodes,root);

if(success){

    cout<<"Success"<<endl;

    return true;}

else{

    cout<<"Error: entry already exists"<<endl;

    return false;}

}



//helper function of find nodes*****************************************************************************************************
DBentry* TreeDB::find_bst(TreeNode* r,string name){

TreeNode* temp=r;

if(temp==NULL){return NULL;}

else if(temp->getEntry()->getName()==name){

    probesCount++;

    return temp->getEntry();
}
else if(strcmp(name.c_str(),temp->getEntry()->getName().c_str())<0){

    probesCount++;

    return find_bst(temp->getLeft(),name);
}
else{
    probesCount++;
    return find_bst(temp->getRight(),name);}
}
//find nodes*****************************************************************************************************
DBentry* TreeDB::find(string name){

probesCount=0;

DBentry* entry=find_bst(root,name);

return entry;
}




//**************************************************************************************************************************
TreeNode* TreeDB::searchnode(TreeNode* r,string name){

TreeNode* temp=r;

while(temp!=NULL){

    if(temp->getEntry()->getName()==name){return temp;}

    else if(strcmp(name.c_str(),temp->getEntry()->getName().c_str())<0){

        temp=temp->getLeft();
    }
    else if(strcmp(name.c_str(),temp->getEntry()->getName().c_str())>0){temp=temp->getRight();}
}

return NULL;
}

TreeNode* TreeDB::maxleftn(TreeNode* n){

    TreeNode* temp=n;

while(temp!=NULL&&temp->getRight()!=NULL){

    temp=temp->getRight();
}

return temp;
}

//**************************************************************************************************************************
bool TreeDB::remove(string name){

TreeNode* maxleft;

//find the position of node
TreeNode* temp=searchnode(root,name);

if(temp==NULL){return false;}

//if the left and right child of the node is NULL
else if(temp->getLeft()==NULL&&temp->getRight()==NULL){

    if(temp==root){

    root=NULL;

    temp->setParent(NULL);

    delete temp;

    //cout<<"Success"<<endl;

    return true;}

    else{

    if(temp->getParent()->getLeft()==temp){

        temp->getParent()->setLeft(NULL);

        temp->setParent(NULL);}

    else{

        temp->getParent()->setRight(NULL);

        temp->setParent(NULL);}

    delete temp;

    //cout<<"Success"<<endl;

    return true;
}
}


else if(temp->getLeft()!=NULL&&temp->getRight()!=NULL){

    maxleft=maxleftn(temp->getLeft());

    if(maxleft->getLeft()==NULL){

        temp->getEntry()->setName(maxleft->getEntry()->getName());

        temp->getEntry()->setIPaddress(maxleft->getEntry()->getIPaddress());

        temp->getEntry()->setActive(maxleft->getEntry()->getActive());

        if(maxleft->getParent()->getLeft()==maxleft){

            maxleft->getParent()->setLeft(NULL);}

        else{

            maxleft->getParent()->setRight(NULL);}

        maxleft->setParent(NULL);

        delete maxleft;

        //cout<<"Success"<<endl;

        return true;
    }


    else if(maxleft->getLeft()!=NULL){

        temp->getEntry()->setName(maxleft->getEntry()->getName());

        temp->getEntry()->setIPaddress(maxleft->getEntry()->getIPaddress());

        temp->getEntry()->setActive(maxleft->getEntry()->getActive());

        if(maxleft->getParent()->getLeft()==maxleft){

            maxleft->getParent()->setLeft(maxleft->getLeft());}

        else{

            maxleft->getParent()->setRight(maxleft->getLeft());}


        maxleft->getLeft()->setParent(maxleft->getParent());

        maxleft->setParent(NULL);

        maxleft->setLeft(NULL);

        delete maxleft;

        //cout<<"Success"<<endl;

        return true;
    }
}


else{

    if(temp==root){

        if(temp->getLeft()!=NULL){

        root=temp->getLeft();

        temp->setLeft(NULL);

        root->setParent(NULL);
        }
        else{

        root=temp->getRight();

        temp->setRight(NULL);

        root->setParent(NULL);

        }
        delete temp;

        //cout<<"Success"<<endl;

        return true;
    }

    else if(temp->getRight()!=NULL){

    if(temp->getParent()->getLeft()==temp){temp->getParent()->setLeft(temp->getRight());}

    else{temp->getParent()->setRight(temp->getRight());}

    temp->getRight()->setParent(temp->getParent());

    temp->setRight(NULL);

    temp->setParent(NULL);

    delete temp;

    //cout<<"Success"<<endl;

    return true;}

    else if(temp->getLeft()!=NULL){

    if(temp->getParent()->getLeft()==temp){temp->getParent()->setLeft(temp->getLeft());}

    else{temp->getParent()->setRight(temp->getLeft());}

    temp->getLeft()->setParent(temp->getParent());

    temp->setLeft(NULL);

    temp->setParent(NULL);

    delete temp;

    //cout<<"Success"<<endl;

    return true;
    }
}
}




//**************************************************************************************************************************
/*void TreeDB::clean(TreeNode* r){

while(r!=NULL){
TreeNode* temp=r;
    remove(temp->getEntry()->getName());
}


if(r==NULL){return;}

else if(r->getLeft()!=NULL)clean(r->getLeft());

 //return;
else if(r->getRight()!=NULL)clean(r->getRight());

else if(r->getLeft()!=NULL&&r->getRight()!=NULL){

 r->setParent(NULL);

 delete r->getEntry();

 delete r;

 r=NULL;

 return;
 }
//if(r->getParent()->getLeft()==r){r->getParent()->setLeft(NULL);}

//else{r->getParent()->setRight(NULL);}

}*/


void TreeDB::clear(){

while(root!=NULL){

    remove(root->getEntry()->getName());
}
}





//**************************************************************************************************************************
void TreeDB::printProbes() const{

cout<<probesCount<<endl;
}



//**************************************************************************************************************************
int TreeDB::cActive (const TreeNode* r)const{

int sum=0;

if(r==NULL){return 0;}

else{
    if(r->getLeft()!=NULL){sum=cActive(r->getLeft());}

    if(r->getEntry()->getActive()){sum++;}

    if(r->getRight()!=NULL){sum+=cActive(r->getRight());}

    return sum;
}
}
void TreeDB::countActive () const{

cout<<cActive(root)<<endl;
}




//helper function for printing all nodes//**********************************************************************************
void TreeDB::printall(const TreeNode* r)const
{
    string status;

if(r==NULL){return;}

else{//cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    if(r->getLeft()!=NULL){printall(r->getLeft());}


    if(r->getEntry()->getActive()){status="active";}

    else{status="inactive";}

    cout<<r->getEntry()->getName()<<" : "<<r->getEntry()->getIPaddress()<<" : "<<status<<endl;

    if(r->getRight()!=NULL){printall(r->getRight());}
}
}

//print all nodes//**************************************************************************************************************************
ostream& operator<< (ostream& out, const TreeDB& rhs){

rhs.printall(rhs.root);

return out;
}





