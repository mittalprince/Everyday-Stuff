#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> ans;

int f(int x, int n){
    int temp;
    temp = v.at(0);
    int z = temp % x;
    
    for(int i=1; i<n; i++){
        temp = v[i];
        if(z!= temp%x)
            return 0;
    }
    
    return 1;
}

int gcd(int A, int B) {
    if(B==0)
        return A;
    else
        return gcd(B, A % B);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,temp,diff=INT_MAX,t;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    for(int i=1; i<n; i++){
        temp = v[i] - v[i-1];
        if(temp<diff)
            diff = temp;
    }
    
    for(int i=1; i<=sqrt(diff); i++){
        // if(gcd(i,diff) == 1)
        //     continue;
        
        // if(f(i,n))
        //     ans.push_back(i);
        
        if(diff%i != 0) continue;
        int a1 = i, a2= diff/i;
        if(f(a1, n) && a1!=1)
            ans.push_back(a1);
        if(f(a2,n) && a2!= a1)
            ans.push_back(a2);
        
    }
    sort(ans.begin(), ans.end());
    for(auto &y: ans)
        cout<<y<<" ";
        
    return 0;
}