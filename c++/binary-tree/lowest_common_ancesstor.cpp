/* 
Lowest Common Ancestor in a Binary Tree | Set 1

Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to 
find the least common ancestor.

Problem statment link https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

*/

#include<iostream>

using namespace std;

struct node{
	int key;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->key = data;

	return temp; 
}

node* find_LCA(node *root, int n1, int n2){	

	if(root == nullptr)
		return nullptr;

	if(root->key == n1 || root->key == n2)
		return root;

	node *left_lca = find_LCA(root->left, n1, n2);
	node *right_lca = find_LCA(root->right, n1, n2);

	if(left_lca != nullptr && right_lca != nullptr)
		return root;

	if(left_lca != nullptr && right_lca == nullptr)
		return left_lca;


	if(left_lca == nullptr && right_lca != nullptr)
		return right_lca;
}

int main(){

	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << find_LCA(root, 4, 5)->key<<endl;
    cout << "nLCA(4, 6) = " << find_LCA(root, 4, 6)->key<<endl;
    cout << "nLCA(3, 4) = " << find_LCA(root, 3, 4)->key<<endl;
    cout << "nLCA(2, 4) = " << find_LCA(root, 2, 4)->key<<endl;

	return 0;
}