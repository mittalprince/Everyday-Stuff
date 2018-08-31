/* Problem statement link -->  https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/monk-and-graph-problem/ 

*/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

typedef long long ll;

struct node{
    bool visited = false;
    list<ll> l;
};

void addEdge(vector<node> &graph, ll u, ll v){
    
    graph[u].l.push_back(v);
    if(u!=v)
        graph[v].l.push_back(u);
}
void dfs(vector<node> &graph, ll index, ll &count){
    
    graph[index].visited = true;
    count+= graph[index].l.size();
    for(auto y: graph[index].l){
        if(y == index)
            count+= 1;
        
        if(!graph[y].visited){
            
            dfs(graph, y, count);
        }
    }
}

int main(){
    
    ll n,m,u,v,count,Max=0;
    
    cin>>n>>m;
    vector<node> graph(n);
    
    while(m--){
        cin>>u>>v;
        addEdge(graph, --u, --v);
    }
    
    for(ll i=0; i<n; i++){
        count =0;
        if(!graph[i].visited){
            dfs(graph, i, count);
        }
        Max = (Max<count) ? count: Max;
    }
    
    cout<<Max/2<<endl;
    
    return 0;
}

