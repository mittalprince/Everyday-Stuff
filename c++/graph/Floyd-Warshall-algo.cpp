#include<bits/stdc++.h>

using namespace std;

#define n 4

typedef long long ll;

void printarr(ll dist[][n]){
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(dist[i][j] == LLONG_MAX)
				cout<<"Inf ";
			else cout<<dist[i][j]<<" ";
		}

		cout<<endl;
	}
}

void floydWarshall(ll edges[][n]){

	ll dist[n][n];

	for(ll i=0; i<n; i++)
		for(ll j=0; j<n; j++)
			dist[i][j] = edges[i][j];

	for(ll k=0; k<n; k++){
		for(ll i=0; i<n; i++){
			for(ll j=0; j<n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printarr(dist);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m,u,v,w;

	cin>>m;
	ll edges[n][n];

	for(ll i=0; i<n; i++)
		for(ll j=0; j<n; j++)
			edges[i][j] = LLONG_MAX;

	while(m--){
		cin>>u>>v>>w;
		edges[u][v] = w;
	}

	//printarr(edges);

	floydWarshall(edges);

	return 0;
}