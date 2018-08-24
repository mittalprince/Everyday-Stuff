/* Probleme statement link https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

To understand logic https://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a


Binary Indexed Tree or Fenwick Tree

Let us consider the following problem to understand Binary Indexed Tree.

We have an array arr[0 . . . n-1]. We should be able to
1 Find the sum of first i elements.
2 Change value of a specified element of the array arr[i] = x where 0 <= i <= n-1.

*/

#include<iostream>
#include<vector>

using namespace std;

int getSum(vector<int> BIT, int index){

	int sum = 0;
	index++;

	while(index > 0){

		sum += BIT.at(index);

		index = index - (index & (-index));
	}

	return sum;
}

void update_BIT(vector<int> &BIT, int n, int index, int val){

	index++;

	while(index <= n){

		BIT.at(index) += val;

		index = index + (index & (-index));
	}

}

vector<int> get_BIT(int arr[], int n){

	vector<int> BIT(n+1);

	for(int i=1;i<=n; i++){
		BIT[i] = 0;
	}

	for(int i=0; i<n ; i++)
		update_BIT(BIT, n, i, arr[i]);

	return BIT;
}

int main(){

	int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> BIT = get_BIT(arr, n);

	for(int i=1; i<=n ; i++)
		cout<<BIT.at(i)<<" ";

	cout<<endl;

	cout<<getSum(BIT, 5)<<endl;;

	arr[3]+= 6;
	update_BIT(BIT, n, 3, 6);

	cout<<getSum(BIT, 5)<<endl;

	for(int i=1; i<=n ; i++)
		cout<<BIT.at(i)<<" ";

	cout<<endl;

	return 0;
}