/* https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/b-sequence-f919fc86/   */

#include<iostream>
#include<unordered_map>
#include<set>
#include<iterator>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n,q,no,tatti,max=0,temp2=0;
    
    set<long long> s;
    unordered_map<long long, long long> m;
    
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>no;
        if(no>max)
            max= no;
        s.insert(no);
        m[no]++;
    }
    
    temp2=n;
    
    cin>>q;
    
    while(q--){
        
        cin>>tatti;
        if(tatti<max){
            if(m[tatti]<=1){
            s.insert(tatti);
            m[tatti]++;
            temp2++;
            }
        }
        else if(tatti > max){
            max = tatti;
            s.insert(tatti);
            m[tatti]++;
            temp2++;
        }
        cout<<temp2<<endl;
    }
    
    auto it= s.begin();
    while(it != s.end()){
        cout<< (*it) <<" ";
        m[*it]--;
        
        ++it;
    }
    
    auto temp = s.rbegin();
    while(temp != s.rend()){
        if(m[*temp]){
            cout<< (*temp) <<" ";
            m[*temp]--;
        }
        
        ++temp;
    }
    
    return 0;
}