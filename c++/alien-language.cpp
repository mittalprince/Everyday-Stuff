/* Problem statement link  https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/alien-language/ */

#include<iostream>
#include<unordered_map>
#include<cstring>

using namespace std;

int main(){
    
    long long t, max, count;
    string s, n;
    char p;
    int a[230];
    
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        max = 0, count = 0;
        cin>>s;
        for(long long i=0;s[i]!='\0'; i++){
            p = s[i];
            a[p]++;
        }
        cin>>n;
        for(long long i=0;n[i]!='\0'; i++){
            if(a[n[i]]){
                count++;
                if(max < count)
                    max= count;
            }
            else count = 0;
        }
        
        if(max){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}