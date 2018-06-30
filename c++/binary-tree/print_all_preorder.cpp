/* 
Find all possible binary trees with given Inorder Traversal

Given an array that represents Inorder Traversal, find all possible Binary Trees 
with the given Inorder traversal and print their preorder traversals. */


#include<iostream>
#include<set>
#include<vector>

using namespace std;

struct node{
	int data;
	node *left, *right;
};

struct node *newNode(int key){
	struct node *newnode = new node;
	newnode->data = key;
	newnode->left = nullptr;
	newnode->right = nullptr;

	return newnode;
}

void preorder(node *root){
	if(root != nullptr){
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	}
}

vector<node *> print_all_preorder(int arr[], int start, int end){
	vector<node *> tree;

	if(start > end){
		tree.push_back(nullptr);
		return tree;
	}

	for(int i=start; i<=end; i++){

		vector<node *> ltree = print_all_preorder(arr, start, i-1);
		vector<node *> rtree = print_all_preorder(arr, i+1, end);

		for(int j=0; j<ltree.size(); j++){
			for(int k=0; k<rtree.size(); k++){

				node* root = newNode(arr[i]);
				root->left = ltree[j];
				root->right = rtree[k];

				tree.push_back(root);
			}
		}
	}
	return tree;
}

int main(){

	int arr[] = {1,2,3,4};
	int size = (sizeof(arr)/sizeof(arr[0]));

	vector<node *> root = print_all_preorder(arr,0,size-1);

	cout<<"All possibble preorder of given inorder"<<endl;
	cout<<root.size()<<endl;

	for(int i=0;i<root.size();i++){
		preorder(root[i]);
		cout<<endl;
	}

	return 0;
}