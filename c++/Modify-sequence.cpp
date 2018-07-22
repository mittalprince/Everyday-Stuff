/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/modify-sequence/description/ */

#include<iostream>

using namespace std;

void sequence(long long n){
    long long num, even=0, odd=0;
    
    for(long long i=0;i<n; i++){
        cin>>num;
        if(i%2 == 0)
            even+= num;
        else odd+= num;
    }
    
    if(even == odd){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long T;
    cin>>T;
    
    sequence(T);
    
    return 0;
}