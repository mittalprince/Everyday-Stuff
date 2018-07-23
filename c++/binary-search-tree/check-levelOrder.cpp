/* 
Check if the given array can represent Level Order Traversal of Binary Search Tree

Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a Binary Search Tree or not.

Problem statement link https://www.geeksforgeeks.org/check-given-array-can-represent-level-order-traversal-binary-search-tree/

*/

#include<iostream>
#include<unordered_map>

using namespace std;

struct node{
    int data;
    node *left = nullptr, *right = nullptr;
};

node* newNode(int data){
    node *temp = new node;
    temp->data = data;

    return temp;
}

unordered_map<int, int> m;

bool check_level_order(node *&root, int key, int depth,int& last_depth){

    if(root == nullptr){
        root = newNode(key);
        if(depth >= last_depth)
        {
            if(m.find(depth) != m.end()){

                if(m[depth] < key){
                    m[depth] = key;
                    last_depth = depth;
                    return true;
                }
                else return false;
            }
            else {
                m[depth] = key;
                last_depth = depth;
                return true;
            }
        }
        else return false;
    }

    if(key < root->data)
        return check_level_order(root->left, key, depth+1,last_depth);

    if(key > root->data)
        return check_level_order(root->right, key, depth+1,last_depth);
}

bool wrapper(int arr[], int size){

    node *root = nullptr;
    int last_depth = 0;

    for(int i=0; i<size; i++){

        if(!(check_level_order(root, arr[i], 0,last_depth)))
            return false;
    }

    return true;
}

int main(){

    int arr[] = {7, 4, 12, 3, 6, 8, 1};
    //int arr[] = {11, 6, 13, 5, 12, 10};
    //int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
	//int arr[] = {11, 6, 13, 5, 12, 10};
	//int arr[] = {4,5,7};
	//int arr[] = {1,0,2};

    if(wrapper(arr,sizeof(arr)/sizeof(int)))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
