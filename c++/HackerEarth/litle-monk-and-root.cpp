#include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        priority_queue<int> heap;
        int n,k;
        cin>>n>>k;
        assert(n>0 and n<=1e5);
        assert(k>0 and k<=1e5);
        assert(n>=k);
        double ans = 0;
        for(int i=0;i<n;i++){
            double x;
            cin>>x;
            assert(x>0 and x<=1e9);
            ans+=x;
            heap.push(x);
        }
        cout<<fixed<<setprecision(6)<<ans/n<<" ";
        while(k--){
            double x = heap.top();
            heap.pop();
            x=ceil(x/3);
            heap.push(x);
        }
        ans=0;
        while(!heap.empty()){
            double x = (double)heap.top();
            heap.pop();
            ans+=x;
        }
        cout<<fixed<<setprecision(6)<<ans/n<<endl;
        return 0;
    }
 