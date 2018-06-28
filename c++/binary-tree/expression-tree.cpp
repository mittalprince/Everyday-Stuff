/* Given a postfix expression convert this into the binary tree .
Inorder traversal of expression tree produces infix version of given
postfix expression (same with preorder traversal it gives prefix expression).
So given postfix make tree then we can find infix and prefix expression */

#include<iostream>
#include<sstream>
#include<cctype>
#include<stack>

using namespace std;

struct node{
  char data;
  node *left, *right;
};

struct node* newNode(char key){
  struct node *Node = new node;
  Node->data = key;
  Node->left =NULL;
  Node->right = NULL;

  return Node;
}

bool isoperand(char c){
  if(c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
            return true;
      return false;
}

struct node* expression(string str){
  stringstream s(str);
  char c;
  node *root;
  stack<node* > S;
  node *val1,*val2;
  while(s >> c){

  if(!isoperand(c)){
    root = newNode(c);
    S.push(root);
  }
  else{
    root = newNode(c);
    val1 = S.top();
    S.pop();
    val2 = S.top();
    S.pop();
    root->left = val2;
    root->right = val1;
    S.push(root);

    }
  }
  root = S.top();
  S.pop();
  return root;
  //inorderTraversal(root);
}

void inorderTraversal(struct node* root){
    if(root==NULL)
      return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
//a=1,b=2,c=3,d=4,e=5,f=6,g=7
int main(){
  string s = "ab+ef*g*-" ;
  //cin>>s;
  struct node* result = expression(s);
  inorderTraversal(result);
  cout<<endl;
  return 0;
}
