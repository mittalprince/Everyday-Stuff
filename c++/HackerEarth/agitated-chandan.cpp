/* Problem statement link --> https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/agitated-chandan/

*/

#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long ll;

struct node{
    bool visited = false;
    list< pair< ll, ll> > l;
};

void addEdge(vector<node> &graph, ll u, ll v, ll w){
    graph[u].l.push_back(make_pair(v,w));
    graph[v].l.push_back(make_pair(u,w));
}

ll DFS(vector<node> &graph, ll index, ll &Max){
    
    graph[index].visited = true;
    
    ll temp1=0, temp2=0;
    for(auto y: graph[index].l){
        if(!graph[y.first].visited){
            ll ans = DFS(graph, y.first, Max);
            ans += y.second;
            
            if(ans > temp1){
                temp2 = temp1;
                temp1 = ans;
            }
            
            else if(ans > temp2){
                temp2 = ans;
            }
        }
    }
    
    Max = max(Max, temp1+temp2);
    return temp1;
}

ll cost(ll distance){

    if(distance < 100)
        return 0;

    else if(distance >10000)
        return 10000;

    else if(distance > 1000)
        return 1000;
    
    else return 100;
}

ll printAns(vector<node> graph){
    ll Max = 0;
    DFS(graph, 0, Max);

    return Max;

}

int main(){

    ll t,n,u,v,w;
    cin>>t;
    while(t--){
        cin>>n;
        vector<node> graph(n);
        n--;
        while(n--){
            cin>>u>>v>>w;
            addEdge(graph,--u, --v, w);
        }

        ll Max = printAns(graph);
        ll Cost = cost(Max);

        cout<<Cost<<" "<<Max<<endl;
    }
    
    return 0;
}