/* 
Find distance between two nodes of a Binary Tree

Find the distance between two keys in a binary tree, no parent pointers are given. 
Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.

Problem statement link https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/

the distance between two node can be found using formula
	disance(lca, n1) + distance(lca, n2)

here lca is the lowest common ancesstor of two given nodes n1,n2.

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

node* find_LCA(node *root, int n1, int n2){

	if(root == nullptr)
		return nullptr;

	if(root->data == n1 || root->data == n2)
		return root;

	node *left = find_LCA(root->left, n1, n2);
	node *right = find_LCA(root->right, n1, n2);

	if(left != nullptr && right != nullptr)
		return root;

	if(left != nullptr && right == nullptr)
		return left;


	if(left == nullptr && right != nullptr)
		return right;

}

void find_level(node *root, int n1, int index, int& level){

	if(root == nullptr)
		return; 

	if(root->data == n1){
		level = index;
	}

	find_level(root->left, n1, index+1, level);

	find_level(root->right, n1, index+1, level);
}

int findDistance(node *root, int n1, int n2){

	node *lca = find_LCA(root, n1, n2);

	int d1 = 0, d2 = 0;
	find_level(lca, n1, 0, d1);
	find_level(lca, n2, 0, d2);

	return  (d1+d2);
}

int main(){

	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Dist(4, 5) = " << findDistance(root, 4, 5)<<endl;
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6)<<endl;
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4)<<endl;
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4)<<endl;
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5)<<endl;



	return 0;
}