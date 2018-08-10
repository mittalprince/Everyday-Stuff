    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<iterator>
    #include<cstring>
     
    using namespace std;
     
    long long v[1000005];
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long n,no,q,k;
        char c;
        cin>>n;
        memset(v,0,n);
        for(long long i=0;i<n;i++){
            cin>>v[i];
        }
        
        sort(v, v+n);
        
        cin>>q;
        while(q--){
            cin>>k;
            cin>>c;
            if(c == 'L'){
                cout<<v[n-k]<<endl;
            }
            else {
                cout<<v[k-1]<<endl;
            }
        }
        
        return 0;
    }