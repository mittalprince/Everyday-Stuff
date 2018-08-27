#include<iostream>
#include<queue>
#include<list>

using namespace std;

struct graph{

	bool visited=false;
	list<int> l;
	int value = 0;

};

void assign(graph a[], int u, int value){
	
	a[u].value = value;
}

void add(graph a[], int u, int v){
	a[u].l.push_back(v);
}


void BFS(graph a[]){
	
	queue<int> q;
	q.push(0);
	a[0].visited = true;

	while(!q.empty()){
		int t = q.front();
		q.pop();

		cout<<a[t].value<<endl;

		for(auto i: a[t].l){

			if(!a[i].visited){
				q.push(i);
				a[i].visited = true;
			}
		}
	}
}

int main(){

	graph a[4];

	assign(a,0,10);
	assign(a,1,20);
	assign(a,2,30);
	assign(a,3,40);

	add(a,0,1);
	add(a,1,2);
	add(a,1,3);
	add(a,2,3);

	BFS(a);

	return 0;
}

//baap bhai bacha