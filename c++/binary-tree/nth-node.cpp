#include<iostream>
#include<vector>

using namespace std;

struct node{
	int data;
	node *left = nullptr;
	node *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void inorder(node *root, int index){
	static int count =0;
	if(root == nullptr)
		return ;
	if(count <= index){
		inorder(root->left, index);
		count++;

		if(count == index)
			cout<<root->data<<endl;

		inorder(root->right, index);
	}
}

void postorder(node *root, int index){
	static int count =0;
	if(root == nullptr)
		return ;
	if(count <= index){

		inorder(root->left, index);
		count++;
		inorder(root->right, index);

		if(count == index)
			cout<<root->data<<endl;
	}
}

void postorder(node *root, int index){
	static int count =0;
	if(root == nullptr)
		return ;
	if(count <= index){
		
		inorder(root->left, index);
		count++;
		inorder(root->right, index);

		if(count == index)
			cout<<root->data<<endl;
	}
}

void pretorder(node *root, int index){
	static int count =0;
	if(root == nullptr)
		return ;
	if(count <= index){
		if(count == index)
			cout<<root->data<<endl;

		count++;
		inorder(root->left, index);
		inorder(root->right, index);
	}
}

int main(){

	struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    int n=4;
    //int index = n-1;

    inorder(root, n);

    return 0;
 
}