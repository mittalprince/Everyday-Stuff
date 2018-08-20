#include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long n,l,pro=1,j=0,i,m1,m2,m3;
        cin>>n;
        vector<long>vec;
        priority_queue<long>pq;
        for(i=0;i<n;i++)
        {
            cin>>l;
            vec.push_back(l);
            pq.push(l);
            if(i<2)
            cout<<"-1\n";
            else
            {
                m1=pq.top();
                pq.pop();
                m2=pq.top();
                pq.pop();
                m3=pq.top();
                pq.pop();
                cout<<m1*m2*m3<<"\n";
                pq.push(m1);
                pq.push(m2);
                pq.push(m3);
            }
        }
    }