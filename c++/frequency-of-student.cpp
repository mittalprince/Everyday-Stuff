/* Problem statement link https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/frequency-of-students/ */

#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main(){
    
    map<string, int> m;
    int n;
    string name;
    cin>>n;
    while(n--){
        cin>>name;
        m[name]++;
    }
    auto it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    return 0;
}