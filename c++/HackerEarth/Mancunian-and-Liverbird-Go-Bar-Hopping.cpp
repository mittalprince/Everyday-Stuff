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
}

vector<node> transpose(vector<node> graph, int n){
    
    vector<node> reverse(n);
    
    for(ll i=0; i<n ;i++){
        for(auto y: graph[i].l){
            reverse[y].l.push_back(i);
        }
    }
    
    return reverse;
}

void dfs(vector<node> graph, ll index, ll &count){
    graph[index].visited = true;
    
    for(auto y: graph[index].l)
        if(!graph[y].visited)
            dfs(graph, y, count);
            
    count++;
}

int main(){
    ll n,no,q,count=0,index;
    char ch;
    cin>>n;
    vector<node> graph(n);
    for(ll i=1; i<n; i++){
        cin>>no;
        if(no){
            addEdge(graph, (i-1), i);
        }
        else addEdge(graph, i, (i-1));
    }
    vector<node> reverse = graph;
    cin>>q;
    while(q--){
        cin>>ch;
        if(ch == 'U'){
            reverse= transpose(graph, n);
        }
        else if(ch == 'Q'){
            cin>>index;
            count = 0;
            dfs(graph, --index, count);
            cout<<count<<endl;
        }
    }
    
    return 0;
    
}