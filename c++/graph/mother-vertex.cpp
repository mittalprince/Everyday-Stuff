/* 
Find a Mother Vertex in a Graph

What is a Mother Vertex?
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.

*/

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<stack>

using namespace std;

struct graph{

	int value = 0;
	bool visited = false;
	list<int> l;
};

void assign(vector<graph> &v, int u, int value){

	v[u].value = value;
}

void addEdge(vector<graph> &V, int u, int v){

	V[u].l.push_back(v);
}

void DFS(vector<graph> &v, int node, stack<int> &s){

	v[node].visited = true;

	if(!v[node].l.empty()){

	for(auto y: v[node].l)
		if(!v[y].visited)
			DFS(v, y, s);
	}

	s.push(v[node].value);
}

int main(){

	vector<graph> v(7);

	assign(v,0,0);
	assign(v,1,1);
	assign(v,2,2);
	assign(v,3,3);
	assign(v,4,4);
	assign(v,5,5);
	assign(v,6,6);

	addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 4, 1);
    addEdge(v, 6, 4);
    addEdge(v, 5, 6);
    addEdge(v, 5, 2);
    addEdge(v, 6, 0);
 

    stack<int> s;

    for(int i=0;i<7;i++){
    	if(v[i].visited == false)
    		DFS(v, i, s);
    }

    cout<<s.top()<<endl;

	return 0;
}