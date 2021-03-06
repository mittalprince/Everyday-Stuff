/* 
AVL Tree | Set 1 (Insertion)

AVL tree is a self-balancing Binary Search Tree (BST) where the 
difference between heights of left and right subtrees cannot be more than one for all nodes.

Problem statement link https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

*/ 

#include<iostream>
#include<algorithm>

using namespace std;

struct node{
	int data, height;
	node *left=nullptr, *right=nullptr;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->height =1;

	return temp;
}

// function to calculate the height for a given node
int height(node *root){

	if(root == nullptr)
		return 0;

	return root->height;
}


//Utility function to calculate tha balance factor for a given node
int get_balance_factor(node *root){

	if(root == nullptr)
		return 0;

	return height(root->left) - height(root->right);
}


//Utility function to perform right rotation
node* right_rotate(node *z){

	node *y = z->left;
	node *t2 = y->right;

	y->right = z;
	z->left = t2;

	z->height = max((height(z->left)), (height(z->right))) + 1;
	y->height = max((height(y->left)), (height(y->right))) + 1;

	return y;
}


//Utility function to perform left rotation
node *left_rotate(node *z){

	node *y = z->right;
	node *t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max((height(z->left)), (height(z->right))) + 1;
	y->height = max((height(y->left)), (height(y->right))) + 1;

	return y;
}


//Function to insert node in AVL Tree
node* insert(node *root, int key){

	if(root == nullptr)
		return newNode(key);

	if(key < root->data)
		root->left = insert(root->left, key);

	else if(root->data < key)
		root->right = insert(root->right, key);

	else return root;

	//Calculate height at each node and update height of the ancesstor node
	root->height = max(height(root->left), height(root->right)) + 1;


	//calculate balance factor at each node to check whether its balanced or not
	int balance_factor = get_balance_factor(root);


	//Left Left Case
	if(balance_factor > 1 && key < root->left->data)
		return right_rotate(root);

	//Left Right Case
	if(balance_factor > 1 && key > root->left->data){
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}

	//Right Right Case
	if(balance_factor < -1 && key > root->right->data)
		return left_rotate(root);

	//Right Left Case
	if(balance_factor < -1 && key < root->right->data){
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}


//Utility function to print preorder
void preorder(node *root){
	if(root == nullptr)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){

	node *	root = insert(root, 10);
  	root = insert(root, 20);
  	root = insert(root, 30);
  	root = insert(root, 40);
  	root = insert(root, 50);
  	root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
  preorder(root);
  cout<<endl;

  return 0;
}

