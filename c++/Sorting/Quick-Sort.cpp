#include<iostream>
#include<algorithm>

using namespace std;

int Partition(int arr[], int p, int r){

	int x = arr[r];
	int i = p-1;

	for(int j=p; j<r; j++){
		if(arr[j] <= x){
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i+1], arr[r]);

	return i+1;

}

void QuickSort(int arr[], int start, int end){

	if(start < end){

		int q = Partition(arr, start, end);
		QuickSort(arr, start, q-1);
		QuickSort(arr, q+1, end);
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

	QuickSort(arr, 0, n-1);

	printArr(arr, n);
	cout<<endl;

	return 0;
}