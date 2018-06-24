
/* Level Order Traversal usinng Queue */

#include<iostream>
#include<queue>

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

void printLevelOrder(struct node* root){
  queue<struct node* > q;
  struct node* temp_node = root;

  while(temp_node){
    cout<<temp_node->data<<endl;

    if(temp_node->left){
      q.push(temp_node->left);
    }
    if(temp_node->right){
      q.push(temp_node->right);
    }
    temp_node = q.front();
    q.pop();
  }
}

// problem: root node data print twice
// void levelorder(struct node* root){
//   if(root == NULL)
//     return;
//
//   if(root->left == NULL)
//       return;
//
//   if(root->right == NULL)
//       return ;
//   cout<<root->data<<endl;
//
//   cout<<root->left->data<<endl;
//
//   cout<<root->right->data<<endl;
//
//   levelorder(root->left);
//   levelorder(root->right);
// }


// to calculate the height of tree
// int height(struct node* root){
//   if(root == NULL){
//     return 0;
//   }
//   else{
//
//     int lheight = height(root->left);
//     int rheight = height(root->right);
//
//     if(lheight > rheight)
//       return (lheight+1);
//     else return (rheight+1);
//   }
// }

// for print nodes at givrn level
 // void levelorder(struct node* root, int height){
 //   if(root == NULL)
 //    return ;
 //    if(height ==1)
 //    cout<<root->data<<endl;
 //
 //    else if(height > 1){
 //      levelorder(root->left, height-1);
 //      levelorder(root->right, height-1);
 //    }
 // }


//function to print level order traversal a tree
//  void printLevelOrder(struct node* root){
//     int h = height(root);
//     int i;
//     for (i=1; i<=h; i++)
//         levelorder(root, i);
// }

int main(){
  struct node *root  = newNode(1);
     root->left          = newNode(2);
     root->right         = newNode(3);
     root->left->left    = newNode(4);
     root->left->right   = newNode(5);

     printLevelOrder(root);

  return 0;
}
