/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-watching-fight/

*/

#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    long long  data, height;
    node *left = nullptr, *right =nullptr;
};

node* newNode(long long data){
    node *temp = new node;
    temp->data = data;
    temp->height =1;
    
    return temp;
}

long long height(node *root){
    
    if(root == nullptr)
    return 0;
    
    return root->height;
}

node* insert(node *root, long long key){
    
    if(root == nullptr)
        return newNode(key);
        
    if(root->data > key)
        root->left = insert(root->left, key);
        
    if(root->data < key)
        root->right = insert(root->right, key);
    if(root->data == key){
        root->height++;
        return root;
    }
    
    root->height = max(height(root->left), height(root->right)) +1;
    
    return root;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long No_of_nodes, key;
    cin>>No_of_nodes;
    
    node *root = nullptr;
    
    while(No_of_nodes--){
     cin>>key;
     root = insert(root, key);
    }
    
    cout<<root->height<<endl;
    
    return 0;
}

