#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

long long arr[100000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,no,i,j,sum=0;
    
    cin>>n;
    memset(arr, 0, n);
    for(i=0;i<n;i++)
        cin>>arr[i];

    int temp = 0, temp2= 0;

    for(i=0;i<n;i++){
        temp = 0;
        for(j=i;j<n;j++){
            temp = temp | arr[j];  
            sum+= temp;
        }
    }
    
    cout<<sum<<endl;
    return 0;
}