/* Problem statement link https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-queries-45/ */

    #include<iostream>
    #include<unordered_map>
    #include<queue>
    #include<climits>
    #include<vector>
    #include<cstring>
    #include<utility>
     
    using namespace std;
     
    // #define ll long long;
    // #define IM INT_MIN;
    // #define im INT_MAX;
     
    long long arr[2000006];
     
    struct nayinode{
        long long sum=0;
        vector<long long> v;
    };
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long n,Q,qq,index,Level,val,l,r;
        
        cin>>n>>Q;
        memset(arr,0,n);
        
        queue< pair<long long, long long > > q;
        unordered_map< long long, nayinode > m;
        for(long long i=0; i<n; i++)
            cin>>arr[i];
        
        q.push(make_pair(0, arr[0]));
        q.push(make_pair(INT_MIN, INT_MIN));
        
        long long last_pop = INT_MAX, level=1;
        
        while(!q.empty()){
            
            auto front = q.front();
            q.pop();
            
            if(last_pop == front.first)
                break;
            
            else{
                if(front.first != INT_MIN){
                    long long index1 = 2*(front.first)+1;
                    long long index2 = 2*(front.first)+2;
                    
                    if(index1<n){
                        q.push(make_pair(index1, arr[index1]));
                    }
                    
                    if(index2<n){
                        q.push(make_pair(index2, arr[index2]));
                    }
     
                    m[level].v.push_back(front.second);
                    m[level].sum+= front.second;
                }
                
                else {
                    q.push(make_pair(INT_MIN, INT_MIN));
                    level++;
                }
                
                last_pop = front.first;
            }    
        }
        
        while(Q--){
            cin>>qq;
            
            if(qq==1){
                cin>>index>>Level;
                
                cout<<m[Level].v.at(index-1)<<endl;
            }
            else if(qq==2){
                cin>>l>>r;
                
                long long Sum=0;
                for(long long i=l; i<=r; i++)
                    Sum+= m[i].sum;
                
                cout<<Sum<<endl;
            }
            
            else if(qq==3){
                cin>>index>>Level>>val;
                long long Sum = 0;
                
                long long it = m[Level].v.at(index-1);
                m[Level].v.at(index-1) = val;
                
                m[Level].sum += (val-it);
            }
        }
        
        return 0;
        
    }
