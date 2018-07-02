/* 
Calculate depth of a full Binary tree from Preorder

Given preorder of a binary tree, calculate its depth(or height) [starting from depth 0]. 
The preorder is given as a string with two possible characters.

    ‘l’ denotes the leaf
    ‘n’ denotes internal node

The given tree can be seen as a full binary tree where every node has 0 or two children. 
The two children of a node can ‘n’ or ‘l’ or mix of both.

Problem statement link https://www.geeksforgeeks.org/calculate-depth-full-binary-tree-preorder/ */

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left=nullptr, *right=nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data= data;

	return temp;
}

int depth(string s, int size, int &index){

	if(index >= size || s[index] == 'l')
		return 0;

	index++;
	int lheight = depth(s, size, index);

	index++;
	int rheight = depth(s, size, index);

	if(lheight > rheight)
		return (lheight+1);

	else return (rheight+1);

}

int main(){

	string s = "nlnnlll";
    int size = s.size();
 	int index = 0;

    cout << depth(s, size, index) << endl;
 
    return 0;
}