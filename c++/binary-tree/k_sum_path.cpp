/* 
Print all k-sum paths in a binary tree

A binary tree and a number k are given. Print every path in the tree with sum 
of the nodes in the path as k.
A path can start from any node and end at any node and must be downward only,
 i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

 Problem statement link https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

 */

#include<iostream>
#include<vector>

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

void print_vector(const vector<int>& v, int j){

	for(int i=j;i<v.size();i++)
		cout<<v[i]<<" ";

	cout<<endl;
}

void print_path(node *root, vector<int>& v, int sum){

	if(root == nullptr)
		return;

	v.push_back(root->data);

	print_path(root->left, v, sum);
	print_path(root->right, v, sum);

	int S =0;
	for(int i = v.size()-1;i>=0; i--){
		S += v[i];

		if(S == sum){
			print_vector(v, i);
		}
	}

	v.pop_back();
}

int main(){

	node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);

    vector<int> v;
    int k =5;

	print_path(root, v, k); 

	return 0;
}