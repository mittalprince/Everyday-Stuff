/* 
Construct Full Binary Tree using its Preorder traversal and Preorder traversal of its mirror tree

Given two arrays that represent Preorder traversals of a full binary tree and its mirror tree, 
we need to write a program to construct the binary tree using these two Preorder traversals.

A Full Binary Tree is a binary tree where every node has either 0 or 2 children.

Note: It is not possible to construct a general binary tree using these two traversal. 
But we can create a full binary tree using the above traversals without any ambiguity. 
For more details refer to this article.

Problem statement link  https://www.geeksforgeeks.org/construct-full-binary-tree-using-preorder-traversal-preorder-traversal-mirror-tree/

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

int p[] = {1,2,4,5,3,6,7};
int pm[] = {1,3,7,6,2,5,4};

node* make_tree(int p_start, int p_end, int pm_start, int pm_end){

	if(p_start <= p_end && pm_start <= pm_start){

		node *root = newNode(p[p_start]);

		if(p_start != p_end && pm_start != pm_end){

			int right_root, left_root;

			for(int i=p_start+1 ;i<= p_end;i++){

				if(pm[pm_start+1] == p[i]){
					right_root = i;
					break;
				}
			}

			for(int i=pm_start+1 ;i<= pm_end;i++){

				if(p[p_start+1] == pm[i]){
					left_root = i;
					break;
				}
			}

			root->left = make_tree(p_start+1, right_root-1, left_root, pm_end);
			root->right = make_tree(right_root, p_end, pm_start+1, left_root+1);

		}
		return root;
	}
	
		return nullptr;
}

void inorder_traversaal(node* root) {
    if(root) {
        inorder_traversaal(root->left);
        cout<<root->data<<" ";
        inorder_traversaal(root->right);
    }
}

int main(){
	node *root = make_tree(0, sizeof(p)/sizeof(p[0])-1, 0, sizeof(pm)/sizeof(pm[0])-1 );

	inorder_traversaal(root);
	cout<<endl;

	return 0;
}