#include<bits/stdc++.h>

using namespace std;

/* Basic Recursive Method
int recursivePower(int x, int n){
	if(n==0)
		return 1;

	return x*recursivePower(x, n-1);
}
*/

/* Basic Iterative Method
int iterativePower(int x, int n){
	int result = 1;

	while(n>0){
		result = result*x;
		n--;
	}

	return result;
}
*/

// Optimized Recursive Method
int binaryExponentiation(int x, int n){
	if(n == 0)
		return 1;

	else if(n%2 == 0)
		return binaryExponentiation(x*x, n/2);
	else return x*binaryExponentiation(x*x, (n-1)/2);
}

/* Optimized Iterative Method
int binaryExponentiation(int x, int n){

	int result = 1;

	while(n>0){
		if(n%2 == 1){
			result = result*x;
		}

		x= x*x;
		n= n/2;
	}

	return result;
}
*/

int main(){
	int x,n;
	cin>>x>>n;
	cout<<binaryExponentiation(x,n)<<endl;
	return 0;
}