/* 
Sieve of Eratosthenes

Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 

Problem statement link https://www.geeksforgeeks.org/sieve-of-eratosthenes/

*/

#include<iostream>
#include<cstring>

using namespace std;

void SieveOfEratosthenes(int n){

	bool prime[n+1];
	memset(prime, true, n+1);

	for(int i=2; i*i <= n; i++){

		if(prime[i]){
			for(int p = 2*i; p<=n ; p += i)
				prime[p] = false;
		}
	}

	for(int i=2;i<n;i++)
		if(prime[i])
			cout<<i<<" ";
}

int main(){

	int n = 30;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n);

    cout<<endl;

	return 0;
}