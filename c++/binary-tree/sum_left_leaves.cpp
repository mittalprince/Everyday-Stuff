/* 
Find sum of all left leaves in a given Binary Tree

Given a Binary Tree, find sum of all left leaves in it. For example, sum of all left leaves in below Binary

Problem statement https://www.geeksforgeeks.org/find-sum-left-leaves-given-binary-tree/

*/


#include<iostream>

using namespace std;

struct node
{
	char data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(char data){

	node *temp = new node;
	temp->data = data;

	return temp;
}

int sum =0;

void sum_left_leaves(node *root, int flag){

	if(root == nullptr)
		return;

	if(root->left == nullptr && root->right == nullptr && flag ==1)
		sum += root->data;

	sum_left_leaves(root->left,1);

	sum_left_leaves(root->right, 0);
}

int main(){

	struct node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    sum_left_leaves(root, 0);

    cout<<sum<<endl;
	return 0;
}
