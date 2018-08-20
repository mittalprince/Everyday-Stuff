/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/little-monk-and-swaps/  */

#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
     
using namespace std;
     
struct node {
    long long data;
    node* left;
    node* right;
};
     
node* newNode(long long item) {
    node* temp =  new node;
    temp->data = item;
    temp->left = temp->right = nullptr;
     
    return temp;
}
     
void insert(struct node* root, long long size){
        
    queue<struct node*> q;
    q.push(root);
    long long index = 0,val;
    index++;
    
    while (!q.empty()&& index<size) {
        struct node* temp = q.front();
        q.pop();
        
        if(index<size){
             
             if (!temp->left) {
                 cin>>val;
                temp->left = newNode(val);
                index++;
            } 
            q.push(temp->left);
                    
        }
     
        if(index<size){
            
            if (!temp->right) {
                cin>>val;
                temp->right = newNode(val);
                index++;
            }
            q.push(temp->right);
        }    
    
    }
}
     
void inorder(node* root,long long order[]){
        
    static long long index = 0;
    if (root != nullptr) {
        inorder(root->left,order);
        order[index] = root->data;
        index++;
        inorder(root->right,order);
    }
}
     
long long minSwaps(long long arr[], long long n){
        
    pair<long long, long long> arrPos[n];
    for (long long i = 0; i < n; i++){
            
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
     
    sort(arrPos, arrPos + n);
 
    vector<bool> vis(n, false);
     
    long long ans = 0;
     
    for (long long i = 0; i < n; i++){
            \
        if (vis[i] || arrPos[i].second == i)
            continue;
     
        long long cycle_size = 0;
        long long j = i;
        while (!vis[j]){
               
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        ans += (cycle_size - 1);
        }
     
    return ans;
}
     
int main(){
        
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    long long N,temp;
    node * root = nullptr;
    cin>>N;
        
    long long Order[N];
        
    cin>>temp;
    root = newNode(temp);
        
    insert(root,N);
        
    inorder(root,Order);
    
    long long count = minSwaps(Order,N);
        
    cout<<count;
        
    return 0;

}