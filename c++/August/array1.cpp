#include<bits/stdc++.h>

using namespace std;

int DecreasingArray(int a [], int n){

    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        if( !pq.empty() && pq.top() < a[i]){
            sum += (a[i] - pq.top());
            pq.pop();
            pq.push(a[i]);
        }
        pq.push(a[i]);
    }

    return sum;
}

int main(){
    int n;
    cin>> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<DecreasingArray(a, n)<<endl;
    return 0;
}



// https://www.geeksforgeeks.org/minimum-incrementdecrement-to-make-array-non-increasing/