/* 
Check if removing an edge can divide a Binary Tree in two halves

Given a Binary Tree, find if there exist edge whose removal creates two trees of equal size.

Problem statement link https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/

*/


#include<iostream>

using namespace std;

struct node{

	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int key){

	node *temp = new node;
	temp->data = key;

	return temp;
}

int no_of_nodes(node *root){

	if(root == nullptr)
		return 0;

	return no_of_nodes(root->left) + no_of_nodes(root->right) + 1;
}

bool check_rec(node *root, int n){

	if(root == nullptr)
		return false;

	if( no_of_nodes(root) == n - no_of_nodes(root))
		return true;

	return check_rec(root->left, n) || check_rec(root->right, n);
}

bool check(node *root){

	int n = no_of_nodes(root);

	return check_rec(root, n);
}

int main(){

	struct node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->right->right = newNode(4);
 
    if(check(root))
    	cout<<"YES\n";

    else cout<<"NO"<<endl;
 
    return 0;
}