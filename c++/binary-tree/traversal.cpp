#include<iostream>

using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data){
  struct node* Newnode = new node;
  Newnode->data = data;
  Newnode->left=NULL;
  Newnode->right=NULL;
  return Newnode;
}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<endl;
    inorderTraversal(root->right);
}

void postTraversal(struct node* root){
    if(root==NULL)
      return;

    postTraversal(root->left);
    postTraversal(root->right);
    cout<<root->data<<endl;
}

void preTraversal(struct node* root){
    if(root==NULL)
      return;

    cout<<root->data<<endl;
    preTraversal(root->left);
    preTraversal(root->right);
}

int main(){
  struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);

     cout<<"Inorder"<<endl;
     inorderTraversal(root);
     cout<<endl;

     cout<<"Preorder"<<endl;
     preTraversal(root);
     cout<<endl;

     cout<<"Postorder"<<endl;
     postTraversal(root);
     cout<<endl;

     return 0;
}
