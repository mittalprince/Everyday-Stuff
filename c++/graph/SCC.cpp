/* 
Strongly Connected Components

A directed graph is strongly connected if there is a path between all pairs of vertices. 
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 

*/

#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>

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

void DFS(vector<graph> v, int node, stack<int> &s){

	v[node].visited = true;

	for(auto y: v[node].l)
		if(!v[y].visited)
			DFS(v, y, s);

	s.push(v[node].value);
}

vector<graph> transpose(vector<graph> v, int n){
	vector<graph> V(n);

	for(int i=0;i<n;i++){

		if(!v[i].l.empty()){

			for(auto y: v[i].l)
				V.at(y).l.push_back(i);

		}
	}

	return V;
}

void printSCC(vector<graph> &v, int node){

	cout<<node<<" ";
	v[node].visited = true;

	for(auto y: v[node].l){
		if(!v[y].visited)
			printSCC(v, y);
	}
}

void SCC(vector<graph> v, stack<int> s){

	while(!s.empty()){

		int temp = s.top();
		s.pop();

		if(!v[temp].visited){

			printSCC(v, temp);
			cout<<endl;
		}
	}
}

int main(){

	vector<graph> v(5);

	assign(v,0,0);
	assign(v,1,1);
	assign(v,2,2);
	assign(v,3,3);
	assign(v,4,4);

	addEdge(v, 1, 0);
    addEdge(v, 0, 2);
    addEdge(v, 2, 1);
    addEdge(v, 0, 3);
    addEdge(v, 3, 4);

    stack<int> s;

    DFS(v, 0, s);

    vector<graph> V = transpose(v, 5);

    SCC(V, s);

	return 0;
}