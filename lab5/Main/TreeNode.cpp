#include <iostream>
#include <string>
#include "DBentry.h"
#include "TreeNode.h"
using namespace std;



TreeNode::~TreeNode(){}



TreeNode::TreeNode(DBentry* _entryPtr){

    entryPtr=_entryPtr;

    left=NULL;

    right=NULL;

    parent=NULL;
}




void TreeNode::setLeft(TreeNode* newLeft){

left=newLeft;
}




void TreeNode::setRight(TreeNode* newRight){

right=newRight;
}




void TreeNode::setParent(TreeNode* parent_){

parent=parent_;
}




TreeNode* TreeNode::getLeft() const{

return left;
}




TreeNode* TreeNode::getRight() const{

return right;
}




DBentry* TreeNode::getEntry() const{

return entryPtr;
}




TreeNode* TreeNode::getParent(){

return parent;
}



