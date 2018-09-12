#include<iostream>

using namespace std;

void Sort(int arr[], int n){

	for(int j=1; j<n; j++){
		int key = arr[j];

		int i = j-1;
		while(i>=0 && arr[i] > key){
			arr[i+1] = arr[i];
			i--;
		}

		arr[i+1] = key;
	}
}

void printArr(int arr[], int n){

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}

int main(){

	int arr[10] = {6,4,6,8,9,1,3,5,3,7};

	printArr(arr, 10);
	cout<<endl;
	Sort(arr, 10);
	printArr(arr, 10);
	cout<<endl;

	return 0;
}