#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *right = nullptr, *left = nullptr;
    bool rightThreaded = false;
};

 node* newNode(int data) {
    node* temp = new node;
    temp->data = data;

    return temp;
}

void inorder(node *root, vector<node *>* v) {
    if (root != nullptr) {
        inorder(root->left, v);

        v->push_back(root);

        inorder(root->right, v);
    }
}

void make_threads(vector<node *>& v) {
    for(int i=0;i<v.size();i++){
    	if(v[i]->right == nullptr){
    		v[i]->right = v[i+1];
    		v[i]->rightThreaded = true;
    	}
    }
}

node* leftmost(node *root) {
    if(root == nullptr)
        return nullptr;

    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

void threaded_inorder_traversal(node* root) {
    node *temp = leftmost(root);

    while(temp != nullptr) {
        cout<<temp->data<<" ";

        if(temp->rightThreaded)
            temp = temp->right;
        else
            temp = leftmost(temp->right);
    }

    cout<<endl;
}

int main() {
    node* root = newNode(1); 
    root->left = newNode(2);       
    root->right = newNode(3);      
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    
    vector<node *> inorder_traversal;

    inorder(root, &inorder_traversal);
    make_threads(inorder_traversal);
    threaded_inorder_traversal(root);

    return 0;
}