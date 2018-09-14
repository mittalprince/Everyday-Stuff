#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

struct node{
	int weight;
	pair<int, int> edge;
};

struct ds{
	int size;
	int val;
};

bool comparator(const node& node1, const node& node2){
	return node1.weight < node2.weight;
}

vector<ds> arr;

void initialize(int n){

	for(int i=0; i<n; i++){
		ds temp;
		temp.val = i;
		temp.size = 1;

		arr.push_back(temp);
	}
}

int root(int i){
	while(arr.at(i).val != i){
		arr.at(i).val = arr.at(arr.at(i).val).val;
		i = arr.at(i).val;
	}

	return i;
}

void Union(int a, int b){
	int root_a = root(a);
	int root_b = root(b);

	if(root_a == root_b)
		return;

	if(arr.at(root_a).size < arr.at(root_b).size){
		arr.at(root_a).val = arr.at(root_b).val;
        arr.at(root_b).size +=  arr.at(root_a).size;
	}

	else{
		arr.at(root_b).val = arr.at(root_a).val;
        arr.at(root_a).size +=  arr.at(root_b).size;
	}
}

bool find(int a, int b){
	if(root(a) == root(b))
		return true;
	
	else false;

}

int kruskal(vector<node> &graph){
	int mincost = 0;
	vector<node> result;

	for(auto i: graph){
		if(!find(i.edge.first, i.edge.second)){
			result.push_back(i);
			Union(i.edge.first, i.edge.second);
			mincost += i.weight;
		}
	}

	for(auto y: result){
		cout<<y.edge.first<<" -- "<<y.edge.second<<" == "<<y.weight<<endl;
	}
	return mincost;
}

int main(){

	int nodes, edges;
    cin>>nodes>>edges;

    vector<node> graph(edges);

    initialize(nodes);

    for(int i = 0; i < edges; ++i) {
        int x, y, w;
        cin>>x>>y>>w;
        graph.at(i).weight = w;
        graph.at(i).edge = make_pair(x, y);
    }

    sort(graph.begin(), graph.end(), comparator);
    cout<<"Total cost "<<kruskal(graph)<<endl;
}


