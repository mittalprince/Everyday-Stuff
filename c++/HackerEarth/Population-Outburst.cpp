#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nodes,child,parent;
    cin>>nodes;
    cin>>child;
    
    int arr[nodes + 1];
    int level[nodes+1];
    
    // queue of index, siblings
    queue< pair<long long, long long> > q;

    for(long long i=1; i<=child ; i++){
        if(q.size() <= nodes)
        q.push(make_pair(0, i));
    }
    
    arr[0] = 0;
    level[0] = 0;
    
    for(long long i=0; i<nodes ; i++){
        
        cin>>parent;
        cin>>child;
        
        arr[i+1] = parent;
        level[i+1] = level[q.front().first]+1;
        cout<<arr[q.front().first]<<" "<<level[i+1]<<" "<<q.front().second<<endl;
        
        q.pop();
        if(q.size() <= nodes){
            
        for(long long j=1; j<=child; j++){
            if(q.size() <= nodes)
            q.push(make_pair(i+1,j));
            
            else break;
        }
        }
    }
    
    return 0;
}