/*
Problem statement link -->   https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/description/
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

#define siz 100005

vector<p> graph[siz+5];

ll vis[siz+5];
ll n;

void dijikstra(ll dist[],ll src)
{
	memset(vis,0, sizeof(vis));
	
	for(ll i=1; i<=n; i++)
		dist[i]=LONG_LONG_MAX;
	
	priority_queue<p ,vector<p>, greater<p> > q;
	q.push(make_pair(0,src));
	dist[src]=0;
	//vis[src] = 1;
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(vis[x]==1)
			continue;
		vis[x]=1;
		for(ll i=0; i<graph[x].size(); i++)
		{
			if(!vis[graph[x][i].first])
			{
				if(dist[graph[x][i].first]>dist[x]+graph[x][i].second)
				{
					dist[graph[x][i].first]=dist[x]+graph[x][i].second;
					q.push(make_pair(dist[graph[x][i].first],graph[x][i].first));	
				}
			}
		}
	}
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m,k,x,t,u,v,d,A,B;
	cin>>n>>m>>k>>x;
	vector<ll> f;
	for(ll i=0; i<k; i++)
	{
		cin>>t;
		f.push_back(t);
	}
	while(m--)
	{
		cin>>u>>v>>d;
		graph[u].push_back(make_pair(v,d));
		graph[v].push_back(make_pair(u,d));
	}
	cin>>A>>B;
	ll dist1[n+1],dist2[n+1];
	dijikstra(dist1,A);
	dijikstra(dist2,B);
	ll ans=LONG_LONG_MAX;

	if(dist1[B] == LONG_LONG_MAX){
		cout<<"-1"<<endl;
		return 0;
	}
	for(ll i=0; i<k; i++)
	{
		if(dist2[f[i]]<=x)
			ans=min(ans,dist1[f[i]]+dist2[f[i]]);
	}
	if(ans==LONG_LONG_MAX)
		ans=-1;
	cout<<ans<<"\n";

	return 0;
}