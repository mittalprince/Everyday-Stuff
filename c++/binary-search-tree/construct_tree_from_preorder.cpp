/* 
Construct BST from given preorder traversal | Set 1

Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

Problem statement link https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

node* make_tree(node *root, int key){

	if(root == nullptr)
		return newNode(key);

	if(key < root->data)
		root->left = make_tree(root->left, key);

	else if(root->data < key)
		root->right = make_tree(root->right, key);

	return root;
}

void inorderTraversal(node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){

	struct node *root = nullptr;
	int preorder[] = {10, 5, 1, 7, 40, 50};

	for(int i=0; i< sizeof(preorder)/sizeof(int); i++){
		root = make_tree(root, preorder[i]);
	}

	inorderTraversal(root);

 	cout<<endl;

	return 0;

}