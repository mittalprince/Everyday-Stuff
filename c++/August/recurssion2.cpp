#include<iostream>

using namespace std;

typedef long long ll;

void incr(ll n){

    if(n == 0){
        return;
    }

    incr(n-1);
    cout<<n<<' ';
}

void descr(ll n){
    if(n == 0){
        return;
    }

    cout<<n<<' ';
    descr(n-1);
}

int main(){

    int n;
    cin>>n;

    incr(n);
    descr(n);

    return 0;
}