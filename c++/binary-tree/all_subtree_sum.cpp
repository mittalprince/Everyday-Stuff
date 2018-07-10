/* 
Count subtrees that sum up to a given value x

Given a binary tree containing n nodes. The problem is to count subtress 
having total node’s data sum equal to a given value x.

Problem statement link https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/

*/


#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* getNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp; 
}

void sum_postorder(node *root, int x, int &count){

	if(root == nullptr)
		return ;

	sum_postorder(root->left, x, count);
	sum_postorder(root->right, x, count);

	if(root->left != nullptr)
		root->data += root->left->data;

	if(root->right != nullptr)
		root->data += root->right->data;

	if(root->data == x) 
		count++;
}

int main(){

	node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int x = 7;
    int count =0;

    sum_postorder(root, x, count);

    cout<<count<<endl;


	return 0;
}