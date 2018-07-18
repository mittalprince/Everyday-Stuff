/* 
Binary Tree to Binary Search Tree Conversion

Given a Binary Tree, convert it to a Binary Search Tree. 
The conversion must be done in such a way that keeps the original structure of Binary Tree.

Problem statement link https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

*/ 

#include<iostream>
#include<algorithm>
#include<vector>

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

void inorder(node *root, vector<int>& v){

	if(root == nullptr)
		return ;

	inorder(root->left, v);
	v.push_back(root->data);
	inorder(root->right, v);

}

void inorderTraversal(node* &root, vector<int>& v, int& index){

	if(root == nullptr)
		return;

	inorderTraversal(root->left, v, index);
	root->data = v.at(index);
	index++;
	inorderTraversal(root->right, v, index);

}

void Inorder(node *root){

	if(root == nullptr)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main(){
	struct node *root = nullptr;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    int index =0;
    vector<int> v;
    inorder(root, v);
    Inorder(root);
    cout<<endl;
    sort(v.begin(),v.end());
    inorderTraversal(root, v, index);
    Inorder(root);
    cout<<endl;

    return 0;
}