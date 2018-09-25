/* 
Problem statment link https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

/* 
Recursivre approach

int lcs(string x, string y, int m, int n){

	if(m==0 || n==0)
		return 0;

	if(x[m-1] == y[n-1])
		return 1+ lcs(x,y, m-1, n-1);

	else return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
}
*/

int lcs(string x, string y, int m, int n){

	int l[m+1][n+1];
	int i,j;

	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){

			if(i==0 || j==0)
				l[i][j] = 0;

			else if(x[i-1] == y[j-1])
				l[i][j] = 1+ l[i-1][j-1];

			else l[i][j] = max(l[i-1][j], l[i][j-1]);
		}
	}

	return l[m][n];
}

int main(){

	string x = "AGGTAB";
	string y = "GXTXAYB";

	int m = x.length();
	int n = y.length();

	cout<<"Length of LCS is "<<lcs(x,y,m,n)<<endl;

	return 0;
}