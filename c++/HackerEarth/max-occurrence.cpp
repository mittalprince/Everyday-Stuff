/* Problem statement link https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-occurrence-9/  */

#include<iostream>
#include<cstring>

using namespace std;

int main() {
    string s;
    int i,pos,max,a[230],p;
    memset(a,0,sizeof(a));
    getline(cin,s);
    
    for(i=0;i<s.length();i++){
        p=s[i];
        a[p]++;
    }

    max=a[0];
    pos=0;
    for(i=1;i<=127;i++){
        if(a[i]!=0){
            if(max<a[i]){
                max=a[i];
                pos=i;
            }
            else if(max==a[i]){
                if(pos>i){
                    max=a[i];
                    pos=i;
                }
            }
        }
    }
    cout<<(char)pos<<" "<<max;
return 0;
}