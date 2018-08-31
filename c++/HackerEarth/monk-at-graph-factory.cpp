#include<iostream>

using namespace std;

int main(){
    int n,i,sum=0,deg;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>deg;
        sum+=deg;
    }
    
    if(sum == (2*(n-1)))
        cout<<"Yes";
    else cout<<"No";
    
    return 0;
}