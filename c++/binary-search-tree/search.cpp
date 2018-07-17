#include<iostream>

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

node* search(node *root, int key){

	if(root == nullptr)
		return nullptr;

	if(root->data == key)
		return root;

	if(root->data < key)
		return search(root->right, key);

	return search(root->left, key);
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

	struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if(search(root, 80))
    	cout<<"YES, it exist in tree"<<endl;

    else cout<<"Not found"<<endl;

   	return 0;
}

