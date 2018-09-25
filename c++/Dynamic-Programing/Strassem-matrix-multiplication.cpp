#include<iostream>
#include<vector>

using namespace std;

void print(int arr[2][2]){

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;
}

void strassen(int a[2][2], int b[2][2] ){

	int c[2][2] = {0,0,0,0};

	int p[7] = {0,0,0,0,0,0,0};

	p[0] = a[0][0]*(b[0][1] - b[1][1]);
	p[1] = (a[0][0] + a[0][1])*b[1][1];
	p[2] = (a[1][0] + a[1][1])*b[0][0];
	p[3] = a[1][1]*(b[1][0] - b[0][0]);
	p[4] = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
	p[5] = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);
	p[6] = (a[0][0] - a[1][0])*(b[0][0] + b[0][1]);

	c[0][0] = p[3]+p[4]+p[5]-p[1];
	c[0][1] = p[0]+p[1];
	c[1][0] = p[2]+p[3];
	c[1][1] = p[0]+p[4] - p[2]-p[6];

	print(c);
}

int main(){

	int a[2][2] = {1,1,1,1};
	int b[2][2] = {1,1,1,1};

	cout<<"A matrix: "<<endl;
	print(a);
	cout<<"B matrix: "<<endl;
	print(b);

	strassen(a,b);

	return 0;
}