#include<iostream>
#include<vector>

using namespace std;


int main(){
    long long n,i,q,l,r,temp,temp1;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>q;
    while(q--){
        cin>>l>>r;

        for(i=l;i<=r;i++){
            temp=n-i+1;
            temp1=a[temp-1];
            a[temp-1]=a[i-1];
            a[i-1]=temp1;
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
