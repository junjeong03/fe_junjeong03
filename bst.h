// bst.h
// Binary search tree header file for CS 24 final exam

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
using namespace std;

class bst {

 public:
    
    // DO NOT CHANGE THE GIVEN PUBLIC OR PRIVATE METHODS
    bst(vector<int>&v); 
    ~bst();
     
    int countLeaves() const { return countLeaves(root); }
    int countParentsWithTwoChildren() const {return countParentsWithTwoChildren(root);};
    int height() const {return height(root);};
    void outputPreOrder(vector<int>& output) const {return outputPreOrder(root, output);};
    void outputInOrder(vector<int>& output) const {return outputInOrder(root, output);};
    bool insert(int key);

    // IMPLEMENT THE FOLLOWING METHOD(s): both public and helper functions
    
    //Deletes the subtree in the BST that is rooted at the given key value
    void deleteSubtree(int key); 
    
 private:

    struct bstNode {
	int info;
	bstNode *left, *right, * parent;
    bstNode(int v=0) : info(v), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    bstNode *root;
    // returns the number of leaf nodes
    int countLeaves(bstNode *root) const;
    // returns the number of parents with two children
    int countParentsWithTwoChildren(bstNode *root) const;
    // returns the height of the bst. Note height of an empty bst is -1
    int height(bstNode *root) const;
    //stores the result of a preorder traversal in the vector output
    void outputPreOrder(bstNode *root, vector<int>& output) const;
    //stores the result of an inorder traversal in the vector output
    void outputInOrder(bstNode *root, vector<int>& output) const;

    //METHODS ALREADY IMPLEMENTED
    bstNode* getNodeFor(int value, bstNode* n) const;
    bool insert(int value, bstNode *n);
    
   
    //Add any new helper methods here

};

#endif