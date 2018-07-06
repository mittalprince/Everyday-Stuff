/* 
Convert a given Binary Tree to Doubly Linked List | Set 1

Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
The left and right pointers in nodes are to be used as previous and 
next pointers respectively in converted DLL. The order of nodes in DLL
 must be same as Inorder of the given Binary Tree. The first node of 
 Inorder traversal (left most node in BT) must be head node of the DLL.

 Problem statement link https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

 */


#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* t = new node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void inorder(node* root, vector<node *>& v) {
    if(root == nullptr)
        return;
    
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

void tree_to_doubly_linked_list(node*& root) {
    vector<node *> v;
    inorder(root, v);

    auto it = v.begin();
    
    (*it)->right = *(it+1);
    (*it)->left = nullptr;

    root = *it;

    for(it ; it != v.end()-1 ; ++it) {
        (*it)->right = *(it+1);
        (*it)->left = *(it-1);
    }

    (*it)->left = *(it-1);
    (*it)->right = nullptr;
}

void traverse_doubly_linked_list(node* root) {
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    traverse_doubly_linked_list(root->right);
}

int main() {

    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    tree_to_doubly_linked_list(root);

    traverse_doubly_linked_list(root);

    cout<<endl;

    return 0;
}