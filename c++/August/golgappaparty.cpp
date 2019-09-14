#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin>>n;

    vector<ll> v;
    v.resize(n);

    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += abs(v[i] - (i+1));
    }
    cout<<ans<<endl;
    return 0;
}