/* 
Modify a binary tree to get preorder traversal using right pointers only

Given a binary tree. Modify it in such a way that after modification you can have a preorder 
traversal of it using only the right pointers. During modification, you can use right as well as left pointers. 

Problem statement link https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/

*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right= nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void make_skewed_tree(node *root){

	if(root){
		make_skewed_tree(root->right);

		if(root->left){
		make_skewed_tree(root->left);
		node * rp = root->right;
		node * lp = root->left;

		root->left = nullptr;
		root->right = lp;

		while(lp->right){
			lp = lp->right;
		}
		lp->right = rp;
		}

		return ;
	}
}

void print_tree(struct node* root){
    if(root==NULL)
      return;

    cout<<root->data<<endl;
    preTraversal(root->right);
}


int main(){
	struct node *root         = newNode(1);
    root->left                = newNode(2);
    root->left->left          = newNode(4);
    root->left->right         = newNode(5);
    root->right   			  = newNode(3);
    root->right->right  	  = newNode(7);
    root->right->left  		  = newNode(6);

    make_skewed_tree(root);
    print_tree(root);

    return 0;
}