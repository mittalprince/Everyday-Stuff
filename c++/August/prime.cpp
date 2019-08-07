//  https://www.geeksforgeeks.org/sieve-sundaram-print-primes-smaller-n/

#include<bits/stdc++.h>

using namespace std;

vector<int> SieveOfSundaram(int n){
    
    int nNew = (n-2)/2;
    vector<int> prime;

    bool marked[nNew + 1];
    memset(marked, false, sizeof(marked));

    for(int i=1; i<= nNew; i++){
        for(int j=i; (i+j+2*i*j) <= nNew; j++){
            marked[i+j+2*i*j] = true;
        }
    }

    if(n >2){
        prime.push_back(2);
    }

    for(int i=1; i<= nNew; i++){
        if(marked[i] == false){
            prime.push_back(2*i+1);
        }
    }

    return prime;
}

int main(){

    int n;
    cin>>n;
    vector<int> v = SieveOfSundaram(n);
    for (auto ir = v.begin(); ir != v.end(); ++ir) 
        cout << *ir << " "; 
    return 0;
}