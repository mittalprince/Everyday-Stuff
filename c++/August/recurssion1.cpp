#include<iostream>

using namespace std;

typedef long long ll;

ll factorial(ll n){

    if(n == 0){
        return 1;
    }

    return factorial(n-1) * n;
}

int main(){

    ll n;
    cin>>n;
    cout<<factorial(n)<<endl;

    return 0;
}