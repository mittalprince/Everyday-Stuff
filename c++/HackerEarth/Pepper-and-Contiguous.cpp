/* Problem statment link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pepper-and-contiguous-even-subarray-9f3adf65/ */    

    #include<iostream>
     
    using namespace std;
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long T,N,n,count,max;
        cin>>T;
        while(T--){
            
            cin>>N;
            count = 0;
            max = 0;
            
            while(N--){
                
                cin>>n;
                if(n%2 == 0){
                    count++;
                    if(max < count)
                        max = count;
                }
                else count = 0;
            }
            
            if(max)
                cout<<max<<endl;
            else cout<<"-1"<<endl;
        }
        
        return 0;
    }