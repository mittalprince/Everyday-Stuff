#include<iostream>
#include<stack>
#include<string>

using namespace std;

class node{
public:
  string data;
  node *left, *right;
  node(string key){
    data = key;
    left = nullptr;
    right = nullptr;
  }
};

int toint(string s){
  int num = 0;
  for(int i=0;i<s.length();i++){
    num = num*10 + (int(s[i])-48);
  }
  return num;
}

int evaluation(node* root){
  if(root ==nullptr){
    return 0;
  }
  if(!root->left && !root->right){
    return toint(root->data);
  }
  if(root->data == "+"){
      return (evaluation(root->left) + evaluation(root->right));
    }
   if(root->data == "-"){
      return (evaluation(root->left) - evaluation(root->right));
    }
   if(root->data == "*"){
      return (evaluation(root->left) * evaluation(root->right));
    }

    return (evaluation(root->left) / evaluation(root->right));
}

int main()
{
    // create a syntax tree
   node *root = nullptr;
    // root = new node("+");
    // root->left = new node("*");
    // root->left->left = new node("5");
    // root->left->right = new node("4");
    // root->right = new node("-");
    // root->right->left = new node("100");
    // root->right->right = new node("20");
    // cout << evaluation(root) << endl;


    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");

    cout << evaluation(root)<<endl;
    return 0;
}
