#include<iostream>

using namespace std;

void Merge(int arr[], int P, int Q, int R){

	int n1 = Q-P+1;
	int n2 = R-Q;

	int i,j,k;
	int l[n1], r[n2];

	for(i=0; i<n1; i++)
		l[i] = arr[P+i];

	for(j=0; j<n2; j++)
		r[j] = arr[Q+j+1];

	i=0, j=0, k=P;

	while(i< n1 && j<n2){

		if(l[i] <= r[j]){
			arr[k] = l[i];
			i++;
		}
		else {
			arr[k] = r[j];
			j++;
		}

		k++;
	}

	while(i<n1){
		arr[k] = l[i];
		i++;
		k++;
	}

	while(j<n2){
		arr[k] = r[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int start, int end){

	if(start < end){
		int mid = (start +(end-start)/2);

		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end);

		Merge(arr, start, mid, end);
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

	MergeSort(arr, 0, n-1);

	printArr(arr, n);
	cout<<endl;

	return 0;

}