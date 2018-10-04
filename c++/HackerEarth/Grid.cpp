/* 
Problem statement link https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/
*/

#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct cell
{
  bool visited  =false,occupied = false;
};

ll dist[1005][1005] ;


cell edge [1005][1005];

void BFS(ll u, ll v, ll n, ll m)
{
    queue < pair < ll, ll > > q;
    q.push({--u,--v});
    
    edge[u][v].visited = true;
    
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        
        ll i = temp.first,j = temp.second;
        
       
        if((i+1) < n && j< m && !edge[i+1][j].visited)
        {
            dist [i+1][j] = dist[i][j] + 1;
            edge[i+1][j].visited = true;
            q.push({i+1,j});
        }
        
        
        if(j<m && !edge[i-1][j].visited && (i-1) >= 0)
        {
            dist[i-1][j] = dist[i][j] + 1;
            edge[i-1][j].visited = true;
            q.push({i-1,j});
        }
        if(i<n && j+1 < m && !edge[i][j+1].visited)
        {
            dist[i][j+1] = dist[i][j] + 1;
            edge[i][j+1].visited = true;
            q.push({i,j+1});
        }
        if(i < n && !edge[i][j-1].visited && (j-1) >= 0)
        {
            dist[i][j-1] = dist[i][j] + 1;
            edge[i][j-1].visited = true;
            q.push({i,j-1});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,q;
    cin>>n>>m>>q;
    
    memset(dist,-1,1005*1005*sizeof(ll));
    
    for(ll i=0;i<n;i++)
    {
        string str;
        cin>>str;
        
        for(ll j =0;j < str.length();j++)
        {
            if(str[j] == '*')
            {
                edge[i][j].occupied = true;
                edge[i][j].visited = true;
            }
        }
    }
    ll u,v;
    
    cin>>u>>v;
    
    dist[u-1][v-1] = 0;
    
    BFS(u,v,n,m);
    
    ll x,y;
    
    while(q--)
    {
        cin>>x>>y;
        
        --x;
        --y;
        
        cout<<dist[x][y]<<endl;
        
    }
    return 0;
}