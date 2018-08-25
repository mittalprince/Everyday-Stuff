#include<iostream>
#include<set>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n,no,q;
    multiset<long long> s;
    cin>>n;
    while(n--){
        cin>>q;
        if(q==1){
            cin>>no;
            s.insert(no);
        }
        else if(q==2){
            cin>>no;
            auto it = s.find(no);
            if(it == s.end())
                cout<<"-1"<<endl;
            else
                s.erase(it);
        }
        else if(q==3){
            if(!s.empty())
                cout<<*(--s.end())<<endl;
            else cout<<"-1"<<endl;
        }
        else {
            if(!s.empty())
                cout<<*(s.begin())<<endl;
            else cout<<"-1"<<endl;
        }
        
    }
    
    return 0;
    
}