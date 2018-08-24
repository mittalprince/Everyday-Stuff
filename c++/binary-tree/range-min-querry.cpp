/* We have an array arr[0 . . . n-1]. We should be able to efficiently find the minimum value from index qs (query start) to qe 
(query end) where 0 <= qs <= qe <= n-1.

Problem statement link https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/

*/

#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>

using namespace std;

void make_tree(int tree[], int start, int end, int index, int arr[]){

	if(start == end){
		tree[index] = arr[start];
		return;
	}
	int mid = (start+end)/2;

	make_tree(tree, start,mid, 2*index+1, arr);
	make_tree(tree, mid+1,end, 2*index+2, arr);

	tree[index] = min(tree[2*index+1],tree[2*index+2]);

	return ;
}

int getMin(int tree[], int s, int e, int index, int l, int r){

	if(l<= s && r>= e)
		return tree[index];

	if(r<s || l>e)
		return INT_MAX;

	if(s != e){
		int mid = (s+e)/2;

		return min(getMin(tree,s,mid,2*index+1,l,r) , getMin(tree,mid+1,e,2*index+2,l,r));
	}
}

int main(){

	int arr[] ={1,3,2,7,9,11};
	int size = sizeof(arr)/sizeof(arr[0]);
	int tree[2*size -1];
	make_tree(tree, 0, size-1, 0, arr);
	cout<<getMin(tree, 0, size-1, 0, 3,5)<<endl;
	return 0;
}