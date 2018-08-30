/* 
Shortest path to reach one prime to other by changing single digit at a time

Given two four digit prime numbers, suppose 1033 and 8179, we need to find the shortest path from 1033 to 8179 by altering 
only single digit at a time such that every number that we get after changing a digit is prime. 
For example a solution is 1033, 1733, 3733, 3739, 3779, 8779, 8179 

Problem statement link https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/

*/

#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

struct node{

    int visited = 0;
    list<int> l;
};

void addEdge(vector<node> &graph, int u, int v){

    graph[u].l.push_back(v);
    graph[v].l.push_back(u);
}

void SieveOfEratosthenes(vector<int> &v){

    int n = 9999;
    bool prime[n+1];
    memset(prime, true, n+1);

    for(int p=2; p*p <= n; p++){

        if(prime[p]){
            for(int i = 2*p; i<=n ; i += p)
                prime[i] = false;
        }
    }

    for(int i=1000; i<=n; i++)
        if(prime [i])
            v.push_back(i);
}

int BFS(vector<node> &graph, int index1, int index2){

    queue<int> q;
    graph[index1].visited = 1;
    q.push(index1);

    while(!q.empty()){

        int temp = q.front();
        q.pop();

        for(auto y: graph[temp].l){
            if(!graph[y].visited){
                graph[y].visited = graph[temp].visited+1;
                q.push(y);
            }

            if(y == index2)
                return graph[y].visited-1;
        }
    }
}

bool compare(int num1, int num2){

    string s1 = to_string(num1);
    string s2 = to_string(num2);

    int count = 0;

    if(s1[0] != s2[0])
        count++;
    if(s1[1] != s2[1])
        count++;
    if(s1[2] != s2[2])
        count++;
    if(s1[3] != s2[3])
        count++;

    return (count == 1);
}

int shortest_path(int num1, int num2){

    vector<int> v;
    SieveOfEratosthenes(v);

    vector<node> graph(v.size());

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(compare(v[i], v[j]))
                addEdge(graph, i, j);
        }
    }

    int index1, index2;

    for(int i=0; i<v.size(); i++)
        if(v[i] == num1)
            index1 = i;

    for(int i=0; i<v.size(); i++)
        if(v[i] == num2)
            index2 = i;

    return BFS(graph, index1, index2);

}

int main(){

    int num1 = 1033, num2 = 8179;
    cout << shortest_path(num1, num2)<<endl;
    return 0;
}