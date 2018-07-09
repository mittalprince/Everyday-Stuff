/* 
Check if a Binary Tree contains duplicate subtrees of size 2 or more

Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree of size 2 or more.
Note : Two same leaf nodes are not considered as subtree size of a leaf node is one.

Problem statement link https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/

*/

#include<iostream>
#include<unordered_set>

using namespace std;

struct node{
	char data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(char data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

unordered_set<string> S;

string dup_subtree(node *root){

	if(root == nullptr)
		return "$";

	string s = "";

	string lstr = dup_subtree(root->left);
	if(lstr == "")
		return s;

	string rstr = dup_subtree(root->right);
	if(rstr == "")
		return s;

	s = root->data + lstr +rstr;

	if(s.size() > 3 && S.find(s) != S.end())
		return "";

	S.insert(s);

	return s;
}

int main(){

	node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');

    string s = dup_subtree(root);

    if(s == "")
    	cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

    return 0;
}