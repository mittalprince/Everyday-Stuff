/* Problem statement https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/all-vowels-2/ */

#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    
    int n;
    bool flag = false;
    unordered_map<char, int> m;
    string name;
    cin>>n;
    cin>>name;
    for(int i=0;i<n;i++){
        m[name[i]]++;
    }
    
    if(m['a'] && m['e'] && m['o'] && m['i'] && m['u'])
        flag = true;
    
    if(flag)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}