#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

void initialize(){

	for(int i=0; i<arr.size(); i++){
		arr.at(i) = i;
	}
}

int root(int i){

	while(arr.at(i) != i){
		i = arr.at(i);
	}

	return i;
}

void Union(int a, int b){

	int root_a = root(a);
	int root_b = root(b);

	arr[root_a] = root_b;
}

bool find(int a, int b){
	return (root(a) == root(b));
}

int main(){

	arr = {0,1,2,3,4,5};

	initialize();

	Union(1, 0);
    Union(0, 2);
    Union(3, 4);
    Union(1, 4);

    if(find(1,4))
    	cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

	if(find(3,5))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}