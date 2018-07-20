/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-cursed-tree/ */

#include<iostream>

using namespace std;

struct node{
    long long data;
    node *left = nullptr, *right = nullptr;
};

node* newNode(long long data){
    node *temp = new node;
    temp->data = data;
    
    return temp;
}

node* insert(node *root, long long key){
    
    if(root == nullptr)
        return newNode(key);
        
    if(root->data > key)
        root->left = insert(root->left, key);
        
    if(root->data < key)
        root->right = insert(root->right, key);
        
    return root;
}

node* lowest_common_ancesstor(node *root, long long n1, long long n2){
    
    if(root == nullptr)
        return root;
    
    if(root->data == n1 || root->data == n2)
        return root;
        
    node *left = lowest_common_ancesstor(root->left, n1, n2);
    node *right = lowest_common_ancesstor(root->right, n1, n2);
    
    if(left && right)
        return root;
        
    if(left != nullptr && right == nullptr)
        return left;
    
    if(right != nullptr && left == nullptr)
        return right;
}

void max_node(node *root, long long key){
    
    if(root->data == key){
        cout<<root->data<<endl;
        return ;
    }
    
    if(root->data < key){
        max_node(root->right, key);
    }
    else {
        cout<<root->data<<endl;
        return;
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long T,n,X,Y;
    node *root = nullptr;
    cin>>T;
    while(T--){
        cin>>n;
        root = insert(root, n);
    }
    cin>>X>>Y;
    root = lowest_common_ancesstor(root, X, Y);
    if(X>Y)
    max_node(root, X);
    
    else if(X<Y)
    max_node(root, Y);
    
    else cout<<X<<endl;
    
    return 0;
}