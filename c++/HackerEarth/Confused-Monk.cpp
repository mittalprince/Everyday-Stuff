/* 
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-confused-monk/
*/

#include<bits/stdc++.h>

using namespace std;
unsigned long long  M =  1000000007;

unsigned long long   gcd(unsigned long long   A, unsigned long long   B) {
    if(B==0)
        return A;
    else
        return gcd(B, A % B);
}

unsigned long long modularExponentiation(unsigned long long   x,unsigned long long   n,unsigned long long   M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long   temp,f,n,b;
    cin>>n;
    unsigned long long   a[n];
    cin>>a[0];
    temp = a[0], f= a[0];
    
    for(unsigned long long   i=1; i<n; i++){
        cin>>a[i];
        temp = gcd(temp, a[i]);
    }
    unsigned long long temp1 = modularExponentiation(a[0], temp, M);
    for(int i=1; i<n; i++){
          temp1 = temp1*modularExponentiation(a[i],temp, M);
          temp1 = temp1%M;
    }
    //cout<<temp<<" "<<f<<endl;
    cout<<temp1<<endl;
    
    return 0;
    
}