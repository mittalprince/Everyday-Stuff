#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

unordered_map<ll , pair<ll, bool> > m;

struct node{
	list<p> l;
	ll distance = LONG_LONG_MAX;
};

void DFS(vector<node> &graph, ll index, ll distance){
	if(graph.at(index).distance > distance)
		graph.at(index).distance = distance;

	bool flag = false;

	for(auto &y: graph[index].l){
		if(!m[y.second].second){
			DFS(graph, y.first, distance + m[y.second].first);
			flag = true;
		}
		else{
			DFS(graph, y.first, distance);
		}

		if(flag){
				m[y.second].second = false;
				flag = false;
			}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,M;
	cin>>n>>M;
	ll arr[n+1][M+1];
	ll cost[n+1];

	vector<node> graph(n+1);

	for(ll i=1; i<=n;i++){
		for(ll j=1; j<=M; j++){
			cin>>arr[i][j];
		}

		cin>>cost[i];
	}

	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=M; j++){
			if(arr[i][j])
			graph.at(j-1).l.push_back({j,i});
		}
		m[i].first = cost[i];
		m[i].second = false;
	}
	DFS(graph, 0, 0);
	cout<<graph[n].distance - 1<<endl;
	return 0;
}