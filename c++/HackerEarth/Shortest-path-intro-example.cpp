#include <bits/stdc++.h>

using namespace std;

int dist[100005];
int vis[100005];

vector< pair<int,int> > v[100005];

void dijkstra(){

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
			dist[x] = dist[e]+y;
			s.insert({dist[x],x});
			}	
		}
	}
}

int main(){

	int m,n,x,y,w;
	cin>>n>>m;
	for(int i=0;i<=n+3;i++){

		dist[i]=1e9;
		vis[i]=0;
	}
	
	dist[0]=0;
	dist[1]=0;
	
	for(int i=0;i<m;i++){

	cin>>x>>y>>w;
	v[x].push_back(make_pair(y,w));
	}
	
	dijkstra();
	for(int i=2;i<=n;i++){
	cout<<dist[i]<<" ";
	}
	
	return 0;
}