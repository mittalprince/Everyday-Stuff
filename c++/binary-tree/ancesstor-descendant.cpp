/* 
Query for ancestor-descendant relationship in a tree

Given a rooted tree with N vertices and N-1 edges. We will be given many pairs of vertices u and v, 
we need to tell whether u is an ancestor of v or not. Given tree will be rooted at the vertex with index 0.

Problem statement link https://www.geeksforgeeks.org/query-ancestor-descendant-relationship-tree/

*/

#include<iostream>
#include<unordered_map>

using namespace std;

bool check_anscestor(unordered_map < int, int >& m,int anscestor,int child)
{
	while(m.find(child) != m.end())
	{
		if(m[child] == anscestor)
		{
			return true;
		}
		child = m[child];
	}
	return false;
}

int main(){

	int edges[][2] = {
        { 0, 1 },
        { 0, 2 },
        { 1, 3 },
        { 1, 4 },
        { 2, 5 },
        { 4, 6 },
        { 5, 7 }
    };
 	
 	unordered_map<int, int> m;

 	for(int i=0; i< sizeof(edges)/(2*sizeof(int)); i++){
 		m[edges[i][1]] = edges[i][0];
 	}

 	int u = 1;
 	int v = 6;

 	if(check_anscestor(m,u,v)){
 		cout<<"YES"<<endl;
 	}
 	else cout<<"NO"<<endl;

 	if(check_anscestor(m,1,7))
 		cout<<"YES"<<endl;
 	else cout<<"NO"<<endl;

	return 0;

}