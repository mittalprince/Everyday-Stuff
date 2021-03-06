#include<iostream>

using namespace std;

void max_heap(int arr[], int i, int N){
	
	int left = 2*i;
	int right = 2*i +1;
	int largest;

	if(left<= N && arr[left] >= arr[i]){
		largest = left;
	}
	else  largest =i;
	if(right<= N && arr[right] >= arr[largest]){
		largest = right;
	}

	if(largest != i){
		swap(arr[i], arr[largest]);
		max_heap(arr, largest, N);
	}
}

int main(){
	
	int arr[] = {0,1,4,3,7,8,9,10};

	int N = sizeof(arr)/sizeof(arr[0]);
	N--;
	for(int i=N/2; i>=1; i--){
		max_heap(arr, i, N);
	}

	for(int i=1;i<=N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}