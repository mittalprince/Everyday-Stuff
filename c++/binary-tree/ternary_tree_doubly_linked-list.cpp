/* 
Create a Doubly Linked List from a Ternary Tree

Given a ternary tree, create a doubly linked list out of it.
 A ternary tree is just like binary tree but instead of having two nodes, 
 it has three nodes i.e. left, middle, right.

The doubly linked list should holds following properties –

    Left pointer of ternary tree should act as prev pointer of doubly linked list.
    Middle pointer of ternary tree should not point to anything.
    Right pointer of ternary tree should act as next pointer of doubly linked list.
    Each node of ternary tree is inserted into doubly linked list before its subtrees 
    and for any node, its left child will be inserted first, followed by mid and right child (if any).

For the above example, the linked list formed for below tree 
should be NULL <- 30 <-> 5 <-> 1 <-> 4 <-> 8 <-> 11 <-> 6 <-> 7 <-> 15 <-> 63 <-> 31 <-> 55 <-> 65 -> NULL

Problem statement link https://www.geeksforgeeks.org/create-doubly-linked-list-ternary-ree/

*/
 

#include<iostream>
#include<list>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr, *middle=nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data  =data;

	return temp;
}

void tree_to_doubly(node *root, list<int >* l){

	if(root== nullptr)
		return ;

	if(root){
		l->push_back(root->data);

		if(root->left != nullptr)
			tree_to_doubly(root->left, l);

		if(root->middle != nullptr)
			tree_to_doubly(root->middle, l);

		if(root->right != nullptr)
			tree_to_doubly(root->right, l);
	}
}

int main(){

	node* root = newNode(30);
 
    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);
 
    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);
 
    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);
 
    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);
 

	list<int > l;

	tree_to_doubly(root, &l);

	auto it = l.begin();

	while(it != l.end()){
		cout<< *it<<" ";
		it++;
	}
	return 0;

}