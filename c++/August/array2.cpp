// https://www.geeksforgeeks.org/minimum-number-of-changes-required-to-make-the-given-array-an-ap/

#include<bits/stdc++.h>

using namespace std;

int minimumChanges(int a[], int n, int d){
    int maxFreq = INT_MIN;

    unordered_map<int, int> freq;

    for(int i=0; i<n; i++){
        int a0 = a[i] - i*d;

        if(freq.find(a0) != freq.end()){
            freq[a0]++;
        }
        else{
            freq[a0] = 1;
        }

        if(maxFreq < freq[a0]){
            maxFreq = freq[a0];
        }
    }

    return (n-maxFreq);
}

int main(){
    int n, d;
    cin>>n>>d;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<minimumChanges(a, n, d)<<endl;
    return 0;
}