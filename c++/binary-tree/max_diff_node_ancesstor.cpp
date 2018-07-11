/* 
Maximum difference between node and its ancestor in Binary Tree

Given a binary tree, we need to find maximum value we can get by subtracting value of node B from value of node A, 
where A and B are two nodes of the binary tree and A is an ancestor of B. Expected time complexity is O(n).

Problem statement link https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/

*/

#include<iostream>
#include<climits>

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

int max_difference = INT_MIN;

int max_diff(node *root){

	if(root == nullptr)
		return INT_MAX;

	int left = max_diff(root->left);
	int right = max_diff(root->right);

	if(max_difference < max(root->data - left, root->data - right))
		max_difference = max(root->data - left, root->data - right);

	return min(root->data, min(left,right));
}

int main(){

	node *root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

	int diff = max_diff(root);
	cout<<max_difference<<endl;

	return 0;
}