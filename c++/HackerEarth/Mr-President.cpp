/* Problem statement link https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/ */

#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long ll;

struct node1{
	ll weight;
	pair<ll, ll> edge; 
};

struct node2{
	bool visited = false;
	vector<ll> l;
};

struct node3{
	ll size;
	ll val;
};

bool comparator(const node1& nodea, const node1& nodeb){
	return nodea.weight < nodeb.weight;
}

vector<node3> arr;

void initialize(ll n){

	for(ll i=0; i<n; i++){
		node3 temp;
		temp.val = i;
		temp.size = 1;

		arr.push_back(temp);
	}
}

ll root(ll i){
	while(arr.at(i).val != i){
		arr.at(i).val = arr.at(arr.at(i).val).val;
		i = arr.at(i).val;
	}

	return i;
}

void Union(ll a, ll b){
	ll root_a = root(a);
	ll root_b = root(b);

	if(root_a == root_b)
		return;

	if(arr.at(root_a).size < arr.at(root_b).size){
		arr.at(root_a).val = arr.at(root_b).val;
        arr.at(root_b).size +=  arr.at(root_a).size;
	}

	else{
		arr.at(root_b).val = arr.at(root_a).val;
        arr.at(root_a).size +=  arr.at(root_b).size;
	}
}

ll find(ll a, ll b){
	return (root(a) == root(b));
}

void dfs(vector<node2> &graph, ll index, ll &count){

	graph.at(index).visited = true;
	count++;

	for(auto y: graph.at(index).l){
		if(!graph.at(y).visited){
			dfs(graph, y, count);
		}
	}
}

bool disconnected(vector<node2> &Graph){
	ll count = 0;

	dfs(Graph, 1, count);

	return !(++count == Graph.size());
}

ll minCost(vector<node1> &graph, ll k){
	ll mincost = 0;
	vector<ll> path;

	for(auto& i: graph){
		if(!find(i.edge.first, i.edge.second)){
			Union(i.edge.first, i.edge.second);
			mincost += i.weight;
			path.push_back(i.weight);
		}
	}

	if(mincost <= k)
		return 0;

	if(path.size() > k)
		return -1;

	ll count = 0; 

	for(auto i = path.size()-1; i>= 0; i--){

		if(mincost <= k)
			return count;

		mincost =mincost - path.at(i) + 1;
		++count;
	}

	return count;
}

void addEdge(vector<node2> &Graph, ll u, ll v){
	Graph.at(u).l.push_back(v);
	Graph.at(v).l.push_back(u);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll nodes, edges, k;

	cin>>nodes>>edges>>k;

	vector<node1> graph(edges+1);
	vector<node2> Graph(nodes+1);

	initialize(nodes+1);

	for(ll i=1; i<= edges; i++){
		ll u,v,w;
		cin>>u>>v>>w;

		graph.at(i).weight = w;
		graph.at(i).edge = make_pair(u,v);

		addEdge(Graph, u, v);
	}

	if(disconnected(Graph)){
		cout<<"-1"<<endl;
		return 0;
	}

	sort(graph.begin(), graph.end(), comparator);

	cout<<minCost(graph, k)<<endl;

	return 0;
}