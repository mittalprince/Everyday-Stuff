    #include<iostream>
    #include<queue>
    #include<unordered_map>
    #include<algorithm>
     
    using namespace std;
     
    int main(){
        
        unordered_map<long long, long long> freq, m;
        priority_queue<long long> q;
        long long n,M;
        cin>>n>>M;
        
        while(n--){
            long long t;
            cin>>t;
            ++freq[t];
            
            if(m.find(freq[t]) == m.end())
                m[freq[t]] = t;
                
            else m[freq[t]] = max(m[freq[t]], t);
            
            q.push(freq[t]);
            
            long long v = q.top();
            
            cout<<m[v]<<" "<<v<<endl;
        }
        return 0;
    }