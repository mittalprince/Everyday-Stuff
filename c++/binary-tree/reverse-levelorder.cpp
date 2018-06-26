/* Reverse LevelOrder Traversal  implement using class stack and Queue */

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
  int data;
  node *left;
  node *right;

public:
  node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
  }

  node*& leftnode(){
    return left;
  }
  node*& rightnode(){
    return right;
  }

  void levelOrder(){
    queue<node* >q;
    stack<int >s;
    class node *temp_node = this;

    while(temp_node!= nullptr){
      //cout<<temp_node->data<<endl;
      s.push(temp_node->data);

      if(temp_node->right != nullptr)
        q.push(temp_node->right);

        if(temp_node->left != nullptr)
          q.push(temp_node->left);

      temp_node = q.front();
      q.pop();
    }
    while(!s.empty()){
      cout<<s.top()<<endl;
      s.pop();
    }
  }
  ~node(){
    delete left;
    delete right;
  }
};

int main(){

  node *root = nullptr;
  root = new node(1);
  root->leftnode() = new node(2);
  root->rightnode() = new node(3);
  root->leftnode()->leftnode() = new node(4);
  root->rightnode()->rightnode() = new node(5);

  root->levelOrder();
  return 0;
}
