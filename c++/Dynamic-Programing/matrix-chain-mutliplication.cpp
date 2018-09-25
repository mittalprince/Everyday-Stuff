#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int chainOrder(int p[], int n){

	int m[n][n];

	int i,j,k,d,q;
	
	for (i=1; i<n; i++) 
        m[i][i] = 0; 

    for(d=2; d<n; d++){
    	for(i=1; i<n-d+1; i++){
    		j = i+d-1;
    		m[i][j] = INT_MAX;
    		for(k=i; k<=j; k++){
    			q = m[i][k] + m[k+1][j] +p[i-1]*p[k]*p[j];
    			if(q < m[i][j])
    				m[i][j] = q;
    		}
    	}
    }

    return m[1][n-1];
}

int main(){

	int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    cout<<"Minimum number of multiplications is "<< chainOrder(arr, size)<<endl; 
	return 0;
}


