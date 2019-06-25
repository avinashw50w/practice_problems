#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int max_n = 5e4 + 10;
ll mod = 1e9 + 7;

struct node
{
	ll val, valup, tot;
}node[max_n];

ll par[max_n];

int main()
{
	ll t, n, m, q, i, j, idx, val;
	string type;

	scanf("%lld", &t);

	while(t--)
	{
		scanf("%lld %lld %lld", &n, &m, &q);
		for(i=1;i<=n;++i)
		{
			scanf("%lld", &par[i]);
			node[i].val = node[i].valup = node[i].tot = 0LL;
		}

		for(i=1;i<=m;++i)
		{
			cin>>type>>idx>>val;
			if(type == "ADD")
			{
				node[idx].val = (node[idx].val +val)%mod;
			}
			else
			{
				node[idx].valup = (node[idx].valup +val)%mod;
			}
		}

		for(i=n;i>0;--i)
		{
			node[i].val = (node[i].val +node[i].valup)%mod;
			node[i].tot = (node[i].tot +node[i].val)%mod;
			node[par[i]].valup = (node[par[i]].valup + node[i].valup)%mod;
			node[par[i]].tot = (node[par[i]].tot +node[i].tot)%mod;
		}

		while(q--)
		{
			cin>>type>>idx;
			if(type == "VAL")
			{
				printf("%lld\n", node[idx].val);
			}
			else
			{
				printf("%lld\n", node[idx].tot);
			}
		}
	}

	return 0;
}
