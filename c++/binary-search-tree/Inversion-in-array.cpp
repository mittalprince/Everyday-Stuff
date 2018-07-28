/* 
Count inversions in an array | Set 2 (Using Self-Balancing BST)

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.

    Two elements a[i] and a[j] form an inversion if 
     a[i] > a[j] and i < j. For simplicity, we may 
     assume that all elements are unique.

     Example:
     Input:  arr[] = {8, 4, 2, 1}
     Output: 6
     Given array has six inversions (8,4), (4,2),
     (8,2), (8,1), (4,1), (2,1).     

Problem statement link https://www.geeksforgeeks.org/count-inversions-in-an-array-set-2-using-self-balancing-bst/  */

#include<iostream>

using namespace std;
 
struct node{

    int key, height;
    struct node *left, *right;
    int size; 

};

node* newNode(int key){

    node* temp = new node;
    temp->key   = key;
    temp->left   = temp->right  = nullptr;
    temp->height = temp->size = 1;

    return temp;
} 

int height(node *root){

    if (root == nullptr)
        return 0;
    return root->height;
}
 
int size(node *root)
{
    if (root == nullptr)
        return 0;
    return root->size;
}
 
node *rightRotate(node *y){

    node *x = y->left;
    node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
 
    return x;
}
 
node *leftRotate(node *x){

    node *y = x->right;
    node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    return y;
}
 
int getBalance(node *root){

    if (root == nullptr)
        return 0;
    return height(root->left) - height(root->right);
}
 
node* insert(node* root, int key, int &result){

    if (root == nullptr)
        return(newNode(key));
 
    if (key < root->key){

        root->left  = insert(root->left, key, result);

        result = result + size(root->right) + 1;
    }
    else
        root->right = insert(root->right, key, result);
 
    root->height = max(height(root->left), height(root->right)) + 1;

    root->size = size(root->left) + size(root->right) + 1;
 
    int balance = getBalance(root);
 	
 	// Left Left case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && key > root->left->key){

        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && key < root->right->key){

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
int getInvCount(int arr[], int n){

  node *root = nullptr;
 
  int result = 0;  
 
  for (int i=0; i<n; i++)
 
     root = insert(root, arr[i], result);
 
  return result;
}
 

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    cout << "Number of inversions count are : "<< getInvCount(arr,n)<<endl;

    return 0;
}