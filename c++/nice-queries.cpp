/* https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/mandee-and-his-girlfriend-9a96aabd/ */

#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,q;
	cin >> n >> q;
	map<long long, long long> m;
	while(q--)
	{
	    int type,val;
	    cin >> type >> val;
	    if(type==1)
	    {
	        m[val]++;
	    }
	    else
	    {
	        auto it= m.lower_bound(val);
	        if(it==m.end())
	            cout<<"-1"<<endl;
	        else
	            cout<<it->first<<endl;
	    }
	}
	return 0;
}