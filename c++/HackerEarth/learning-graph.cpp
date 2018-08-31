/* https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/

*/

#include<iostream>
#include<set>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

class comparator{
    public:
    
    bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b){
        if(a.first > b.first)
            return true;
        
        else if(a.first == b.first)
            return (a.second > b.second);
        else return false;
    }
};

struct node{
    ll value;
    multiset< pair<ll, ll>, comparator> s;
    ll size = 0;
};

void addEdge(vector<node> &graph, ll u, ll v){
    graph[u].s.insert(make_pair(graph[v].value, v));
    graph[u].size++;

    graph[v].s.insert(make_pair(graph[u].value, u));
    graph[v].size++;
}

ll print_kth(multiset<pair<ll, ll>, comparator>& s, ll k){
    auto it = s.begin();
    
    while(k--){
        if(it == s.end())
            return -1;
        ++it;
    }
    --it;
    return it->second + 1;
}
int main(){
    
    ll n,m,u,v,val,k;
    cin>>n>>m>>k;
    vector<node> graph(n);
    
    for(ll i=0;i<n;i++){
        cin>>val;
        graph[i].value = val;
    }
    while(m--){
        cin>>u>>v;
        addEdge(graph,--u, --v);
    }
    
    for(ll i=0; i<n; i++){
        if(k > graph[i].size)
            cout<<"-1\n";
        
        else {
            auto& temp = graph[i].s;
            cout<<print_kth(temp, k)<<endl;
        }
    }
    
    return 0;
}