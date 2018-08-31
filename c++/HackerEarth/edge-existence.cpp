#include<iostream>
#include<list>
#include<list>
#include<vector>

using namespace std;

struct node{
    list<int> l;
};

void addEdge(vector<node> &graph, int u, int v){
    graph[u].l.push_back(v);
    graph[v].l.push_back(u);
}

bool checkEdge(vector<node> graph, int u, int v){
    
    for(auto y: graph[u].l){
        if(y == v)
            return true;
    }
    
    return false;
}

int main(){
    int n,m,u,v,U,V,q;
    cin>>n>>m;
    vector<node> graph(n);
    while(m--){
        cin>>u>>v;
        addEdge(graph, u, v);
    }
    
    cin>>q;
    while(q--){
        cin>>U>>V;
        if(checkEdge(graph, U, V))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}