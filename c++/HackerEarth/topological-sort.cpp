/* https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/topological-sorttutorial/

*/

#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<set>

using namespace std;

struct node{

	bool visited = false;
	set<int, std::greater<int> > l;
};

void addEdge(vector<node> &graph, int u, int v){

	graph[u].l.insert(v);
}

void topologicalSortUtil(vector<node> &graph, int index, stack<int> &s){

	graph[index].visited = true;

	for(auto y: graph[index].l){
		if(!graph[y].visited)
			topologicalSortUtil(graph, y, s);
	}

	s.push(index+1);
}

void topologicalSort(vector<node> graph, int n){

	stack<int> s;

	for(int i=n-1; i>=0 ; i--)
		if(!graph[i].visited)
			topologicalSortUtil(graph, i, s);

	while(!s.empty()){

		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
	vector<node> graph(n);
	while(m--){
	    cin>>u>>v;
	    addEdge(graph, --u, --v);
	}
	
    topologicalSort(graph, n);
    cout<<endl;

	return 0;
}