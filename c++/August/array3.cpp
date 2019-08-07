// https://www.geeksforgeeks.org/make-array-elements-equal-in-minimum-steps/

#include<bits/stdc++.h>

using namespace std;

int minSteps(int n, int m){
    if(n == 1){
        return 0;
    }

    else if (n == 2){
        return m;
    }
    else {
        return 2*m+ (n-3);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<minSteps(n,m)<<endl;
    return 0;
}