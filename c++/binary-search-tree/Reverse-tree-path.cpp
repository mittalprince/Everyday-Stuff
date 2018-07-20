/* 
Reverse a path in BST using queue

Given a binary search tree and a key, your task to reverse path of the binary tree.

Problem statement link https://www.geeksforgeeks.org/reverse-path-bst-using-queue/

*/

#include<iostream>
#include<queue>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void reverse_path(node *root, queue<int>& q, int key){
	
	if(root == nullptr)
		return;

	static bool flag = false;

	if(!flag){

		if(root->data > key){
			q.push(root->data);
			reverse_path(root->left, q, key);
		}

		if(root->data < key){
			q.push(root->data);
			reverse_path(root->right, q, key);
		}

		if(root->data == key){
			q.push(root->data);
			flag = true;
		}
	}

	if(flag){
		root->data = q.front();
		q.pop();
		return;
	}
}

void inorder(node *root){

	if(root == nullptr)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}

node* insert(node *root, int key){

	if(root == nullptr)
		return newNode(key);

	if(root->data > key)
		root->left = insert(root->left, key);

	else if(root->data < key)
		root->right = insert(root->right, key);


	return root;
}

int main(){

	struct node* root = nullptr;
    queue<int> q;
 
    // reverse path till k
    int k = 80;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    cout << "Before Reverse :"<<endl;
    // print inoder traversal of the BST
    inorder(root);
 
    cout << "\n";
 
    // reverse path till k
    reverse_path(root, q, k);
     
    cout << "After Reverse :"<<endl;
 
    // print inorder of reverse path tree
    inorder(root);
    cout<<endl;

	return 0;
}