/* 
Convert a given tree to its Sum Tree

Given a Binary Tree where each node has positive and negative values. 
Convert this to a tree where each node contains the sum of the left and 
right sub trees in the original tree. The values of leaf nodes are changed to 0.

Problem statement link https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr ;
};

struct node* newNode(int data){
	node *temp =new node;
	temp->data = data;

	return temp;
}

int sum_tree(node *root){

	if(root == nullptr)
		return 0;

	int old_val = root->data;

	root->data = sum_tree(root->left) + sum_tree(root->right);

	return root->data + old_val;
}

void inorder(node *root){

	if(root == nullptr)
		return;

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}

int main(){

	node* root = newNode(10);
  	root->left = newNode(-2);
  	root->right = newNode(6);
  	root->left->left = newNode(8);
  	root->left->right = newNode(-4);
  	root->right->left = newNode(7);
  	root->right->right = newNode(5);

  	sum_tree(root);
  	inorder(root);

  	cout<<endl;

  	return 0;

}
