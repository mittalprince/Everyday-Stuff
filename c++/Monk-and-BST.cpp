#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<string>

using namespace std;

struct node{
    long long data;
    node *left = nullptr, *right =nullptr;
};

node* newNode(long long key){
    node *temp =new node;
    temp->data = key;
    
    return temp;
}

unordered_map<long long, string > m;

node* sortedarray(vector<long long > arr, long long start, long long end, string str, vector<long long>& v){
    
    if(start > end)
        return nullptr;
    
    long long mid = (start+end)/2;
    
    node *root = newNode(arr[mid]);
    if(m.find(arr[mid]) == m.end()){
        if(str == "")
            m[arr[mid]] = "root";
        else m[arr[mid]] = str;
    }
    
    v.push_back(arr[mid]);
    
    root->left = sortedarray(arr, start, mid-1, str+'l', v);
    root->right = sortedarray(arr, mid+1, end, str+'r', v);
    
    return root;
}


long long find_a(long long s, long long n){
    
    return (((2*s)-(n*n*2))/(n+1));
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long l,s,n,temp,q,type,index,val,N;
    cin>>l>>s;

    n = pow(2, l-1) - 1;
    temp = find_a(s, n);
    
    temp = (temp & 1)? temp+1:temp+2;
    
    temp = temp>>1;
    N= pow(2,l)-1;
    vector<long long> arr(2*n+1);
    
    for(long long i=0;i<2*n; i=i+2){
        arr[i]=temp;
        arr[i+1]=temp;
        temp++;
    }
    arr[N-1]=temp;
    
    string str = "";
    vector<long long> v;
    node *root = sortedarray(arr, 0, arr.size()-1, str, v);

    for(auto& y:v)
    {
        cout<<y<<" ";
    }
    cout<<endl;
    
    cin>>q;
    while(q--){
        cin>>type;
        if(type==0){
            cin>>val;
            cout<<m[val]<<endl;
        }
        else if(type==1){
            cin>>index;
            cout<<v.at(index-1)<<endl;
        }
    }
    
    return 0;
}