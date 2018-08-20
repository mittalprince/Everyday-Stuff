/*

Find a sorted subsequence of size 3 in linear time

Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.

Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30

Input:  arr[] = {1, 2, 3, 4}
Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

Input:  arr[] = {4, 3, 2, 1}
Output: No such triplet
*/

/*
                        Using Auxillary Space

#include<iostream>

using namespace std;

bool subarray(int arr[], int n){
    int min=0,max=n-1,i;
    int smaller[n], greater[n];

    smaller[0]=-1;
    for(i=1;i<n;i++){
      if(arr[i] <= arr[min]){
        smaller[i]= -1;
        min=i;
      }
      else{
        smaller[i]=min;
      }
    }
    greater[n-1]=-1;
    for(i=n-2;i>=0;i--){
      if(arr[i] >= arr[max]){
        greater[i]= -1;
        max=i;
      }
      else{
        greater[i]=max;
      }
    }
    for(i=0;i<n;i++){
      if(smaller[i]!= -1 && greater[i]!= -1){
        cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
        return true;
      }
    }
    return false;
}

int main(){
  int arr[]= {12, 11, 10, 5, 6, 2, 30};
  bool ans = subarray(arr, sizeof(arr)/sizeof(int));
  if(!ans){
    cout<<"No subarray exist"<<endl;
  }
  return 0;
}

*/

#include<iostream>
#include<climits>

using namespace std;

bool subarray(int arr[], int n){
  int lowest=INT_MAX, second_lowest=INT_MAX;
  int highest=0, saved_lowest=0;

  for(int i=0;i<n;i++){
    if(arr[i]<lowest){
      lowest=arr[i];
    }
    else if(arr[i]<second_lowest){
      saved_lowest=lowest;
      second_lowest=arr[i];
    }
    else{
      highest=arr[i];
      cout<<saved_lowest<<" "<<second_lowest<<" "<<highest<<endl;
      return true;
    }
  }
  return false;
}

int main(){
  int arr[]= {12, 11, 10, 5, 6, 2, 30};
  bool ans = subarray(arr, sizeof(arr)/sizeof(int));
  if(!ans){
    cout<<"No subarray exist"<<endl;
  }
  return 0;
}
