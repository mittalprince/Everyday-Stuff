/* Implement of Union-Find Algorithm to find disjoint sets */

#include<iostream>
#include<vector>

using namespace std;

void initialize(vector<int> &arr, vector<int>& s){

	for(int i=0; i<arr.size(); i++){
		arr.at(i) = i;
		s.at(i) = 1;
	}
}

int root(vector<int> &arr, int i){

	while(arr[i] != i){
		arr[i] = arr[arr[i]];
		i = arr[i];
	}

	return i;
}

void weighted_union(vector<int> &arr, vector<int> &s, int a, int b){

	int root_a = root(arr, a);
	int root_b = root(arr, b);

	if(s.at(root_a) <= s.at(root_b)){
		arr.at(root_a) = root_b;
		s.at(root_b) += s.at(root_a);
	}
	
	else {
		arr.at(root_b) = root_a;
		s.at(root_a) += s.at(root_b);
	}
	
}

bool find(vector<int> arr, int a, int b){
	if(root(arr, a) == root(arr, b))
		return true;

	else false;
}



int main()
{
  int N = 10;

  vector < int > arr(N);
  vector < int > s(N);

  initialize(arr,s);

  weighted_union(arr, s, 2, 1);
  weighted_union(arr, s, 4, 3);
  weighted_union(arr, s, 8, 4);
  weighted_union(arr, s, 9, 3);
  weighted_union(arr, s, 6, 5);

  for(auto& y: arr)
  {
    cout<<y<<" ";
  }

  cout<<endl;

  if(find(arr,2,3))
  {
    cout<<"yes"<<endl;
  }
  else
  {
    cout<<"no"<<endl;
  }

  return 0;
}

