#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> p;

ll M = 1000000007;

void primeFactor(ll n, unordered_map<ll, ll> &m){

    while(n%2 == 0){
        n /= 2;
        m[2]++;
    }

    for(ll i=3; i<= sqrt(n); i++){
        while(n%i == 0){
            n /= i;
            m[i]++;
        }
    }
    if(n>2)
        m[n]++;
}

ll modularExponentiation(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

ll Max(const ll a, const ll b) {
    return a>b ? a : b;
}

ll computeK(ll A, ll B, ll C){
    unordered_map<ll, ll> m1, m2;
    primeFactor(A, m1);
    primeFactor(B, m2);
    vector<p> ans;

    for(auto it=m2.begin(); it!= m2.end(); it++){

        if(m1[it->first]){
            ll z = m1[it->first];
            ll j = (it->second)*C;
            ll m = j > z ? j-z : 0;
            
            ans.push_back({it->first, m});
        }
        else ans.push_back({it->first, it->second*C});
    }

    if(ans.size() <= 0 )
        return 1;

    ll temp = modularExponentiation(ans[0].first%M, ans[0].second, M);

    for(ll i=1; i<ans.size(); i++){
        temp *= modularExponentiation(ans[i].first%M, ans[i].second, M);
        temp %= M;
    }

    return temp;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,A,B,C;

    cin>>t;
    while(t--){
        cin>>A>>B>>C;
        cout<<computeK(A, B, C)<<endl;
    }

    return 0;
}