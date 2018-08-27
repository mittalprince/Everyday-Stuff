#include<iostream>
#include<queue>
#include<set>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);6
    
    long long n,no;
    string str;
    multiset<long long> s;
    cin>>n;
    while(n--){
        cin>>str;
        
        if(str == "Push"){
            cin>>no;
            s.insert(no);
            
        }
        else if(str == "Diff"){
            if(s.empty())
                cout <<"-1\n";
            else if(s.size()==1)
            {
                cout << "0\n";
                s.erase(s.begin());
            }
            else
            {
                auto it=s.end();
                it--;
                int diff=(*it)-(*s.begin());
                cout << diff << endl;
                s.erase(it);
                s.erase(s.begin());
            }
        }
        else if(str == "CountHigh"){
            if(!s.empty()){
            auto it = --s.end();
            cout<<s.count(*it)<<endl;
            }
            else cout<<"-1"<<endl;
        }
        else {
            if(!s.empty()){
            auto it = s.begin();
            cout<<s.count(*it)<<endl;
            }
            else cout<<"-1"<<endl;
        }
    }
    
    return 0;
}