
/* 
Check sum of Covered and Uncovered nodes of Binary Tree

Given a binary tree, you need to check whether sum of all covered elements is equal to 
sum of all uncovered elements or not.
In a binary tree, a node is called Uncovered if it appears either on left boundary or 
right boundary. Rest of the nodes are called covered.

For example, consider below binary tree 

Problem statement link https://www.geeksforgeeks.org/check-sum-covered-uncovered-nodes-binary-tree/

*/


#include<iostream>

using namespace std;

struct node 
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;

	temp->data = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}
void inorder(node * root,int& sum)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left,sum);

	sum += root->data;

	inorder(root->right,sum);
}


bool check_uncovered_covered(node * root)
{
	int l_sum =0;
	int r_sum = 0;
	int uncovered_sum = 0;
	int covered_sum = 0;
	node * temp = root;

	if(root == nullptr)
	{
		return true;
	}
	while(temp->left != nullptr || temp->right != nullptr)
	{
		if(temp->left != nullptr)
		{
			l_sum += temp->left->data;
			temp = temp->left;
		}
		else if(temp->right != nullptr)
		{
			l_sum += temp->right->data;
			temp = temp->right;
		}
	}
	temp = root;

	while(temp->left != nullptr || temp->right != nullptr)
	{
		if(temp->right != nullptr)
		{
			r_sum += temp->right->data;
			temp = temp->right;
		}
		else if(temp->left != nullptr)
		{
			r_sum += temp->left->data;
			temp = temp->left;
		}
	}
	uncovered_sum = l_sum + r_sum + root->data;

	inorder(root,covered_sum);

	// cout<<covered_sum<<endl;
	// cout<<uncovered_sum<<endl;

	covered_sum -= uncovered_sum;

	if(covered_sum == uncovered_sum)
	{
		return true;
	}
	else
	{
		return false;
	}


}

int main()
{
	node* root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(21);
    root->left->right->left = newNode(21);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    if(check_uncovered_covered(root))
    {
    	cout<<"YES Sum of covered and uncovered is same"<<endl;
    }
    else
    {
    	cout<<"NO  Sum of covered and uncovered is not same"<<endl;
    }

    return 0;
 
}