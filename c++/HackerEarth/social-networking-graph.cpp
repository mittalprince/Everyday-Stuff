/* Problem statement link --> https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/description/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

typedef long long ll;

struct node{
    ll visited = 0;
    list<ll> l;
};

void addEdge(vector<node> &graph, ll u, ll v){
    
    graph[u].l.push_back(v);
    graph[v].l.push_back(u);
}

void dfs(vector<node> graph, ll index, ll n, ll &ans){
    graph[index].visited = 1;
    queue<ll>q;
    q.push(index);
    
    while(!q.empty()){
        ll temp = q.front();
        q.pop();
        
        for(auto y: graph[temp].l){
           
            if(!graph[y].visited){
                graph[y].visited = graph[temp].visited +1;
                q.push(y);
                if(graph[y].visited == n+1){
                ++ans;
            }
            }
            
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,u,v,q,ans;
    cin>>n>>m;
    vector<node> graph(n);
    while(m--){
        cin>>u>>v;
        addEdge(graph, u, v);
    }
    cin>>q;
    while(q--){
        cin>>u>>v;
        ans = 0;
        dfs(graph, u, v, ans);
        cout<<ans<<endl;
    }
    
    return 0;
}