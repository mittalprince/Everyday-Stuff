/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/speed-7/  */

#include<iostream>
#include<cstring>

using namespace std;

long long arr[100000];

long long speed(long long arr[], int n){
    long long count = 1;
    
    cin>>arr[0];
    
    for(long long i=1; i<n; i++){
        cin>>arr[i];
        if(arr[i-1] > arr[i])
            count++;
    }
    
    return count;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long T,n;
    
    cin>>T;
    
    while(T--){
        
        cin>>n;
        memset(arr,0,n);
        
        cout<<speed(arr, n)<<endl;
    }
    
    return 0;
}