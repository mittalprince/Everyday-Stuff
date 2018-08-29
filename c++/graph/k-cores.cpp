/* 
Find k-cores of an undirected graph

Given a graph G and an integer K, K-cores of the 
graph are connected components that are left after all vertices of degree less than k have been removed 

Problem statement link https://www.geeksforgeeks.org/find-k-cores-graph/

*/

#include<iostream>
#include<list>
#include<vector>
#include<climits>

using namespace std;

struct graph{

	int value, degree;
	bool visited = false;
	list<int> l;
};

void addEdge(vector<graph> &V, int u, int v){

	V[u].l.push_back(v);
	V[v].l.push_back(u);
}

bool DFS(vector<graph> &v, int node, vector<int> &Degree, int k){

	v[node].visited = true;

	for(auto y: v[node].l){

		if(Degree[node] < k)
			Degree[y]--;

		if(!v[y].visited){

			if(DFS(v, y, Degree, k))
				Degree[node]--;
		}
	}

	return (Degree[node] < k);
}

void printCores(vector<graph> v, int n, int k){

	vector<int> Degree(n,0);

	int mindeg = INT_MAX;
    int startvertex;
 
    // Store degrees of all vertices
    for (int i=0; i<n; i++)
    {
        Degree[i]  = v[i].l.size();
 
        // if (Degree[i] < mindeg)
        // {
        //     mindeg = Degree[i];
        //     startvertex=i;
        // }
    }

	DFS(v, 0, Degree, k);

	for(int i=0; i<n; i++)
		if(!v[i].visited)
			DFS(v, i, Degree, k);

	cout << "K-Cores : \n";
    for (int i=0; i<n; i++)
    {
        if (Degree[i] >= k)
        {
            cout << "\n[" << i << "]";
 			
 			for(auto y: v[i].l){
 				if(Degree[y] >= k)
 					cout << " -> " << y;
 			}
        }
    }
}

int main(){

	int k = 3;
    vector<graph> v(9);
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 2);
    addEdge(v, 1, 5);
    addEdge(v, 2, 3);
    addEdge(v, 2, 4);
    addEdge(v, 2, 5);
    addEdge(v, 2, 6);
    addEdge(v, 3, 4);
    addEdge(v, 3, 6);
    addEdge(v, 3, 7);
    addEdge(v, 4, 6);
    addEdge(v, 4, 7);
    addEdge(v, 5, 6);
   	addEdge(v, 5, 8);
    addEdge(v, 6, 7);
   	addEdge(v, 6, 8);
    
    printCores(v, 9, k);
 
    cout << endl;

	return 0;
}