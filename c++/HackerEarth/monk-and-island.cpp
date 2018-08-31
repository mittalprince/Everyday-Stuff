/* Problem statement link --> https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

*/

#include<iostream>
#include<list>
#include<vector>
#include<queue>

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

ll BFS(vector<node> &graph, int n){
    
    queue<ll> q;
    graph[0].visited = 1;
    q.push(0);
    
    while(!q.empty()){
        ll temp = q.front();
        q.pop();
        
        for(auto y: graph[temp].l){
            if(!graph[y].visited){
                graph[y].visited = graph[temp].visited+1;
                q.push(y);
            }
            
            if(y == (n-1)){
               return graph[y].visited-1; 
            }
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<node> graph(n);
        while(m--){
            cin>>u>>v;
            addEdge(graph, --u, --v);
        }
        cout<<BFS(graph, n)<<endl;
    }
    
    return 0;
}