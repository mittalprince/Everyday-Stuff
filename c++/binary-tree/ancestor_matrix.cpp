/* 
Construct Ancestor Matrix from a Given Binary Tree

Given a Binary Tree where all values are from 0 to n-1. Construct an ancestor matrix mat[n][n]. Ancestor matrix is defined as below.

mat[i][j] = 1 if i is ancestor of j
mat[i][j] = 0, otherwise

Problem statement link https://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/

*/


#include<iostream>
#include<climits>
#include<vector>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newnode(int data){
	node *temp = new node;
	temp->data  =data;

	return temp;
}

vector<vector<int> > arr(6, vector<int> (6,0));

int max_value_of_node(node *root){

	int max = INT_MIN;

	if(root){
	max_value_of_node(root->left);
	if(max < root->data)
		return root->data;
	max_value_of_node(root->right);

	return max;
	}
	else return 0;

}

void ancestor_matrix(node *root, int n){
	if(root == nullptr)
		return;

	ancestor_matrix(root->left, n);
	ancestor_matrix(root->right, n);

	if(root->left != nullptr){
		arr[root->data][root->left->data] = 1;

		for(int i=0;i<=n;i++){
			if(arr[root->left->data][i] == 1)
				arr[root->data][i] = 1;
		}
	}

	if(root->right != nullptr){
		arr[root->data][root->right->data] = 1;

		for(int i=0;i<=n;i++){
			if(arr[root->right->data][i] == 1)
				arr[root->data][i] = 1;
		}
	}
}

int main(){

	node *root        = newnode(5);
    root->left        = newnode(1);
    root->right       = newnode(2);
    root->left->left  = newnode(0);
    root->left->right = newnode(4);
    root->right->left = newnode(3);

    int n = max_value_of_node(root);

    int arr[n+1][n+1];
 
    ancestor_matrix(root, n);

    for(int i=0;i<=5;i++){
    	for(int j=0;j<=5;j++){
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }


	return 0;
}
