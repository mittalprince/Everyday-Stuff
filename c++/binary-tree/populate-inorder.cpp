/* 
Populate Inorder Successor for all nodes

Given a Binary Tree where each node has following structure, write a function to populate next 
pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
struct node
{
  int data;
  struct node* left;
  struct node* right;
  struct node* next;
}

*/

#include<iostream>
#include<vector>

using namespace std;

struct node{
	int data;
	node *left = nullptr;
	node *right = nullptr;
	node *next = nullptr;
};

struct node* newNode(int data){
	node *newnode = new node;
	newnode->data = data;

	return newnode;
}

void inorder(node *root, vector<node *>* v){

	if(root != nullptr){
		inorder(root->left, v);

		v->push_back(root);

		inorder(root->right, v);
	}
}

void inorder(node *root){
	if(root != nullptr){
		inorder(root->left);
		cout<<root->data;
		if(root->next != nullptr)
			cout<<" next-pointer "<<root->next->data<<endl;
		inorder(root->right);
	}
}

void populate_inorder(vector<node *> &v){
	for(int i=0; i<v.size()-1; i++){
		v[i]->next = v[i+1];
	}
}

int main(){
	node* root = newNode(1); 
    root->left = newNode(2);       
    root->right = newNode(3);      
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<node *> v;

    inorder(root, &v);
    populate_inorder(v);
    inorder(root);

    cout<<endl;

    return 0;
}