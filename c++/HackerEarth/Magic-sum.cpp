/* Problem statement link --> 

https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/magic-sum/

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    ll value = 0;
    node* left = nullptr;
    node* right = nullptr;
};

node* newNode(ll value) {
    node* temp = new node;
    temp->value = value;
    return temp;
}

void count_max(node* root, ll& Max) {
    if(root == nullptr)
        return;
    
    count_max(root->left, Max);
    count_max(root->right, Max);

    ll l=0, r=0;

    if(root->left)
        l = root->left->value;
    if(root->right)
        r = root->right->value;
    
    Max = max(Max, root->value + l +r);
    root->value = max(root->value + l, root->value + r);
}

void make_tree(node*& root, ll arr[], ll n, ll i) {
    root = newNode(arr[i]);

    if((2*i+1) < n)
        make_tree(root->left, arr, n, 2*i+1);
    if((2*i+2) < n)
        make_tree(root->right, arr, n, 2*i+2);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll arr[n];
        for(ll i = 0; i < n; ++i) {
            cin>>arr[i];
        }

        node* root = nullptr; 
        make_tree(root, arr, n, 0);

       ll Max = LONG_LONG_MIN;

       count_max(root, Max);
       cout<<Max<<endl;
    }

    return 0;
}