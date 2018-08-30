/* 
Topological Sorting

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed 
edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Problem statement link  https://www.geeksforgeeks.org/topological-sorting/-

*/

#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

struct node{

	bool visited = false;
	list<int> l;
};

void addEdge(vector<node> &graph, int u, int v){

	graph[u].l.push_back(v);
}

void topologicalSortUtil(vector<node> &graph, int index, stack<int> &s){

	graph[index].visited = true;

	for(auto y: graph[index].l){
		if(!graph[y].visited)
			topologicalSortUtil(graph, y, s);
	}

	s.push(index);
}

void topologicalSort(vector<node> graph, int n){

	stack<int> s;

	for(int i=0; i<n ; i++)
		if(!graph[i].visited)
			topologicalSortUtil(graph, i, s);

	while(!s.empty()){

		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){

	vector<node> graph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(graph, 6);
    cout<<endl;

	return 0;
}