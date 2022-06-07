// bst.cpp
// CS24 Final Exam
// Implements class bst
// YOUR NAME(S), DATE

#include "bst.h"

#include <iostream>
using std::cout;



bst::bst(vector<int>&v){
    for (int i : v) {
        insert(i);
    }
}

bst::~bst(){
    clear(this->root);
}



bool bst::insert(int value) {

    if (root == nullptr){
        root = new bstNode(value);
        return true;
    }else{
        return insert(value, root);
    }

    return false; 

}


// recursive helper for insert (assumes n is never 0)

bool bst::insert(int value, bstNode *n) {

    if(value < n->info){
        if(n->left == nullptr){
            n->left = new bstNode(value);
            n->left->parent = n;
            return true;
        } else {
            return insert(value, n->left);
        }
    } else if (value > n->info) {
        if (n->right == nullptr){
            n->right = new bstNode(value);
            n->right->parent = n;
            return true;
        } else {
            return insert(value, n->right);
        }
    } else {
        return false;
    }

}


void bst::deleteSubtree(int key){

}
int bst::countLeaves(bstNode *n) const{
    if (!this->root) return -1;
    if (!n->right && !n->left) {
        return 1;
    } else if (n->right && n->left) {
        return countLeaves(n->right) + countLeaves(n->left);
    } else if (!n->right) {
        return countLeaves(n->left);
    } else if (!n->left) {
        return countLeaves(n->right);
    }
    return 0;
    
}
int bst::countParentsWithTwoChildren(bstNode *n) const{
    if (!this->root) return -1;
    if (!n->right && !n->left) {
        return 0;
    } else if (n->right && !n->left) {
        return countParentsWithTwoChildren(n->right);
    } else if (n->left && !n->right) {
        return countParentsWithTwoChildren(n->left);
    } else if (n->left && n->right) {
        return 1 + countParentsWithTwoChildren(n->left) + countParentsWithTwoChildren(n->right);
    }
    return 0;
    
}
int bst::height(bstNode *n) const{
    if (!this->root) return -1;
    else {
        if (!n->right && !n->left) {
            return 0;
        } else if (n->right) {
            return 1 + height(n->right);
        } else if (n->left) {
            return 1 + height(n->left);
        } else if (n->right && n->left) {
            if (height(n->right) > height(n->left)) {
                return 1 + height(n->right);
            } else {
                return 1 + height(n->left);
            }
        }
    }
    return 0;
}
void bst::outputPreOrder(bstNode *n, vector<int>& output) const{
    if (!this->root) return;
    output.insert(output.begin() + output.size() - 1, root->info);
    if (n->left) outputPreOrder(n->left, output);
    if (n->right) outputPreOrder(n->right, output);
    return;
}
void bst::outputInOrder(bstNode *n, vector<int>& output) const{
    if (!this->root) return;
    if (n->left) outputPreOrder(n->left, output);
    output.insert(output.begin() + output.size() - 1, root->info);
    if (n->right) outputPreOrder(n->right, output);
    return;
}

typename bst::bstNode* bst::getNodeFor(int value, bstNode* n) const{
    while (n != nullptr) {
        if (value == n->info) {
            return n; 
        }
        else if (value < n->info) {
            return getNodeFor(value, n->left);
        } else {
            return getNodeFor(value, n->right);
        }
    }
    return nullptr; // Node doesn't exist in tree
}

void bst::clear(bstNode *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}