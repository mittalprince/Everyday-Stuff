/* Probelm statement link --> 

https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/little-monk-and-edge-count/

*/

#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

typedef long long ll;

struct node{
	bool visited = false;
	list<ll> l;
	ll count = 1;
};

void addEdge(vector<node> &graph, ll u, ll v){
	graph[u].l.push_back(v);
	graph[v].l.push_back(u);
}

void dfs(vector<node> &graph, ll index){
	graph[index].visited = true;

	for(auto y: graph[index].l){
		if(!graph[y].visited){
			dfs(graph, y);
			graph[index].count += graph[y].count;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,q,no,u,v,i;
	cin>>n>>q;
	vector<node> graph(n);
	unordered_map<ll, pair<ll, ll> > m;

	for(i=0; i<(n-1); i++){
		cin>>u>>v;
		addEdge(graph, --u, --v);
		m[i].first = u;
		m[i].second = v;
	}

	dfs(graph, 0);

	while(q--){
		cin>>no;
		no--;
		ll a = graph[m[no].first].count;
		ll b = graph[m[no].second].count;
		if(a > b){
			a = n - b;
			cout<<a*b<<endl;
			
		}
		else {
			b = n -a;
			cout<<a*b<<endl;
		}
	}

	return 0;
}