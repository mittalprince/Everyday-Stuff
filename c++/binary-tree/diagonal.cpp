/* 
Diagonal Traversal of Binary Tree

Consider lines of slope -1 passing between nodes. 
Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Problem statement link  https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

*/


#include<iostream>
#include<queue>

using namespace std;

struct node{
	int data;
	node *left=nullptr, *right=nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void diagnol_traversal(node* root) {
    queue<node *> q;
    
    while(root != nullptr) {
        q.push(root);
        //q.push(nullptr);
        root = root->right;
    }

    while(!q.empty()) {

        root = q.front();
        q.pop();

        // if(root == nullptr){
        // 	cout<<endl;
        // 	q.push(nullptr);
        // }

        //else{
        cout<<root->data<<" ";

        root = root->left;
        while(root != nullptr) {
            q.push(root);
            //q.push(nullptr);
            root = root->right;
        }

    //}
	}
}

int main(){

    node* root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->right = newNode(10);
    root->right->left = newNode(6);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    diagnol_traversal(root);
    cout<<endl;

	return 0;

}