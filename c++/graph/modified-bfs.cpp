#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

struct node{
	bool visited = false;
	list<int> l;
	int pred = -1;
	int dist = 0;
};

void addEdge(vector<node> &graph, int u, int v){
	graph.at(u).l.push_back(v);
	graph.at(v).l.push_back(u);
}

bool BFS(vector<node> &graph, int src, int dest){

	graph.at(src).visited = true;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int temp = q.front();
		q.pop();

		for(auto y: graph.at(temp).l){
			if(!graph.at(y).visited){
				q.push(y);
				graph.at(y).visited = true;
				graph.at(y).dist = graph.at(temp).dist+1;
				graph.at(y).pred = temp;
			}

			if(y == dest)
				return true;
		}
	}

	return false;
}

void print_shortes_path(vector<node> graph, int src, int dest){

	if(!BFS(graph, src, dest)){
		cout<<"Given source and destination aren't connected"<<endl;
		return ;
	}

	cout<<"Shortest Path length is "<<graph.at(dest).dist<<endl;


	vector<int> path;
	path.push_back(dest);

	while(graph.at(dest).pred != -1){
		path.push_back(graph.at(dest).pred);
		dest = graph.at(dest).pred;
	}

	for(int i=path.size()-1; i>=0; i--)
		cout<<path[i]<<" ";

}

int main(){

	// no. of vertices
    int v = 8; 
 
    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<node> graph(v);
 
    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source 
    // and destination vertex as argument and forms
    // an edge between them.
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);

    int source = 0, dest = 7;

    print_shortes_path(graph, source, dest);
    cout<<endl;
    return 0;
}