/*
Largest Sum Contiguous Subarray
      Kadnes algorithm
*/

#include<iostream>
#include<climits>

using namespace std;

int subarray_sum(int arr[], int size){
  int max1 = INT_MIN;
  int max2 = 0;

  for(int i=0;i<size;i++){
    max2 = max2+ arr[i];
    if(max1<max2){
      max1=max2;
    }
    if(max2<0){
      max2=0;
    }
  }
  return max1;
}

int main(){

  int arr[] = {12 + 8 - 8 + 9 - 9 + 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int max_sum = subarray_sum(arr,n);
  cout<<max_sum<<endl;

  return 0;
}
