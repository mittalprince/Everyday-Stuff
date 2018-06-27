/*
Continuous Tree

A tree is Continuous tree if in each root to leaf path, absolute difference between keys of two adjacent is 1.
We are given a binary tree, we need to check if tree is continuous or not.
*/


#include<iostream>

using namespace std;

class node{
  int data;
  node *left, *right;

public:
  node(int key){
    data = key;
    left = nullptr;
    right = nullptr;
  }

  node*& leftnode(){
    return left;
  }
  node*& rightnode(){
    return right;
  }
  friend bool completion(node *root);
  ~node(){
    delete left;
    delete right;
  }

};

bool completion(node *root){
//  bool result;
  if(root == nullptr)
    return true;

  if(root->left == nullptr && root->right == nullptr)
    return true;

  if(root->right!= nullptr)
    return (abs(root->data - root->right->data) ==1) && completion(root->right);

   if(root->left!= nullptr)
    return  (abs(root->data - root->left->data) == 1) && completion(root->left);

    return  (abs(root->data - root->left->data)==1) && (abs(root->data - root->right->data)==1) && completion(root->left) && completion(root->right);

}


int main(){
  class node* root = nullptr;
  root = new node(3);
  root->leftnode() = new node(2);
  root->rightnode() = new node(4);
  root->leftnode()->leftnode() = new node(1);
  root->leftnode()->rightnode() = new node(3);
  //root->rightnode()->leftnode() = new node(15);
  root->rightnode()->rightnode() = new node(5);

  bool ans = completion(root);
  if(ans){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
  return 0;
}
