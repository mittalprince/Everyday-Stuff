#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

long long arr[1000005], brr[1000005];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n,Q,no,k;
    cin>>n;
    
    memset(arr,0,n);
    
    for(long long i=0;i<3;i++){
        for(long long j=0;j<n;j++){
            cin>>no;
            arr[j]+=no;
        }
    }
    
    priority_queue<long long, vector<long long>, greater<long long> > q;
    
    for(long long i=0;i<n;i++)
        q.push(arr[i]);
        
    cin>>Q;
    
    while(Q--){
        cin>>k;
        
        if(k > q.size())
            cout<<"-1"<<endl;
        
        else{
            
            memset(brr, 0, k);
            long long i=0;
            while(!q.empty() && i < k){
                
                brr[i] = q.top();
                q.pop();
                i++;
            }
            cout<<brr[k-1]<<endl;
            i=0;
            while(i<k-1){
                q.push(brr[i]);
                i++;
            }
        }
    }
    
    return 0;
}