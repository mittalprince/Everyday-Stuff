/* 
Replace each node in binary tree with the sum of its inorder predecessor and successor

Given a binary tree containing n nodes. The problem is to replace each node in the binary 
tree with the sum of its inorder predecessor and inorder successor.  */


#include<iostream>
#include<vector>

using namespace std;

class node{
	int data;
	node *left, *right;

public:
	node(int key){
		data = key;
		left = nullptr;
		right = nullptr;
	}

	node*& leftnode(){
		return left;
	}
	node*& rightnode(){
		return right;
	}

	
	friend void inorder(node *, vector<int>* v);
	friend vector<int> replace_vec_with_sum(const vector<int>& , const int );
	friend void replace_tree_with_sum(node *, const vector<int>& );


	~node(){
		delete left;
		delete right;
	}
};

void inorder(node *root, vector<int>* v = nullptr ){
	if(root != nullptr){
		inorder(root->left, v);

		if(v != nullptr)
			v->push_back(root->data);
		else
			cout<<root->data<<" ";

		inorder(root->right,v);
		}
}

vector<int> replace_vec_with_sum(const vector<int> &v, const int size){
	vector<int> V;

	V.push_back(v[1]);

	for(int i=1 ; i< (size-1) ; ++i){
		int res = v[i-1] + v[i+1];
		V.push_back(res);
	}
		V.push_back(v[size-2]);

	return V;
}

void replace_tree_with_sum(node *root, const vector<int> &v){
	static int i=0;
	if(root == nullptr)
		return ;

	replace_tree_with_sum(root->left, v);

	root->data = v.at(i);
	++i;

	replace_tree_with_sum(root->right, v);

}

int main(){

	node* root = new node(1); 
    root->leftnode() = new node(2);       
    root->rightnode() = new node(3);      
    root->leftnode()->leftnode() = new node(4); 
    root->leftnode()->rightnode() = new node(5); 
    root->rightnode()->leftnode() = new node(6);
	root->rightnode()->rightnode() = new node(7);

	vector<int> inorder_vector;

	inorder(root, &inorder_vector);
	inorder_vector = replace_vec_with_sum(inorder_vector, inorder_vector.size());
	replace_tree_with_sum(root, inorder_vector);
	inorder(root);
	cout<<endl;

	return 0;

}