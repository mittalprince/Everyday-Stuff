/* 
Print Postorder traversal from given Inorder and Preorder traversals

Given Inorder and Preorder traversals of a binary tree, print Postorder traversal. */


#include<iostream>

using namespace std;

struct node{
	int data;
	node *left, *right;
};

struct node *newNode(int key){
	struct node *newnode = new node;
	newnode->data =key;
	newnode->left =nullptr;
	newnode->right= nullptr;

	return newnode;
}

int find(int inorder[], int pre, int n){
	for(int i=0;i<n;i++){
		if(inorder[i] == pre){
			return i;
		}

	}
	return -1;
}

void postorder(int inorder[], int preorder[], int size){

	int root = find(inorder, preorder[0], size);

	if(root != 0){
		postorder(inorder, preorder+1 , root);
	}
	if(root != size-1){
		postorder(inorder+root+1, preorder+root+1, size-root-1);
	}

	cout<<preorder[0]<<" ";
}

int main(){
	int inorder[] = {4, 2, 5, 1, 3, 6};
	int preorder[] = {1, 2, 4, 5, 3, 6};
	int size = sizeof(inorder)/sizeof(inorder[0]);

	postorder(inorder,preorder, size);
	cout<<endl;

	return 0;
}