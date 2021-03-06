/* 
Transpose graph

Transpose of a directed graph G is another directed graph on the same set of vertices with all of the edges reversed compared to the orientation of the corresponding edges in G. That is, if G contains an edge (u, v) then the converse/transpose/reverse of G contains an edge (v, u) and vice versa.
Given a graph (represented as adjacency list), we need to find another graph which is the transpose of the given graph.

Problem statement link https://www.geeksforgeeks.org/transpose-graph/

*/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct node{

	bool visited = false;
	list<int> l;
};

void addEdge(vector<node> &graph, int u, int v){
	graph[u].l.push_back(v);
}

void displayGraph(const vector<node> graph, int n)
{
    for (int i = 0; i < n; i++) {
        cout << i << "--> ";
        for (auto y: graph[i].l)
            cout << y << "  ";
        cout << "\n";
    }
}

vector<node> transpose_graph(const vector<node> graph, int n){

	vector<node> transpose(n);

	for(int i=0; i<n; i++)
		for(auto y: graph[i].l)
			addEdge(transpose, y, i);

	return transpose;
}

int main(){

	int v = 5;
    vector<node> graph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);

    cout<<"Graph before transpose\n";
    displayGraph(graph, v);
 
    vector<node> transpose = transpose_graph(graph, 5);

    cout<<"Graph after transpose\n";
    displayGraph(transpose, v);
    
	return 0;
}