#include<bits/stdc++.h>
     
using namespace std;
     
#define M 1000000007
     
typedef long long ll;
     
ll modularExponentiation(ll x, ll n){
  	ll res = 1;
   	while(n>0){
    	if(n&1)
    		res = (res*x)%M;
    
    	x = (x*x)%M;
   		n >>= 1;
   	}
    
   	return res%M;
}
     
void computeRes(ll n){
  	ll arr[n], a[n-1];
    
   	for(ll i=0; i<n; i++){
   		cin>>arr[i];
   	}
   	ll sum = 0;
   	for(ll i=1; i<n; i++){
   		ll temp=0;
   		temp = (arr[i]*modularExponentiation(arr[i-1], M-2));
   		temp %= M;
   		temp = (temp*(temp+1))%M;
   		temp *= modularExponentiation(2LL,M-2);
   		temp %= M;
 		sum += temp;
    	sum %= M;
    }
    
    sum = (sum*(sum+1))%M;
    sum *= modularExponentiation(2LL, M-2);
    sum %= M;
    
    cout<<sum;
     
}
int main(){
    
   	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
    
   	ll t;
   	cin>>t;
   	while(t--){
   		ll n;
   		cin>>n;
   		computeRes(n);
   		cout<<endl;
   	}    
   
   	return 0;
}