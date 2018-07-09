/* 
Check if a binary tree is subtree of another binary tree | Set 2

Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T.

The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, Tree1 is a subtree of Tree2. 

Problem statement link https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

*/


#include<iostream>
#include<string>

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

void store_inorder(node *root, string& i){

	if(root == nullptr){
		i.push_back('$');
		return;
	}

	store_inorder(root->left, i);
	i.push_back(root->data);
	store_inorder(root->right, i);

}

void store_preorder(node *root, string& p){

	if(root == nullptr){
		 p.push_back('$');
		 return ;
	}

	p.push_back(root->data);
	store_preorder(root->left,p);
	store_preorder(root->right, p);

}

bool is_subtree_exist(node *root, node *root1){

	// if(root == nullptr || root1 == nullptr)
	// 	return false;

	string i,p,I,P;

	store_inorder(root, I);
	store_inorder(root1, i);

	if(I.find(i) == string::npos)
		return false;

	store_preorder(root, P);
	store_preorder(root1, p);

	if(P.find(p) == string::npos)
		return false;

	else return true;
}

int main(){

	node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
    S->right->right = newNode('e');

    if(is_subtree_exist(T,S))
    	cout<<"YES"<<endl;

    else
    	cout<<"NO"<<endl;

    return 0;
}