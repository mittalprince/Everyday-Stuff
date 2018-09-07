#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

void initialize(vector<ll> &arr, vector<ll>& s){

	for(ll i=0; i<arr.size(); i++){
		arr.at(i) = i;
		s.at(i) = 1;
	}
}

ll root(vector<ll> &arr, ll i){

	while(arr[i] != i){
		arr[i] = arr[arr[i]];
		i = arr[i];
	}

	return i;
}

void weighted_union(vector<ll> &arr, vector<ll> &s, ll a, ll b){

	int root_a = root(arr, a);
	int root_b = root(arr, b);
    
    if(root_a == root_b)
        return ;
        
	if(s.at(root_a) < s.at(root_b)){
		arr.at(root_a) = root_b;
		s.at(root_b) += s.at(root_a);
	}
	
	else {
		arr.at(root_b) = root_a;
		s.at(root_a) += s.at(root_b);
	}
	
}

bool find(vector<ll> arr, ll a, ll b){
	if(root(arr, a) == root(arr, b))
		return true;

	else false;
}

int main(){
    ll n,m,u,v;
    cin>>n>>m;
    vector<ll> arr(n), s(n);
    
    initialize(arr, s);
    
    while(m--){
        multiset<ll> m;
        cin>>u>>v;
        weighted_union(arr, s, --u, --v);
        
        for(ll i=0; i<n; i++){
            if(arr.at(i) == i){
                m.insert(s.at(i));
            }
        }
        auto it = m.begin();
        while(it != m.end()){
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }
    return 0;
}

