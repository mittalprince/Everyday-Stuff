/* 
Find the maximum path sum between two leaves of a binary tree

Given a binary tree in which each node element contains a number. 
Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root. For example, 
in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10). Expected time complexity is O(n).

Problem statement link https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

*/

#include<iostream>
#include<climits>
#include<algorithm>

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

int global_sum = INT_MIN;

int max_path_sum(node *root){
	
	if(root == nullptr)
		return 0;

	int left = max_path_sum(root->left);
	int right = max_path_sum(root->right);

	if(global_sum < (root->data +left+right))
		global_sum = root->data +left+right;

	return max(root->data+left, root->data+right);

}

int main(){

	struct node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);

    int ans  = max_path_sum(root);

    cout<<"Max pathsum of given binary tree is "<<global_sum<<endl;

	return 0;
}