/* Given an array A of size 'N' and an integer k, find the maximum for each
and every contiguous subarray of size k.

Input :

    First line contains 2 space separated integers 'N' and 'k' .
    Second line contains 'N' space separated integers denoting array elements.

Output:

    Space separated Maximum of all contiguous sub arrays of size k. */


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(long long int i=0;i<n;i++){
        cin>>v[i];
    }

    for(long long int i=0;i<=n-k;i++){
        long long int max=INT_MIN;
        for(long long int j=0;j<k;j++){
            if(v[i+j]>max)
            max = v[i+j];
        }
        cout<<max<<" ";

    }

    return 0;
}
