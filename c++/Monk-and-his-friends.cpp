/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long T,N,M,temp;
    
    cin>>T;
    while(T--){
        cin>>N>>M;
        
        unordered_map<long long, long long >m;
        
        while(N--){
            cin>>temp;
            m[temp] = 1;
        }
        while(M--){
            cin>>temp;
            if(m.find(temp) != m.end())
            cout<<"YES"<<endl;
            
            else{
                cout<<"NO"<<endl;
                m[temp] = 1;
            }
        }
    }
    
    return 0;
}