/* Problem statement link  https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/  */

#include<iostream>
#include<cstring>

using namespace std;

long long arr[1000005], q[1000005], s[1000005];

bool is_prime(long long n){

    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (long long i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n,no,j=0,k=0;
    
    cin>>n;
    
    memset(arr,0,n);
    memset(q,0,n);
    memset(s,0,n);
    
    while(n--){
        cin>>no;
        
        if(is_prime(no)){
            q[j] = no;
            j++;
        }
        
        else{
            s[k] = no;
            k++;
        }
    }
    
    for(long long i=0;i<j;i++)
        cout<<q[i]<<" ";
        
    cout<<endl;
    
    for(long long i=k-1;i>=0;i--)
        cout<<s[i]<<" ";
        
    return 0;
}