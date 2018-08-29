#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#define ll long long

struct graph{
    
    bool visited = false;
    list<ll> l;
};

void assign(vector<graph> &V, int u, int v){
    V[u].l.push_back(v);
}

void DFS_Store(vector<graph> &v, stack<ll> &s, ll node){
    
    v[node].visited = true;
    
    for(auto y: v[node].l){
        if(!v[y].visited)
            DFS_Store(v, s, y);
    }
    
    s.push(node);
}

vector<graph> transpose(vector<graph> v){
    
    ll n = v.size();
    vector<graph> V(n);
    
    for(ll i=0; i<n; i++){
        if(!v[i].l.empty()){

			for(auto y: v[i].l)
				V.at(y).l.push_back(i);

		}
    }
    
    return V;
}

void count_MI(vector<graph> &v, ll node, ll &count){
    
    v[node].visited = true;
    ++count;
    
    for(auto y: v[node].l){
		if(!v[y].visited)
			count_MI(v, y, count);
	}
}

void SCC(vector<graph> &v, ll n){
    
    stack<ll> s;
    
    for(ll i=0; i<n ; i++){
        if(!v[i].visited)
            DFS_Store(v, s, i);
    }
    
    vector<graph> V = transpose(v);
    
    ll x = 0;
    
    while(!s.empty()){
        ll temp = s.top();
        s.pop();
        
        if(!V[temp].visited){
            ll count = 0;
            count_MI(V, temp, count);
             x = max(x, count);
        }
    }
    
    cout<<x;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,u,v;
    cin>>n>>m;
    
    vector<graph> V(n);
    
    while(m--){
        cin>>u>>v;
        assign(V, --u, --v);
    }
    
    SCC(V, n);
    
    return 0;
}