/* 
Construct a special tree from given preorder traversal

Given an array ‘pre[]’ that represents Preorder traversal of a spacial 
binary tree where every node has either 0 or 2 children. One more array ‘preLN[]’ is 
given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates 
that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the 
corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.

Problem statemnet link https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/

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

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

node* special_wrapper(int pre[], char preLN[], int& index, int size) {
    if(index > size)
        return nullptr;
    
    node* t = newNode(pre[index]);
    
    if(preLN[index] == 'N') {
        t->left = special_wrapper(pre, preLN, ++index, size);
        t->right = special_wrapper(pre, preLN, ++index, size);
    }

    return t;
}

node* special_tree(int pre[], char preLN[], int size) {
    int index = 0;
    return special_wrapper(pre, preLN, index, size);
}

int main() {

	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};

	int size = sizeof(pre)/sizeof(pre[0]);

    node* root = special_tree(pre, preLN, size);
    inorder_traversaal(root);

    cout<<endl;

    return 0;
}