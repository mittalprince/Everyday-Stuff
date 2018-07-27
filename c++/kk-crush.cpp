/* Problem statement link https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/exists/  */

    #include<iostream>
    #include<unordered_map>
     
    using namespace std;
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long t,n,no,k,q;
        cin>>t;
        while(t--){
            unordered_map<long long , long long>m;
            cin>>n;
            
            for(long long i=0;i<n;i++){
                cin>>no;
                m[no]++;
            }
            
            cin>>q;
            for(long long i=0;i<q;i++){
                cin>>k;
                if(m.find(k) != m.end())
                    cout<<"Yes"<<endl;
                    
                else cout<<"No"<<endl;
            }
            m.clear();
            
        }
        
        return 0;
        
    }

Language: C++14
