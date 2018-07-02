/* 
Level order traversal line by line | Set 3 (Using One Queue)

Given a Binary Tree, print the nodes level wise, each level on a new line.


#include<iostream>
#include<queue>

using namespace std;

struct node{
	int data;
	node *left = nullptr;
	node *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void levelorder(node *root){
	if(root == nullptr)
		return ;

	queue<node* > q;
	node *temp;
	q.push(root);
	q.push(nullptr);

	while(!q.empty()){

		temp = q.front();
		q.pop();

		if(temp == nullptr){
			if(!q.empty()){
				q.push(nullptr);
				cout<<endl;
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main(){

	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    levelorder(root);
    cout<<endl;
    return 0;
}


*/

// ----------------------------------------------------------------------------------------------------------------

//Problem statement link https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include<iostream>
#include<stack>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data = data;

	return temp;
}

void level_order_spiral_traversal(node *root){

	if(root == nullptr)
		return ;

	stack<node* > s1,s2;

	s1.push(root);

	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){

			cout<<s1.top()->data<<" ";

			if(s1.top()->right)
				s2.push(s1.top()->right);

			if(s1.top()->left)
				s2.push(s1.top()->left);

			s1.pop();
		}

		while(!s2.empty()){

			cout<<s2.top()->data<<" ";

			if(s2.top()->left)
				s1.push(s2.top()->left);
			
			if(s2.top()->right)
				s1.push(s2.top()->right);
			
			s2.pop();
		}
	}
}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);

    cout << "Spiral Order traversal of binary tree is \n";
    level_order_spiral_traversal(root);
    cout<<endl;
 
    return 0;
}