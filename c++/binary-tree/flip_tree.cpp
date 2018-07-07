/* 
Flip Binary Tree

Given a binary tree, the task is to flip the binary tree towards right direction that is clockwise. 
See below examples to see the transformation.

In the flip operation, left most node becomes the root of flipped tree and its parent become its r
ight child and the right sibling become its left child and same should be done for all left most nodes recursively.


Problem statement link  https://www.geeksforgeeks.org/flip-binary-tree/

*/


#include<iostream>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;

	temp->data = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

node * fliptree(node * root)
{
	if(root==nullptr)
	{
		return root;
	}
	if(root->left == nullptr && root->right == nullptr)
	{
		return root;
	}

	node * flippedroot = fliptree(root->left);

	root->left->left = root->right;
	root->left->right = root;
	root->left = root->right = nullptr;

	return flippedroot;
}

void inorder(node * root)
{
	if(root ==  nullptr)
	{
		return;
	}
	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}

int main()
{
	struct node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);
    root->right->left  = newNode(4);

    root = fliptree(root);

    inorder(root);

    return 0;

}