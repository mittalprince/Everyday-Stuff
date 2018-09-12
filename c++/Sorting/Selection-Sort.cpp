#include<iostream>
#include<algorithm>

using namespace std;

void SelectionSort(int arr[], int n){

	for(int i=0; i<n; i++){
		int min = i;

		for(int j = i+1; j<=n; j++){
			if(arr[j] < arr[min])
				min = j;
		}

		if(min != i)
			swap(arr[min], arr[i]);
	}
}

void printArr(int arr[], int n){

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}

int main(){

	int arr[] = {12, 11, 13, 5, 6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArr(arr, n);
	cout<<endl;

	SelectionSort(arr, n-1);

	printArr(arr, n);
	cout<<endl;

	return 0;
}