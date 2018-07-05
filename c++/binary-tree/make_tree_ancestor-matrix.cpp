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

struct nide{
	int data;
	node *left = nullptr, *right = nullptr;
};

struct node* newNode(int data){
	node *temp = new node;
	temp->data  =data;

	return temp;
}

int int mat[6][6] = {{ 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 0 }
    };

node * make_tree(){

	unordered_map<int, pair<node*, bool> > m;

	pait<node*, bool> temp;

	for(int i=0; i<6;i++){
		for(int j=0; j<6; j++){

			if(mat[i][j]){

				if(m.find(j) != m.end()){

					if()

				}
			}
		}
	}
}
