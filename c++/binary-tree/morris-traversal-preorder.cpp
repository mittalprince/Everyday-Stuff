/* 
Morris traversal for Preorder

Using Morris Traversal, we can traverse the tree without using stack and recursion. 
The algorithm for Preorder is almost similar to Morris traversal for Inorder.

1...If left child is null, print the current node data. Move to right child.
….Else, Make the right child of the inorder predecessor point to the current node. Two cases arise:
………a) The right child of the inorder predecessor already points to the current node. Set right child to NULL. 
	  Move to right child of current node.
………b) The right child is NULL. Set it to current node. Print current node’s data and move to left child of 
	  current node.
2...Iterate until current node is not NULL.

Problem statement link https://www.geeksforgeeks.org/morris-traversal-for-preorder/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr;
	node *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void morris_traversal_preorder(node *root){

	// if(root == nullptr)
	// 	return;

	while(root){

		if(root->left == nullptr){
			cout<<root->data<<" ";
			root = root->right;
		}
		else{

			node *current = root->left;
			while(current->right && current->right != root)
				current = current->right;

			if(current->right == root){
				current->right = nullptr;
				root = root->right;
			}
			else{
				cout<<root->data<<" ";
				current->right = root;
				root = root->left;
			}
		}
	}

}

int main(){

	node* root = newNode(1); 
    root->left = newNode(2);       
    root->right = newNode(3);      
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    
    morris_traversal_preorder(root);
    cout<<endl;

	return 0;
}