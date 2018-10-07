#include <bits/stdc++.h>

using namespace std;

int dist[100005];
int vis[100005];
int parent[100005];

void printPath(int j){

	if(parent[j] == -1)
		return ;

	printPath(parent[j]);

	cout<<j<<" ";
}

void printSolution(int n){
	int src = 1;
	cout<<"Vertex \t \tDistance \tPath \n";

	for(int i=2; i<n; i++){
		cout<<src<<" -> "<<i<<"\t\t"<<dist[i]<<" \t \t"<<src<<" ";
		printPath(i);
		cout<<endl;
	}
}


vector< pair<int,int> > v[100005];

void dijkstra(int n){

	multiset< pair< int,int > > s;
	s.insert({0,1});
	
	while(!s.empty()){

		pair< int,int > p = *s.begin();
		s.erase(s.begin());
		int e = p.second;
		if(vis[e])
			continue;
		
		vis[e]=1;
		for(int i=0;i<v[e].size();i++){

		int x = v[e][i].first;
		int y = v[e][i].second;
		if(dist[e]+y<dist[x]){
			parent[x] = e;
			dist[x] = dist[e]+y;
			s.insert({dist[x],x});
			}	
		}
	}

	printSolution(n);
}

int main(){

	/* 
	Input :
	9
	14
	1 2 4
	2 3 8
	3 4 7
	4 5 9
	5 6 10
	6 7 2
	7 8 1
	8 1 8
	8 9 7
	8 2 11
	9 3 2
	9 7 6
	3 6 4
	4 6 14

	*/

	int m,n,x,y,w;
	cin>>n>>m;
	for(int i=0;i<=n+3;i++){

		dist[i]=1e9;
		vis[i]=0;
		parent[i] = -1;
	}
	
	dist[0]=0;
	dist[1]=0;
	
	for(int i=0;i<m;i++){

	cin>>x>>y>>w;
	v[x].push_back(make_pair(y,w));
	v[y].push_back(make_pair(x,w));
	}
	
	dijkstra(n+1);
	// for(int i=2;i<=n;i++){
	// cout<<dist[i]<<" ";
	// }
	cout<<endl;
	return 0;
}