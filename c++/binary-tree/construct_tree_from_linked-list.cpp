/* 
Construct Complete Binary Tree from its Linked List Representation

Given Linked List Representation of Complete Binary Tree, construct the Binary tree. 
A complete binary tree can be represented in an array in the following approach.

If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively.
Suppose tree is represented by a linked list in same way, how do we convert this into normal 
linked representation of binary tree where every node has data, left and right pointers? In the linked list 
representation, we cannot directly access the children of the current node unless we traverse the list.

Problem statement link https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/ */


#include<iostream>
#include<list>
#include<queue>
#include<iterator>

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

void convert_list_to_binary_tree(node* &root,list<int> l){

	if(l.empty())
		return ;
	queue<node* >q;

	root = newNode(*l.begin());
	q.push(root);

	//l = l.front();
	auto it = l.begin();
	it++;
	//l.pop_front();

	while(it != l.end()){

		node *current = q.front();
		q.pop();

		if(it != l.end()){
			current->left = newNode(*it);
			q.push(current->left);
			//l = l->next;
			//l.pop_front();
		it++;
		}

		if(it != l.end()){
			current->right = newNode(*it);
			q.push(current->right);
			//l = l->next;
			//l.pop_front();
			it++;
		}

	}
}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
	list<int> l ;
	l.push_back(10);  
    l.push_back(12);
    l.push_back(15);
    l.push_back(25);
    l.push_back(30);
    l.push_back(36);
    l.push_back(35);

    node *root = nullptr;

    convert_list_to_binary_tree(root, l);
    inorderTraversal(root);

    cout<<endl;
    return 0;

}