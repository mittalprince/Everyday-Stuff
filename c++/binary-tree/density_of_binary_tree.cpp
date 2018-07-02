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

int height_and_size(node *root, int &size){
	if(root == nullptr)
		return 0;

	int lheight = height_and_size(root->left,size);
	int rheight = height_and_size(root->right, size);

	++size;

	if(lheight > rheight)
		return (lheight+1);

	else return (rheight+1);
}

float density(node *root){
	if(root == nullptr)
		return 0;

	int size = 0;

	int height = height_and_size(root, size);

	return (float)size/height;
}

int main(){

	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
 
    cout<<"Density of given binary tree is "<<density(root);
    cout<<endl;

 
    return 0;
}