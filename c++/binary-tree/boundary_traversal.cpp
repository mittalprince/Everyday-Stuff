/* 
Boundary Traversal of binary tree

Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. 
For example, boundary traversal of the following tree is “20 8 4 10 14 25 22”

Problem statement link  https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left=nullptr, *right=nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void left_most_subtree(node *root){
	// if(root = nullptr)
	// 	return ;
	if(root){
	if(root->left){
		cout<<root->data<<" ";
		//root = root->left;
		left_most_subtree(root->left);
	}
	else if(root->right){
		cout<<root->data;
		//root = root->right;
		left_most_subtree(root->right);
		}
	}
}

void right_most_subtree(node *root){
	
	if(root){
	if(root->right){
		
		//root = root->left;
		right_most_subtree(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left){
		
		//root = root->right;
		right_most_subtree(root->left);
		cout<<root->data;
		}
	}
}

void print_leaves_nodes(node *root){
	// if(root = nullptr)
	// 	return ;
	if(root){

		print_leaves_nodes(root->left);
		if(root->left == nullptr && root->right == nullptr)
			cout<<root->data<<" ";
		print_leaves_nodes(root->right);
	}
}
void boundary_traversal(node *root){
	// if(root == nullptr)
	// 	return ;

	if(root){
		cout<<root->data<<" ";
		left_most_subtree(root->left);
		print_leaves_nodes(root->left);
		print_leaves_nodes(root->right);
		right_most_subtree(root->right);
	}

}

int main(){

	struct node *root         = newNode(1);
    root->left                = newNode(2);
    root->left->left          = newNode(3);
    root->left->right         = newNode(4);
    root->left->right->left   = newNode(5);
    root->left->right->right  = newNode(6);
   // root->right               = newNode(22);
    //root->right->right        = newNode(25);
 
    boundary_traversal( root );
    cout<<endl;
 
    return 0;
}