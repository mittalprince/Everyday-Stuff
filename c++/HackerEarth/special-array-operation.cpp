#include<iostream>
#include<queue>
#include<set>
#include <vector>
#include <climits>
 
using namespace std;
 
int main(){
    
    multiset<long long> s;
    long long q,sum=0,n;
    cin>>n>>q;
    while(n--){
        long long t;
        cin>>t;
        sum+=t;
        s.insert(t);
        
    }
    long long new_sum = sum;
    vector<long long> v;
    long long g=0, h=0;
    while(q--) {
        long long k;
        cin>>k;
        
        if(k == 0)
            cout<<new_sum<<endl;
 
        else if(k > h) {
            g = k-h;
            
            while(g--){
                ++h;
                auto i1 = s.begin();
                auto i2 = s.end();
                --i2;
                
                s.insert(*i2 - *i1);
                sum-= 2*(*i1);
                v.push_back(sum);
                s.erase(i1);
                s.erase(i2);
            }
 
            cout<<v.at(k-1)<<endl;
        }
        else
            cout<<v.at(k-1)<<endl;
    }
    return 0;
}