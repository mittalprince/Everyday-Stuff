/* 
Convert a Binary Tree into its Mirror Tree

Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) 
with left and right children of all non-leaf nodes interchanged.

Problem statement link  https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

*/


#include<iostream>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(int data){
  struct node *Node = new node;
  Node->data = data;
  Node->left= nullptr;
  Node->right = nullptr;

  return Node;
}

void make_mirror(node *root){

	if(root == nullptr)
		return ;

	node *temp = nullptr;

	make_mirror(root->left);
	make_mirror(root->right);

	temp = root->right;
	root->right = root->left;
	root->left = temp;

}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){

	struct node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 

  	inorderTraversal(root);

  	cout<<"Traversal of mirror tree"<<endl;

  	make_mirror(root);

  	inorderTraversal(root);

  	cout<<endl;
  	return 0;
}