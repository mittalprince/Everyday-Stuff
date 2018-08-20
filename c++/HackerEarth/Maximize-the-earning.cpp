/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-the-earning-137963bc-323025a6/  */

#include<iostream>
#include<cstring>

using namespace std;

long long arr[100000];

long long earning(long long arr[], int size){
    
    long long count = 0;
    long long max = 0;
    
    for(long long i= 0; i<size; i++){
        
        cin>>arr[i];
        
        if(arr[i] > max){
            max = arr[i];
            count++;
        }
    }
    return count;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long S,n,k,ans;
    
    cin>>S;
    
    while(S--){
        cin>>n>>k;
        memset(arr,0,n);
    
        ans = earning(arr, n)*k;
        cout<<ans<<endl;
        
    }
    
    return 0;
}