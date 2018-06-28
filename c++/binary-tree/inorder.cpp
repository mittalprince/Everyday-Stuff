#include<iostream>
#include<stack>

using namespace std;

class node{
  int data;
  node *left, *right;

public:
  node(int key){
    data = key;
    left = nullptr;
    right= nullptr;
  }
  node*& leftnode(){
    return left;
  }
  node*& rightnode(){
    return right;
  }

  friend void inorder(node* root);
  ~node(){
    delete left;
    delete right;
  }
};

void inorder(node* root){
  stack<node* >s;
  node *current_node = root;
  while(current_node!= nullptr){
    s.push(current_node);
    current_node = current_node->left;
  }
  while(!s.empty()){
    if(current_node == nullptr){
    cout<<s.top()->data<<" ";
    current_node = s.top()->right;
    s.pop();
    }
    while(current_node!= nullptr){
      s.push(current_node);
      current_node = current_node->left;
    }
  }
}

int main(){
  node *root = nullptr;
  root = new node(1);
  root->leftnode() = new node(2);
  root->rightnode() = new node(3);
  root->leftnode()->leftnode() = new node(4);
  root->leftnode()->rightnode() = new node(5);

  inorder(root);
  return 0;
}
