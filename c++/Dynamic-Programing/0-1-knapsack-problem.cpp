/*   

Problem statement link https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/  

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int wt[], int prof[], int W, int n){

	int i,w;
	int k[n+1][W+1];

	for(int i=0; i<=n; i++){
		for(int w=0; w<=W; w++){

			if(i==0 || w==0)
				k[i][w] = 0;

			else if(wt[i-1] <= w)
				k[i][w] = max(prof[i-1] + k[i-1][w-wt[i-1]], k[i-1][w]);

			else k[i][w] = k[i-1][w];
		}
	}

	return k[n][W];
}

int main(){

	int prof[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(prof)/sizeof(prof[0]); 

    cout<<"Max profit is "<<knapsack(wt, prof, W, n)<<endl;
	return 0;
}
