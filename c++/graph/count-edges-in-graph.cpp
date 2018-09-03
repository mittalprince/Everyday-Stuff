#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct node{
	bool visited = false;
	list<int> l;
};

void addEdge(vector<node> &graph, int u, int v){
	graph[u].l.push_back(v);
	graph[v].l.push_back(u);
}

int countEdges(vector<node> graph){

	int sum =0;
	for(int i=0; i<graph.size(); i++){
		sum+= graph[i].l.size();
	}

	return (sum/2);
}

int main(){

	int V = 9 ;
    vector<node> graph(V);
 
    // making above uhown graph
    addEdge(graph, 0, 1 );
    addEdge(graph, 0, 7 );
    addEdge(graph, 1, 2 );
   	addEdge(graph, 1, 7 );
    addEdge(graph, 2, 3 );
    addEdge(graph, 2, 8 );
    addEdge(graph, 2, 5 );
    addEdge(graph, 3, 4 );
    addEdge(graph, 3, 5 );
   	addEdge(graph, 4, 5 );
   	addEdge(graph, 5, 6 );
 	addEdge(graph, 6, 7 );
    addEdge(graph, 6, 8 );
    addEdge(graph, 7, 8 );
 
    cout << countEdges(graph) << endl;
	return 0;
}