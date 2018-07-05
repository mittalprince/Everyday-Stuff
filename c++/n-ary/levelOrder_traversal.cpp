/* Level Order Traversal of n-ary tree */

#include<iostream>
#include<queue>

using namespace std;

const int n=10;
class Node{
public:
	char data;
	Node* child[n];

	Node(int key){
		data = key;

		for(int i=0;i<n;i++){
			child[i] = nullptr;
		}
	}
};

void levelOrder(Node *root){

queue<Node* > q;
Node *current = root;

q.push(current);

while(!q.empty()){

	current = q.front();
	q.pop();
	cout<<current->data<<" ";

	for(int i=0;i<n;i++){

		if(current->child[i] != nullptr)
			q.push(current->child[i]);
	}

}

}

int main(){

	Node *root = new Node('A');
    root->child[0] = new Node('B');
    root->child[1] = new Node('C');
    root->child[2] = new Node('D');
    root->child[3] = new Node('E');
    root->child[0]->child[0] = new Node('F');
    root->child[0]->child[1] = new Node('G');
    root->child[2]->child[0] = new Node('H');
    root->child[0]->child[0]->child[0] = new Node('I');
    root->child[0]->child[0]->child[1] = new Node('J');
    root->child[0]->child[0]->child[2] = new Node('K');
    root->child[2]->child[0]->child[0] = new Node('L');
    root->child[2]->child[0]->child[1] = new Node('M');

    levelOrder(root);

    cout<<endl;

	return 0;
}