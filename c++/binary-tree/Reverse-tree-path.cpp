/* 
Reverse tree path

Given a tree and a node data, your task to reverse the path till that particular Node.

Problem statement link https://www.geeksforgeeks.org/reverse-tree-path/

*/

#include<iostream>
#include<vector>

using namespace std;

struct node{

	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int key){

	node *temp = new node;
	temp->data = key;

	return temp;
}


void reverse_tree_path(node *root, vector<node* >& v ,int key){

	if(root == nullptr)
		return ;

	static bool flag = false;

	if(root->data == key)
		flag = true;

	if(!flag){
		reverse_tree_path(root->left, v, key);
	}


	if(flag){
		v.push_back(root);
	}

	if(!flag){
		reverse_tree_path(root->right, v, key);
		return;
	}

}

void vector_traverse(vector<node* >& v){

	if(v.empty())
		return ;

	int temp; 

	auto start = v.begin();
	auto last = v.end()-1;

	while(start < last){
		temp = (*start)->data;
		(*start)->data = (*last)->data;
		(*last)->data = temp;

		start++;
		last--;
	}

}

void inorder(node *root){

	if(root == nullptr)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){

	// Let us create binary tree shown in above diagram
    node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
 
    /*     7
         /    \
        6       5
       / \     / \
      4  3     2  1          */
 
    int data = 4;

    vector<node* > v;
 
    // Reverse Tree Path
    reverse_tree_path(root, v, data);

    vector_traverse(v);
 
    // Traverse inorder
    inorder(root);
    cout<<endl;
 

	return 0;
}