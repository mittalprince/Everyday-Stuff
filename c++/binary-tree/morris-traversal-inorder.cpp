/* 
Inorder Tree Traversal without recursion and without stack!

Using Morris Traversal, we can traverse the tree without using stack and recursion. 
The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, 
we first create links to Inorder successor and print the data using these links.

Problem statement link https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

*/


#include<iostream>

using namespace std;

struct node{
	int data;
	node *left, *right;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

void morris_traversal_inorder(node *root){
	if(root == nullptr)
		return;

	struct node *current, *pre;
	current = root;

	while(current != nullptr){

		if(current->left == nullptr){
			cout<<current->data<<" ";
			current = current->right;
		}

		else{

			pre = current->left;

			while(pre->right != nullptr && pre->right != current)
				pre = pre->right;

			if(pre->right == nullptr){
				pre->right = current;
				current = current->left;
			}

			else{
				pre->right = nullptr;
				cout<<current->data<<" ";
				current = current->right;
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
    
    morris_traversal_inorder(root);
    cout<<endl;

	return 0;
}