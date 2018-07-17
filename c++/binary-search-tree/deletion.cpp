/* 
Binary Search Tree | Set 2 (Delete)

We have discussed BST search and insert operations. In this post, delete operation is discussed. 
When we delete a node, three possibilities arise.

Problem statement link https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

*/

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

node *min_val_node(node *root){

	node *temp = root;

	while(temp->left != nullptr)
		temp = temp->left;

	return temp;
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

node* deletion(node *root, int key){

	if(root == nullptr)
		return root;

	if(key < root->data)
		root->left = deletion(root->left, key);

	else if(root->data < key)
		root->right = deletion(root->right, key);

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

		root->right = deletion(root->right, temp->data);
	}
	return root;
}

void inorder(node *root){

	if(root == nullptr)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout<<endl;

    root = deletion(root, 20);
    inorder(root);
    cout<<endl;

    root = deletion(root, 30);
    inorder(root);
    cout<<endl;
 
    root = deletion(root, 50);
    inorder(root);
    cout<<endl;

    return 0;

}

