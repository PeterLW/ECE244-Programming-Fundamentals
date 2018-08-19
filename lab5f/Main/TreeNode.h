#ifndef _TREENODE_H
#define _TREENODE_H

#include "DBentry.h"

class TreeNode {

private:
    DBentry* entryPtr;

    TreeNode* parent;

    TreeNode* left;

    TreeNode* right;

public:
    // A useful constructor
    TreeNode(DBentry* _entryPtr);

    // the destructor
    ~TreeNode();

    // sets the left child of the TreeNode.
    void setLeft(TreeNode* newLeft);

    // sets the right child of the TreeNode
    void setRight(TreeNode* newRight);

    // gets the left child of the TreeNode.
    TreeNode* getLeft() const;

    // gets the right child of the TreeNode
    TreeNode* getRight() const;

    // returns a pointer to the DBentry the TreeNode contains.
    DBentry* getEntry() const;

   // sets the parent of the TreeNode
    void setParent(TreeNode* parent_);

    //gets the parent of the TreeNode.
    TreeNode* getParent();
};

#endif

