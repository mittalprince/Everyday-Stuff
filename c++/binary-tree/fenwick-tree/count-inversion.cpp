/* 
Count inversions in an array | Set 3 (Using BIT)

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.

     Two elements a[i] and a[j] form an inversion if 
     a[i] > a[j] and i < j. For simplicity, we may 
     assume that all elements are unique.

     Example:
     Input:  arr[] = {8, 4, 2, 1}
     Output: 6
     Given array has six inversions (8,4), (4,2),
     (8,2), (8,1), (4,1), (2,1).     

Problem Statement link https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int getSum(vector<int> BIT, int index){
	int sum = 0;

	while(index>0){
		sum+= BIT[index];

		index -= (index & (-index));
	}

	return sum;
}

void updateBIT(vector<int>& BIT, int n, int index, int val){

	while(index <= n){

		BIT[index]+= val;

		index += (index & (-index));
	}
}

int getCount(int arr[], int n){

	int max = INT_MIN;
	int conversion=0,i;
	for(i=0;i<n;i++)
		if(max < arr[i])
			max = arr[i];

	vector<int> BIT(max+1, 0);

	for(i=n-1;i>=0;i--){
		conversion += getSum(BIT, arr[i]-1);

		updateBIT(BIT, max, arr[i], 1);
	}

	return conversion;

}

int main(){

	int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << "Number of inversions are : " << getCount(arr,n)<<endl;
	return 0;
}