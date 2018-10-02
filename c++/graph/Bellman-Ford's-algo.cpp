/* 
Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge{
	ll src, dest, wt;
};

vector<ll> dist(100000, LLONG_MAX);

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m,u,v,w;

	cin>>n>>m;

	vector<edge> graph(m+1);
	for(ll i=1; i<=m; i++){

		cin>>u>>v>>w;
		graph.at(i).src = u;
		graph.at(i).dest = v;
		graph.at(i).wt = w;
	}

	dist.resize(n+1);


	dist[1] = 0;

	for(ll i=1; i<n; i++){
		
		for(ll j=1; j<=m; j++){

			if(dist[ graph.at(j).src] + graph.at(j).wt < dist[graph.at(j).dest] && dist[ graph.at(j).src] != INT_MAX)
				 dist[graph.at(j).dest] = dist[graph.at(j).src] + graph.at(j).wt;

		}
	}

	cout<<"Shortest path of all vertices from source vertex (1) :"<<endl;

	for(ll i=1; i<=n; i++){
		cout<<dist[i]<<" ";
	}

	cout<<endl;

	return 0;

}