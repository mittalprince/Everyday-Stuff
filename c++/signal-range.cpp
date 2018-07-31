/* Problem statement link  https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/signal-range/ */

#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

long long arr[1000005], s[1000005];

void cal_signal_range(long long arr[], long long s[], long long n){
    
    stack<long long> stk;
    stk.push(0);
    
    s[0] = 1;
    
    for(long long i=1; i<n; i++){
        
        while(!stk.empty() && arr[stk.top()] <= arr[i])
            stk.pop();
            
        s[i] = stk.empty()? (i+1) : (i-stk.top());
        
        stk.push(i);
    }
}
void print(long long s[], long long n){
    for(long long i=0;i<n;i++)
        cout<<s[i]<<" ";
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        memset(arr,0,n);
        memset(s,0,n);
        
        for(long long i =0;i<n;i++){
            cin>>arr[i];
        }
        
        cal_signal_range(arr,s,n);
        print(s,n);
        cout<<endl;
        
    }
    return 0;
}