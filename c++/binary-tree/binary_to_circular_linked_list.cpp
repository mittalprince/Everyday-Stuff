	/* 
Convert a given Binary Tree to Circular Linked List | Set 1

Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
The left and right pointers in nodes are to be used as previous and 
next pointers respectively in converted DLL. The order of nodes in DLL
 must be same as Inorder of the given Binary Tree. The first node of 
 Inorder traversal (left most node in BT) must be head node of the DLL.

 Problem statement link https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

 */


#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* t = new node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void make_circular_list(node* &head){

    if(head == nullptr)
        return ;

    node *temp = nullptr;

    temp = head->left;
    temp->right = head;

    //head = head->left->right;

}
void binary_to_dll(node *root, node* &head){

	if(root == nullptr)
		return;

	static node* pre = nullptr;

	binary_to_dll(root->left,head);

	if(pre == nullptr)
		head = root;

	else{

		root->left = pre;
		pre->right = root;
	}

	pre = root;
    head->left = pre;

	binary_to_dll(root->right, head);
}

void traverse_tree(node *head){

    make_circular_list(head);

	if(head == nullptr)
		return ;
    cout<<head->data<<" ";
    node *temp = head->right;

    while(temp != head){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
	
}

int main() {

    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    node *head = nullptr;

    binary_to_dll(root, head);

    traverse_tree(head);

    cout<<endl;

    return 0;
}