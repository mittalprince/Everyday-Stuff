#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long t,n,k,no;
    
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long sum=0;
        priority_queue<long long> q;
        while(n--){
            cin>>no;
            q.push(no);
        }
        while(k--){
            long long temp = q.top();
            sum+= temp;
            q.pop();
            q.push(temp/2);
        }
        
        cout<<sum<<endl;
    }
    return 0;
}