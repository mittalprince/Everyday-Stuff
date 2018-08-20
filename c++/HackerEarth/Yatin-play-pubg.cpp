/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/dummy3-4/  */

#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int data, height;
    node *left = nullptr, *right = nullptr;
};

node* newNode(int data){
    node *temp = new node;
    temp->data = data;
    temp->height = 1;
    
    return temp;
}

int height(node *root){
    
    if(root == nullptr)
        return 0;
    
    return root->height;
}

node* insert(node *root, int key){
    
    if(root == nullptr)
        return newNode(key);
        
    if(root->data > key)
        root->left = insert(root->left, key);
        
    else if(root->data < key)
        root->right = insert(root->right, key);
    
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

int main(){
    
    int  T,n,N;
    
    cin>>T;
    while(T--){
        
        node *root = nullptr;
        
        cin>>N;
        
        while(N--){
            cin>>n;
            root = insert(root, n);
        }
        
        cout<<root->height<<endl;
    }
    
   return 0;
}