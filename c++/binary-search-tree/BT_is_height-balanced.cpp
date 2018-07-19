/* 
How to determine if a binary tree is height-balanced?

A tree where no leaf is much farther away from the root than any other leaf. Different balancing schemes allow different definitions of “much farther” 
and different amounts of work to keep them balanced.

Consider a height-balancing scheme where following conditions should be checked to determine if a binary tree is balanced.
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.

The above height-balancing scheme is used in AVL trees. The diagram below shows two trees, 
one of them is height-balanced and other is not. The second tree is not height-balanced because height of left subtree is 2 more than height of right subtree.

Problem statment link  https://www.geeksforgeeks.org/?p=5230

*/

//Problem Statement -- https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* temp =  new node;
    temp->key = item;
    temp->left = temp->right = nullptr;

    return temp;
}

int isBalanced(node* root, bool& flag) {
    if(root == nullptr)
        return 0;
    
    int l = isBalanced(root->left, flag);
    int r = isBalanced(root->right, flag);

    if(abs(l-r) > 1) {
        flag = false;
    }

    return 1 + max(l, r);
}

int main() {
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    bool flag = true;
    isBalanced(root, flag);

    if(flag)
        cout<<"Balanced\n";
    else    
        cout<<"Unbalanced\n";

    return 0;
}