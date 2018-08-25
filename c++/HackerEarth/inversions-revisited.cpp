    /* Problem statement link https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/inversions-revisited/  */

    #include<iostream>
    #include<vector>
    #include<climits>
    #include<cstring>
     
    using namespace std;
     
    long long a[200005], b[200005];
     
    long long getSum(vector<long long>& BIT, long long index){
        long long sum = 0;
     
        while(index>0){
            sum+= BIT[index];
     
            index -= (index & (-index));
        }
     
        return sum;
    }
     
    void updateBIT(vector<long long>& BIT, long long n, long long index, long long val){
     
        while(index <= n){
     
            BIT[index]+= val;
     
            index += (index & (-index));
        }
    }
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        long long n,i,max=LONG_LONG_MIN,count=0;
        cin>>n;
     
        memset(a,0,n);
        memset(b,0,n);
        
        for(i=0;i<n;i++) {
            cin>>a[i];
            if(max<a[i])
                max = a[i];
        }
            
        for(i=0;i<n;i++){
            cin>>b[i];
            if(max<b[i])
                max = b[i];
        }
        
        vector<long long> BIT(max+1,0);
        for(i=n-2;i>=0;i--){
            
            updateBIT(BIT, max, b[i+1],1);
            count+= getSum(BIT, a[i]-1);
        }
        
        cout<<count<<endl;
        return 0;
    }