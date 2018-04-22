/*
Arrange given numbers to form the biggest number

Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace std;

bool comparator(string a, string b){
    string A = a.append(b);
    string B = b.append(a);
    return A>B;
}

int main(){
  int n,i,N;
  cin>>n;
  vector<string> arr(n);
  for(i=0;i<n;i++){
    cin>>N;
    arr[i]=to_string(N);
  }

  sort(arr.begin(), arr.end(),comparator);
  for(i=0;i<n;i++){
    cout<<arr[i];
  }
  cout<<endl;

  return 0;
}
