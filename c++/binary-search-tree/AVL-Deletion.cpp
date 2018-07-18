/* Problem statement link https://www.geeksforgeeks.org/avl-tree-set-2-deletion/ */

#include<iostream>

using namespace std;

struct node{
	int data, height;
	node *left = nullptr, *right = nullptr;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->height = 1;

	return temp;
}

int height(node *root){

	if(root == nullptr)
		return 0;

	return root->height;
}

int get_balance_factor(node *root){

	if(root == nullptr)
		return 0;

	return height(root->left) - height(root->right);
}

node* right_rotate(node *z){

	node *y = z->left;
	node *t2 = y->right;

	y->right = z;
	z->left = t2;

	z->height = max((height(z->left)), (height(z->right))) + 1;
	y->height = max((height(y->left)), (height(y->right))) + 1;

	return y;
}

node* left_rotate(node *z){

	node *y = z->right;
	node *t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max((height(z->left)), (height(z->right))) + 1;
	y->height = max((height(y->left)), (height(y->right))) + 1;

	return y;
}

node* insert(node *root, int key){

	if(root == nullptr)
		return newNode(key);

	if(key < root->data)
		root->left = insert(root->left, key);

	else if(root->data < key)
		root->right = insert(root->right, key);

	else return root;

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance_factor = get_balance_factor(root);

	if(balance_factor > 1 && key < root->left->data)
		return right_rotate(root);

	if(balance_factor > 1 && key > root->left->data){
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}

	if(balance_factor < -1 && key > root->right->data)
		return left_rotate(root);

	if(balance_factor < -1 && key < root->right->data){
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

node* min_val_node(node *root){

	node *temp = root;

	while(temp->left != nullptr)
		temp = temp->left;

	return temp;
}

node* delete_node(node *root, int key){

	if(root == nullptr)
		return root;

	if(key < root->data)
		root->left = delete_node(root->left, key);

	else if(root->data < key)
		root->right = delete_node(root->right, key);

	else{

		if(root->left == nullptr){
			node *temp = root->right;
			delete root;
			return temp;
		}

		if(root->right == nullptr){
			node *temp = root->left;
			delete root;
			return temp;
		}

		node *temp = min_val_node(root->right);
		root->data = temp->data;

		root->right = delete_node(root->right, temp->data);
	}

	if(root == nullptr)
		return root;

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance_factor = get_balance_factor(root);

	if(balance_factor > 1 && get_balance_factor(root->left) >= 0)
		return right_rotate(root);

	if(balance_factor > 1 && get_balance_factor(root->left) < 0){
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}

	if(balance_factor < -1 && get_balance_factor(root->right) <= 0)
		return left_rotate(root);

	if(balance_factor < -1 && get_balance_factor(root->right) > 0){
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

void preorder(node *root){

	if(root == nullptr)
		return; 

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){

	struct node *root = nullptr;
 
  	/* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

	preorder(root);
	cout<<endl;

	root = delete_node(root, 10);

	    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 

	cout<<"After deletion"<<endl;

	preorder(root);
	cout<<endl;
	return 0;
}