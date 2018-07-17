/* 
Binary Search Tree | Set 1 (Search and Insertion)

The following is definition of Binary Search Tree(BST) according to Wikipedia

Binary Search Tree, is a node-based binary tree data structure which has the following properties:

    The left subtree of a node contains only nodes with keys lesser than the node’s key.
    The right subtree of a node contains only nodes with keys greater than the node’s key.
    The left and right subtree each must also be a binary search tree.
    There must be no duplicate nodes.

Problem statement link https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

node* insert(node *root, int key){

	if(root == nullptr)
		return newNode(key);

	if(root->data > key)
		root->left = insert(root->left, key);

	else if(root->data < key)
		root->right = insert(root->right, key);


	return root;
}

void inorder(node *root){

	if(root == nullptr)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){

	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    cout<<endl;

	return 0;
}

