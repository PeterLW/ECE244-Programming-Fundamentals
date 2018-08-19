#include <iostream>
#include <string.h>
#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"
using namespace std;

TreeDB::~TreeDB(){
if(root!=NULL){clear();}
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

        n->setLeft(NULL);

        n->setRight(NULL);

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

        n->setLeft(NULL);

        n->setRight(NULL);

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

treenodes->setLeft(NULL);

treenodes->setRight(NULL);

cout<<"Success"<<endl;

return true;
}

else{

bool success;

success=insert_bst(treenodes,root);

if(success){

    cout<<"Success"<<endl;

    return true;}

else{

    cout<<"Error: entry already exists"<<endl;

    return false;}
}
}



//helper function of find nodes*****************************************************************************************************
DBentry* TreeDB::find_bst(TreeNode* r,string name){

if(r==NULL){return NULL;}

if(r->getEntry()->getName()==name){

    probesCount++;

    return r->getEntry();
}
else if(strcmp(name.c_str(),r->getEntry()->getName().c_str())<0){

    probesCount++;

    return find_bst(r->getLeft(),name);
}
else{
    probesCount++;
    return find_bst(r->getRight(),name);}
}
//find nodes*****************************************************************************************************
DBentry* TreeDB::find(string name){

probesCount=0;

DBentry* entry=find_bst(root,name);

return entry;
}




//**************************************************************************************************************************
TreeNode* TreeDB::searchnode(TreeNode* r,string name){

while(r!=NULL){

    if(r->getEntry()->getName()==name){return r;}

    else if(strcmp(name.c_str(),r->getEntry()->getName().c_str())<0){
        r=r->getLeft();
    }
    else if(strcmp(name.c_str(),r->getEntry()->getName().c_str())>0){r=r->getRight();}
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

if(temp==NULL){cout<<"Error: entry does not exist"<<endl;return false;}

//if the left and right child of the node is NULL
if(temp->getLeft()==NULL&&temp->getRight()==NULL){

    if(temp==root){root=NULL;delete temp;}

    else{

    if(temp->getParent()->getLeft()==temp){temp->getParent()->setLeft(NULL);}

    else{temp->getParent()->setRight(NULL);}

    delete temp;

    cout<<"Success"<<endl;

    return true;
}
}


else if(temp->getLeft()!=NULL&&temp->getRight()!=NULL){

    maxleft=maxleftn(temp);

    if(maxleft->getRight()==NULL){

        temp->getEntry()->setName(maxleft->getEntry()->getName());

        temp->getEntry()->setIPaddress(maxleft->getEntry()->getIPaddress());

        temp->getEntry()->setActive(maxleft->getEntry()->getActive());

        if(maxleft->getParent()->getLeft()==maxleft){maxleft->getParent()->setLeft(NULL);}

        else{maxleft->getParent()->setRight(NULL);}

        delete maxleft;

        cout<<"Success"<<endl;

        return true;
    }


    else {

        temp->getEntry()->setName(maxleft->getEntry()->getName());

        temp->getEntry()->setIPaddress(maxleft->getEntry()->getIPaddress());

        temp->getEntry()->setActive(maxleft->getEntry()->getActive());

        if(maxleft->getParent()->getLeft()==maxleft){maxleft->getParent()->setLeft(maxleft->getRight());}

        else{maxleft->getParent()->setRight(maxleft->getRight());}

        maxleft->setRight(NULL);

        delete maxleft;

        cout<<"Success"<<endl;

        return true;
    }
}


else{

    if(temp->getRight()!=NULL){

    if(temp->getParent()->getLeft()==temp){temp->getParent()->setLeft(temp->getRight());}

    else{temp->getParent()->setRight(temp->getRight());}

    temp->setRight(NULL);

    delete temp;

    cout<<"Success"<<endl;

    return true;}

    else{
    if(temp->getParent()->getLeft()==temp){temp->getParent()->setLeft(temp->getLeft());}

    else{temp->getParent()->setRight(temp->getLeft());}

    temp->setLeft(NULL);

    delete temp;

    cout<<"Success"<<endl;

    return true;
    }
}
}




//**************************************************************************************************************************
void TreeDB::clean(TreeNode* r){

if(r==NULL){return;}

 clean(r->getLeft());

 clean(r->getLeft());

 delete root;

 root=NULL;

 return;
}
void TreeDB::clear(){

clean(root);
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
    //else{status="inactive";}

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

else{
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





