   /* Problem statement https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/easy-one-8/  */

    #include<iostream>
    #include<map>
    
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long int t;
        cin>>t;
        
        while(t--)
        {
            long long int n,x,i;
            cin>>n>>x;
            
            map<long long int,long long int> m;
            long long int arr[n];
            
            for(i=0;i<n;i++)
            {
                cin>>arr[i];
            
            }
 
            for(i=0;i<n;i++)
            m[arr[i]]++;
          
            while(x--)
            {
                long long int y;
                cin>>y;
                
                if(m.find(y)==m.end())
                cout<<"0\n";
                else
                cout<<m[y]<<"\n";
              
            }
           
        }    
        return 0;
    }