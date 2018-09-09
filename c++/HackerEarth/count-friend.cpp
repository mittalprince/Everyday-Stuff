/* Problem statement link --> https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/  */

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

void initialize(ll arr[], ll size[], ll n){

    for(ll i=1; i<=n; i++){
        arr[i] = i;
        size[i] = 1;
    }
}

ll root(ll arr[], ll  i){
    while(arr[i] != i){
        //arr[i] = arr[arr[i]];
        i = arr[i];
    }

    return i;
}

void Union(ll arr[], ll size[], ll a, ll b){
    ll root_a = root(arr, a);
    ll root_b = root(arr, b);

    if(root_b == root_a)
        return ;

    if(size[root_a] < size[root_b]){
        arr[root_a] = root_b;
        size[root_b]+= size[root_a];
    }


    else{
        arr[root_b] = root_a;
        size[root_a]+= size[root_b];
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,u,v;
    cin>>n>>m;

    ll arr[n+1], size[n+1];

    initialize(arr, size, n);

    while(m--){
        cin>>u>>v;
        Union(arr,size, u, v);
    }

    for(ll i=1; i<=n; i++)
        cout<<size[root(arr, i)]-1<<" ";

    cout<<endl;

    return 0;
}