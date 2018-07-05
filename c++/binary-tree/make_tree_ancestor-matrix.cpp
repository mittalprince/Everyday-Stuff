/* 
Construct tree from ancestor matrix

Given an ancestor matrix mat[n][n] where Ancestor matrix is defined as below.

   mat[i][j] = 1 if i is ancestor of j
   mat[i][j] = 0, otherwise 

Construct a Binary Tree from given ancestor matrix where all its values of nodes are from 0 to n-1.

    It may be assumed that the input provided the program is valid and tree can be constructed out of it.
    Many Binary trees can be constructed from one input. The program will construct any one of them.

Problem statement link https://www.geeksforgeeks.org/construct-tree-from-ancestor-matrix/

*/



#include<iostream>
#include<utility>
#include<unordered_map>

using namespace std;

struct node{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data  =data;

	return temp;
}
int N =6;
int mat[6][6] = {{ 0, 0, 0, 0, 0, 0 },
			        { 1, 0, 0, 0, 1, 0 },
			        { 0, 0, 0, 1, 0, 0 },
			        { 0, 0, 0, 0, 0, 0 },
			        { 0, 0, 0, 0, 0, 0 },
			        { 1, 1, 1, 1, 1, 0 }
    			};

node * maketree(){

  unordered_map < int , pair < node * , bool > > m;

  pair < node* , bool > temp;
  node * root = nullptr;

  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<N;j++)
    {
      
      if(mat[i][j])
      {
        if(m.find(j) != m.end())
        {
          if(m[j].second == false)
          {
            if(m.find(i) != m.end())
            {
              if(m[i].first->left == nullptr)
              {
                m[i].first->left = m[j].first;
                m[j].second = true;
              }
              else if(m[i].first->right == nullptr)
              {
                m[i].first->right = m[j].first;
                m[j].second = true;
              }
            }
            else
            {
              node * Node = newNode(i);

              Node->left = m[j].first;

              m[i] = make_pair(Node,false);

              root = Node;
            }
          }

        }
        else
        {
          if(m.find(i) != m.end())
          {
            if(m[i].first->left == nullptr)
              {
                m[i].first->left = newNode(j);
                m[j] = make_pair(m[i].first->left,true);
              }
            else if(m[i].first->right == nullptr)
              {
                m[i].first->right = newNode(j);
                m[j] = make_pair(m[i].first->right,true);
              }
          }
          else
          {
            node * Node = newNode(i);

            Node->left = newNode(j);

            m[i] = make_pair(Node,false);
            m[j] = make_pair(m[i].first->left,true);

            root = Node;
          }
        }
      }
    }
  }

  return root;
}

void printInorder(node* root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    
    cout<<root->data<<" ";

    printInorder(root->right);

 }


int main(){

	node *root = maketree();
	printInorder(root);

	return 0;

}