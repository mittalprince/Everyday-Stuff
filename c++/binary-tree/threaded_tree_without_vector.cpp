/* /* 
Convert a Binary Tree to Threaded binary tree | Set 2 (Efficient)

Idea of Threaded Binary Tree is to make inorder traversal faster and do it
 without stack and without recursion. In a simple threaded binary tree, the NULL 
 right pointers are used to store inorder successor. Where-ever a right pointer is NULL, 
 it is used to store inorder successor.

Problem statement https://www.geeksforgeeks.org/convert-binary-tree-threaded-binary-tree-set-2-efficient/

*/

#include <iostream>

using namespace std;

struct node {
    int data;
    node *right = nullptr, *left = nullptr;
    bool rightThreaded = false;
};

inline node* new_node(int data) {
    node* temp = new node;
    temp->data = data;
    return temp;
}

node* make_threads(node *root) {
    if(root == nullptr)
        return nullptr;

    node* ans = make_threads(root->left);
    
    if(ans != nullptr) {
        ans->right = root;
        ans->rightThreaded = true;
    }

    if(root->right == nullptr)
        return root;
    
    node* t = make_threads(root->right);
    if(t != nullptr)
        return t;
    return nullptr;
}

node* get_leftmost(node *root) {
    if(root == nullptr)
        return nullptr;

    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

void threaded_inorder_traversal(node* root) {
    node *curr = get_leftmost(root);

    while(curr != nullptr) {
        cout<<curr->data<<" ";

        if(curr->rightThreaded)
            curr = curr->right;
        else
            curr = get_leftmost(curr->right);
    }

    cout<<endl;
}

int main() {
    node* root = new_node(6); 
    root->left = new_node(3);       
    root->right = new_node(8);      
    root->left->left = new_node(1);
    root->left->left->left = new_node(4); 
    root->left->left->right = new_node(16); 
    root->left->right = new_node(5); 
    root->left->right->left = new_node(7); 
    root->left->right->right = new_node(10);
    root->right->left = new_node(7);
    root->right->right = new_node(11);
    root->right->right->left = new_node(9);
    root->right->right->right = new_node(13);

    make_threads(root);
    threaded_inorder_traversal(root);

    node* t = new_node(1);
    t->left = new_node(2);
    t->left->left = new_node(4);
    t->left->right = new_node(5);
    t->left->left->left = new_node(10);
    t->right = new_node(3);
    t->right->right = new_node(7);
    t->right->left = new_node(6);
    t->right->left->right = new_node(11);

    node* ans = make_threads(t);
    cout<<ans->data<<endl;
    threaded_inorder_traversal(t);


    return 0;
}