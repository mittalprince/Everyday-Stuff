#include <iostream>
using namespace std;

int main() {
	int arr[] = {10, 20, 30, 40};
	//int ans = bitonic(arr, sizeof(arr)/sizeof(int));
  int max = 0;
  int n =sizeof(arr)/sizeof(int);
  //int n=4;
  for(int j=0 ; j<n ; ++j ) {
    int   cur_len = 0;
    int i = j; //Main loop control variable should be different than internal loop control variable
      while(arr[i+1] >= arr[i] && i<n) {
          ++i;
          ++cur_len;
      }

    //   if(cur_len == 0){ //If we did not find any increasing sequence no point in finding decreasing one
    //       continue;
    //   }
      while(arr[i] >= arr[i+1] && i<n - 1) { //This loop was going out of array arr
          ++i;
          ++cur_len;
      }
     ++cur_len; //Current count starts from 0 adding 1 makes it start from 1


      if(cur_len > max)
          max = cur_len;
  }
	cout << endl <<max<<endl;
	cout<<n;
	return 0;
}
