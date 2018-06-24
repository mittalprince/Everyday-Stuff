#include<iostream>
#include<queue>

using namespace std;

struct node{
  int key;
  struct node* left;
  struct node* right;
};

struct node* newNode(int key){
  struct node* temp = new node;
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void insert(struct node* root, int key){
    queue<struct node* >q;
    q.push(root);

    while(!q.empty()){
      struct node* temp = q.front();
      q.pop();

      if(!temp->left){
        temp->left = newNode(key);
        break;
      }
      else{
        q.push(temp->left);
      }
      if(!temp->right){
        temp->right = newNode(key);
        break;
      }
      else{
        q.push(temp->right);
      }
    }
}

void inorder(struct node* root){
    if(root == NULL)
      return;

    inorder(root->left);
    cout<<root->key<<endl;
    inorder(root->right);
}

int main(){

  struct node* root = newNode(10);
      root->left = newNode(11);
      root->left->left = newNode(7);
      root->right = newNode(9);
      root->right->left = newNode(15);
      root->right->right = newNode(8);

      cout << "Inorder traversal before insertion:\n";
      inorder(root);

      int key = 12;
      insert(root, key);

      cout << endl;
      cout << "Inorder traversal after insertion:\n";
      inorder(root);

  return 0;
}
