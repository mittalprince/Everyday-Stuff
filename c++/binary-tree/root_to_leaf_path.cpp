/*  Given a binary tree, print out all of its root-to-leaf paths one per line.

Problem statement link https://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/

*/


#include<iostream>
#include<vector>

using namespace std;

struct node
{
	char data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(char data){

	node *temp = new node;
	temp->data = data;

	return temp;
}

void print_vector(const vector<int> v){

	for(auto& y : v){
		cout<<y<<" ";
	}
	cout<<endl;
}

void root_to_leaf(node *root, vector<int> v){

	if(root == nullptr)
		return ;

	v.push_back(root->data);

	if(root->left == nullptr && root->right == nullptr){
		print_vector(v);
		return;
	}

	if(root->left != nullptr)
		root_to_leaf(root->left, v);

	if(root->right != nullptr)
		root_to_leaf(root->right, v);
}

int main(){

	struct node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 

  	vector<int> v;

  	root_to_leaf(root,v);

  	return 0;


}