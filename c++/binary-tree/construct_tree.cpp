/* 
Construct Tree from given Inorder and Preorder traversals

Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

Problem statement link https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

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

node* make_tree(int inorder[], int preorder[], int start, int end){

	int root_index;
	static int index= 0 ;

	if(start < end){
		for(int i=start; i<=end; i++){

			if(inorder[i] == preorder[index]){
				root_index = i;
				break;
			}
		}

	node *root = newNode(inorder[root_index]);
	
	index++;

	root->left = make_tree(inorder,preorder,start, (root_index)-1 );

	index++;

	root->right = make_tree(inorder, preorder, root_index+1, end);

	return root;
	}
	else if(start == end){
		node *root = newNode(inorder[start]);
		return root;
	}
	else{
		index--;
		return nullptr;
	}
}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<endl;
    inorderTraversal(root->right);
}

int main(){
	int inorder[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7}; 
	//{4,2,3,1,5};
	int preorder[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};//
	//{1,2,4,5,3};

	int n = sizeof(inorder)/sizeof(inorder[0]);

	node *root = make_tree(inorder,preorder,0,(n-1));

	inorderTraversal(root);
	cout<<endl;

	return 0;
}