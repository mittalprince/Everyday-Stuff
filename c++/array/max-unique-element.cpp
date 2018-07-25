/* 
Maximum Unique Element in every subarray of size K

Given an array and an integer K. We need to find the maximum of every segment of length K which has no duplicates in that segment.

Examples:

Input : a[] = {1, 2, 2, 3, 3}, 
          K = 3.
Output : 1 3 2
For segment (1, 2, 2), Maximum = 1.
For segment (2, 2, 3), Maximum = 3.
For segment (2, 3, 3), Maximum = 2. 

Input : a[] = {3, 3, 3, 4, 4, 2},
          K = 4.
Output : 4 Nothing 3

Problem statement link https://www.geeksforgeeks.org/maximum-unique-element-every-subarray-size-k/

*/

#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

int main(){

  int arr[] = {3, 3, 3, 4, 4, 2};
  int k =4;
  int n = sizeof(arr)/sizeof(int);

  unordered_map<int, int> m;
  set<int> s;

  for(int i=0; i<k; i++){

    if(m.find(arr[i]) != m.end())
      m[arr[i]]++;
    else
      m[arr[i]] = 1;

    if(m[arr[i]] == 1)
      s.insert(arr[i]);

    else {
      if(!s.empty())
        s.erase(arr[i]);
    }
  }
  if(!s.empty())
    cout<<(*s.rbegin())<<endl;
  else
    cout<<"Nothing"<<endl;

  for(int i=k;i<n;i++){

    if(m.find(arr[i]) != m.end())
      m[arr[i]]++;
    else
      m[arr[i]] = 1;

    if(m[arr[i]] == 1)
      s.insert(arr[i]);

    else {
      if(!s.empty())
        s.erase(arr[i]);
    }
    --m[arr[i-k]];
    if( m[arr[i-k]]== 1)
      s.insert(arr[i-k]);

    else {
      if(!s.empty())
        s.erase(arr[i-k]);
    }

    if(!s.empty())
      cout<<(*s.rbegin())<<endl;

    else cout<<"Nothing"<<endl; 

  }

  return 0;
}