/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/

*/

#include<iostream>
#include<unordered_map>

using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T,N,X,n,dis;
    cin>>T;
    unordered_map<long long , long long> m;
    while(T--){
        dis=0;
        cin>>N>>X;
        while(N--){
        cin>>n;
        if(m.find(n) == m.end()){
            dis++;
            m[n] =1;
            }
        }
        
        if(X < dis)
            cout<<"Average"<<endl;
        else if(X ==dis )
            cout<<"Good"<<endl;
            
        else cout<<"Bad"<<endl;
        m.clear();
        
    }
    
    return 0;
}