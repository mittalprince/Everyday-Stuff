    #include<iostream>
    #include<queue>
     
    using namespace std;
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long N,M,no;
        cin>>M>>N;
        priority_queue<long long> q;
        for(long long i=0; i<M; i++){
            cin>>no;
            q.push(no);
        }
        long long sum=0,temp;
        for(long long i=0; i<N; i++){
            
            sum+= q.top();
            temp = q.top(); q.pop();
            if(temp>1){
                q.push(temp-1);
            }
        }
        
        cout<<sum<<endl;
        return 0;
    }