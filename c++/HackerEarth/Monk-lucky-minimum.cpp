/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-lucky-minimum-3/ */

#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

long long minimum(unordered_map<long long, long long> m, long long n){
    
    long long min = INT_MAX;
    long long data;
    
    while(n--){
        cin>>data;
        if(min > data)
            min = data;
        
        if(m.find(data) != m.end())
            m[data]++;
        else m[data]=1;
    }
    
    return m[min];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long T,n;
    
    cin>>T;
    while(T--){
        
        cin>>n;
        unordered_map<long long, long long> m;
        
        if((minimum(m,n))%2 == 0)
            cout<<"Unlucky"<<endl;
            
        else cout<<"Lucky"<<endl;
        m.clear();
    }
    
    return 0;
}