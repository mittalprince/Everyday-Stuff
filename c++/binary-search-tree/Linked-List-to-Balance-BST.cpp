
/* 
Sorted Linked List to Balanced BST

Given a Singly Linked List which has data members sorted in ascending order. 
Construct a Balanced Binary Search Tree which has same data members as the given Linked List. 

Problem statement link https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

*/

#include<iostream>
#include<list>

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

node* linked_list_to_BST(auto& it, int n){

	if(n <= 0)
		return nullptr;

	node *left = linked_list_to_BST(it, n/2);

	node *root = newNode(*it);
	root->left = left;

	it++;

	root->right = linked_list_to_BST(it, n-(n/2)-1);

	return root;
}

void preorder(node *root){

	if(root == nullptr)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}

int main(){

	list<int> l {1,2,3,4,5,6,7};

	int n = l.size();
	auto it= l.begin();
	node *root = linked_list_to_BST(it, n);

	preorder(root);
	cout<<endl;

	return 0;

}