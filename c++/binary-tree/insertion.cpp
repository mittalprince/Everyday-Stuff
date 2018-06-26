// #include<iostream>
// #include<queue>
//
// using namespace std;
//
// struct node{
//   int key;
//   struct node* left;
//   struct node* right;
// };
//
// struct node* newNode(int key){
//   struct node* temp = new node;
//   temp->key = key;
//   temp->left = NULL;
//   temp->right = NULL;
//
//   return temp;
// }
//
// void insert(struct node* root, int key){
//     queue<struct node* >q;
//     q.push(root);
//
//     while(!q.empty()){
//       struct node* temp = q.front();
//       q.pop();
//
//       if(!temp->left){
//         temp->left = newNode(key);
//         break;
//       }
//       else{
//         q.push(temp->left);
//       }
//       if(!temp->right){
//         temp->right = newNode(key);
//         break;
//       }
//       else{
//         q.push(temp->right);
//       }
//     }
// }
//
// void inorder(struct node* root){
//     if(root == NULL)
//       return;
//
//     inorder(root->left);
//     cout<<root->key<<endl;
//     inorder(root->right);
// }
//
// int main(){
//
//   struct node* root = newNode(10);
//       root->left = newNode(11);
//       root->left->left = newNode(7);
//       root->right = newNode(9);
//       root->right->left = newNode(15);
//       root->right->right = newNode(8);
//
//       cout << "Inorder traversal before insertion:\n";
//       inorder(root);
//
//       int key = 12;
//       insert(root, key);
//
//       cout << endl;
//       cout << "Inorder traversal after insertion:\n";
//       inorder(root);
//
//   return 0;
// }


#include<iostream>
#include<queue>

using namespace std;

class node{
  int data;
  node *left, *right;

public:
  node(int key){
    data= key;
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
      class node *temp_node = this;

      while(temp_node!= nullptr){
        cout<<temp_node->data<<endl;

        if(temp_node->left != nullptr)
          q.push(temp_node->left);

        if(temp_node->right != nullptr)
          q.push(temp_node->right);

        temp_node = q.front();
        q.pop();
      }
    }

    void insert(int data){
      queue<node* >q;
      node *temp = this;

      while(temp->left != nullptr && temp->right != nullptr){
        q.push(temp->left);
        q.push(temp->right);
        temp = q.front();
        q.pop();
      }

      if(temp->left == nullptr){
        temp->left = new node(data);
      }
      else{
        temp->right = new node(data);
      }
    }

    ~node(){
      delete left;
      delete right;
    }
};

int main(){

  node *root = nullptr;
  root = new node(10);
  root->leftnode() = new node(11);
  root->rightnode() = new node(9);
  root->leftnode()->leftnode() = new node(7);
  root->rightnode()->rightnode() = new node(8);
  root->rightnode()->leftnode() = new node(15);
  root->levelOrder();
   root->insert(12);
   cout<<endl;
   root->levelOrder();


  // class node* root = nullptr;
  // root = new node(10);
  // root->insert(11);
  // root->insert(9);
  // root->insert(7);
  // root->insert(8);
  // root->insert(15);
  // root->insert(12);
  //
  // root->levelOrder();

  return 0;
}
