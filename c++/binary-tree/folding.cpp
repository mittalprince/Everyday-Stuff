/* A tree can be folded if left and right subtrees of the tree are structure
wise mirror image of each other. An empty tree is considered as foldable. */

#include<iostream>

using namespace std;

class node{
  int data;
  node *left, *right;

public:
  node(int key){
    data = key;
    left =nullptr;
    right =nullptr;
  }
  node*& leftnode(){
    return left;
  }
  node*& rightnode(){
    return right;
  }

  ~node(){
    delete right;
    delete left;
  }

  friend bool isfolding(node *, node *);
  friend bool foldable(node *);

};

bool foldable(node *root){
  if(root == nullptr){
    return true;
  }
  return isfolding(root->left,root->right);
}

bool isfolding(node* left, node* right){
  if(left == nullptr && right == nullptr){
    return true;
  }
  if(left == nullptr || right ==nullptr){
    return false;
  }
  return isfolding(left->left,right->right) && isfolding(left->right,right->left);
}

int main(){
  node *root = nullptr;
  root = new node(10);
  root->leftnode() = new node(11);
  root->rightnode() = new node(9);
  root->leftnode()->rightnode() = new node(7);
   root->leftnode()->rightnode()->rightnode() = new node(8);
   root->rightnode()->leftnode() = new node(15);
   //root->rightnode()->leftnode()->leftnode() = new node(10);

  //root->folding(0);
  bool ans = foldable(root);
  if(ans){
    cout<<"YES\n";
  }
  else cout<<"NO"<<endl;
  return 0;
}
