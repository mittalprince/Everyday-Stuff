/* 
Merge Two Binary Trees by doing Node Sum (Recursive and Iterative)

Given two binary trees. We need to merge them into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the non-null node will be used as the node of new tree.

Problem statement link https://www.geeksforgeeks.org/merge-two-binary-trees-node-sum/

*/

#include<iostream>

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

node* merge_tree(node *root1, node *root2){

	if(root1 == nullptr)
		return root2;

	if(root2 == nullptr)
		return root1;

	root1->data += root2->data;
	
	root1->left = merge_tree(root1->left, root2->left);
	root1->right = merge_tree(root1->right, root2->right);

	return root1;
}

void inorder(node *root){

	if(root == nullptr)
		return ;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}

int main(){

	node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(6);
 
    node *root2 = newNode(4);
    root2->left = newNode(1);
    root2->right = newNode(7);
    root2->left->left = newNode(3);
    root2->right->left = newNode(2);
    root2->right->right = newNode(6);

    node *root = merge_tree(root1,root2);

    cout<<"Merge Binaary tree \n";
    inorder(root);
    cout<<endl;
 


	return 0;
}