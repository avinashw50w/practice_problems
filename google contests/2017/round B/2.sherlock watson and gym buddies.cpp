/*Watson and Sherlock are gym buddies.

Their gym trainer has given them three numbers, A, B, and N, and has asked Watson and Sherlock to pick two different positive integers i and j, where i and j are 
both less than or equal to N. Watson is expected to eat exactly iA sprouts every day, and Sherlock is expected to eat exactly jB sprouts every day.

Watson and Sherlock have noticed that if the total number of sprouts eaten by them on a given day is divisible by a certain integer K, then they get along well 
that day.

So, Watson and Sherlock need your help to determine how many such pairs of (i, j) exist, where i != j. As the number of pairs can be really high, please output 
it modulo 109+7 (1000000007).
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with 4 integers A, B, N and K, as 
described above.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the required answer.

Limits

1 ≤ T ≤ 100.
0 ≤ A ≤ 106.
0 ≤ B ≤ 106.
Small dataset

1 ≤ K ≤ 10000.
1 ≤ N ≤ 1000.
Large dataset

1 ≤ K ≤ 100000.
1 ≤ N ≤ 1018.
Sample


Input 
 	
Output 
 
3
1 1 5 3
1 2 4 5
1 1 2 2

Case #1: 8
Case #2: 3
Case #3: 0

In Case 1, the possible pairs are (1, 2), (1, 5), (2, 1), (2, 4), (4, 2), (4, 5), (5, 1), and (5, 4).
In Case 2, the possible pairs are (1, 2), (1, 3), and (4, 1).
In Case 3, No possible pairs are there, as i != j.*/

#include <bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 100010
#define MOD 1000000007

ll cnt[N];
vector<int> v[N];
ll mod;

ll pow1(ll a,ll b)
{
	if(b==0)	return 1%mod;
	ll ret=pow1(a,b/2);
	ret=(ret*ret)%mod;
	if(b&1)	ret=(a*ret)%mod;
	return ret;
}
int main()
{
	// freopen("B1.in","r",stdin);
	// freopen("B1.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;++tt)
	{
		ll a,b,n,k,i,j;
		sl(a);sl(b);sl(n);sl(k);
		clr(cnt);
		for(i=0;i<k;++i)
			v[i].clear();
		mod=k;
		for(i=0;i<k;++i)
			cnt[i]=n/k;
		ll low=k*(n/k);
		for(i=low+1;i<=n;++i)
			cnt[i%k]++;
		for(i=0;i<k;++i)
			cnt[i]%=MOD;
		for(i=0;i<k;++i)
			v[pow1(i,b)].PB(i);
		ll ans=0;
		for(i=0;i<k;++i)
		{
			int Left=(k-pow1(i,a))%k;
			for(j=0;j<v[Left].size();++j)
			{
				if(v[Left][j]!=i)
					ans=(ans+cnt[i]*cnt[v[Left][j]]%MOD)%MOD;
				else
					ans=(ans+cnt[i]*(cnt[i]-1+MOD)%MOD)%MOD;
			}
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
}
//////////////////////////////////////////////////////////////////////////

ll power(ll x,ll y,ll mod){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t%mod;
}

ll cta[N],cot[N];
ll ctb[N],rv[N];
int main(){
	int q; scanf("%d",&q);
	REP(aa,q){
		ll a,b,n,k;
		scanf("%lld%lld%lld%lld",&a,&b,&n,&k);
	//	a=b=1000000,n=INF,k=100000;
		REP(i,k) rv[i]=0;
		REP(i,k){
			cot[i]=(n/k+(n%k>=i))%mod;
			if(i==0) cot[i]--;
			cta[i]=power(i,a,k);
			ctb[i]=power(i,b,k);
			rv[ctb[i]]=(rv[ctb[i]]+cot[i])%mod;
		}
		ll sum=0;
		REP(i,k){
			sum=(sum+cot[i]*rv[(k-cta[i])%k]%mod)%mod;
			if((cta[i]+ctb[i])%k==0){
				sum=(sum-cot[i])%mod;
			}
		}
		sum=(sum%mod+mod)%mod;
		printf("Case #%d: %lld\n",aa+1,sum);
	}
	return 0;
}