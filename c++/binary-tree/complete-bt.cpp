/*
Construct Complete Binary Tree from its Linked List Representation

Given Linked List Representation of Complete Binary Tree,
construct the Binary tree. A complete binary tree can be represented in an
array in the following approach. */

#include<iostream>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(){
  struct node *Node = new node;
  Node->left= NULL;
  Node->right = NULL;

  return Node;
}

void tree_from_array(int size,int arr[], int index, struct node*& root){
  if(index < size){
    root = newNode();
    root->data = arr[index];
    tree_from_array(size,arr,(2*index+1),root->left);
    tree_from_array(size,arr,(2*index+2),root->right);
  }
}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<endl;
    inorderTraversal(root->right);
}

int main(){
    int arr[6] = {10,12,15,25,30,36};
    int size  = (sizeof(arr)/sizeof(arr[0]));
    struct node* root = nullptr;
    tree_from_array(size,arr,0, root);
    inorderTraversal(root);

    return 0;

}
