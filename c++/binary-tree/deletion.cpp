#include<iostream>
#include<queue>

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

  void levelOrder(){
    queue<node* >q;
    class node *temp_node = this;

    while(temp_node!= nullptr){
      cout<<temp_node->data<<endl;

      //if(temp_node->left != nullptr)
        q.push(temp_node->left);

      //if(temp_node->right != nullptr)
        q.push(temp_node->right);

      temp_node = q.front();
      q.pop();
    }
  }
  int del_rightmost(){
    int data;

      queue<node* >q;
      node *temp_node = this;
      node *temp = nullptr;

      while(temp_node != nullptr){
        if(temp_node->left != nullptr){
          temp = temp_node;
          q.push(temp_node->left);
        }
        if(temp_node->right != nullptr){
          temp = temp_node;
          q.push(temp_node->right);
        }
        temp_node = q.front();
        q.pop();
      }

      if(temp->right != nullptr){
        data = temp->right->data;
        temp->right = nullptr;
      }
      else if(temp->left != nullptr){
        data = temp->left->data;
        temp->left = nullptr;
      }
      else{
        //this = nullptr;
        cout<<"Root node left\n";
        return -1;
      }
      delete temp_node;
      return data;

  }

  void del_key(int key){
    queue<node* >q;
    node *temp = this;

    while(temp != nullptr){
      if(temp->data == key){
        temp->data = this->del_rightmost();
        return;
      }
      if(temp->left != nullptr)
        q.push(temp->left);

      if(temp->right != nullptr)
        q.push(temp->right);

      temp = q.front();
      q.pop();
    }
    cout<<"No such key found !"<<endl;
  }

  ~node(){
    delete right;
    delete left;
  }
};

int main(){
  node *root = nullptr;

    root = new node(10);
    root->leftnode() = new node(11);
    root->rightnode() = new node(9);
    root->leftnode()->leftnode() = new node(7);
    root->leftnode()->rightnode() = new node(12);
    root->rightnode()->leftnode() = new node(15);
    root->rightnode()->rightnode() = new node(8);


    root->levelOrder();
    root->del_key(11);
    root->levelOrder();

return 0;
}
