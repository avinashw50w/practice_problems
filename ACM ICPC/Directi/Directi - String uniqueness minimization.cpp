#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int max_alp = 27;

string str1, str2;

bool flag1[max_alp], flag2[max_alp];

int main()
{
	ll i, j, t, n, m, lim, n1, n2, ans, tempi;

	scanf("%lld", &t);

	while(t--)
	{
		scanf("%lld", &n);
		cin>>str1>>str2;
		ans = n;

		lim = 1LL<<n;

		for(i=0;i<lim;++i)
		{
			memset(flag1, 0, sizeof(flag1));
			memset(flag2, 0, sizeof(flag2));
			tempi=i;
			for(j=0;j<n;++j,tempi/=2LL)
			{
				if(tempi&1LL)
				{
					flag2[str1[j]-'a'] = true;
					flag1[str2[j]-'a'] = true;
				}
				else
				{
					flag1[str1[j]-'a'] = true;
					flag2[str2[j]-'a'] = true;
				}
			}

			n1 = n2 = 0LL;
			for(j=0;j<max_alp;++j)
			{	
				if(flag1[j])
					++n1;
				if(flag2[j])
					++n2;
			}

			ans = min(ans, max(n1, n2));
		}

		printf("%lld\n", ans);
	}

	return 0;
}