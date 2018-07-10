/* 
Vertical Sum in a given Binary Tree | Set 1

Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Problem statement link https://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/

*/

// C++ program to find Vertical Sum in
// a given Binary Tree
#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new
// Binary Tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Traverses the tree in Inoorder form and
// populates a hashMap that contains the
// vertical sum
void verticalSumUtil(Node *node, int hd,
                     map<int, int> &Map)
{
    // Base case
    if (node == NULL) return;
 
    // Recur for left subtree
    verticalSumUtil(node->left, hd-1, Map);
 
    // Add val of current node to
    // map entry of corresponding hd
    Map[hd] += node->data;
 
    // Recur for right subtree
    verticalSumUtil(node->right, hd+1, Map);
}
 
// Function to find vertical sum
void verticalSum(Node *root)
{
    // a map to store sum of each horizontal
    // distance
    map < int, int> Map;
    map < int, int> :: iterator it;
 
    // populate the map
    verticalSumUtil(root, 0, Map);
 
    // Prints the values stored by VerticalSumUtil()
    for (it = Map.begin(); it != Map.end(); ++it)
    {
        cout << it->first << ": "
             << it->second << endl;
    }
}
 
// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    //root->right->left->right = newNode(12);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->right->left->left = newNode(11);

    root->right->left->right = newNode(12);
    root->left->left->left = newNode(8);
    root->right->right->left = newNode(13);
    root->right->right->right = newNode(14);

 
    // cout << "Following are the values of vertical
    //         " sums with the positions of the "
    //         "columns with respect to root\n";
    verticalSum(root);
 
    return 0;
}
// This code is contributed by Aditi Sharma