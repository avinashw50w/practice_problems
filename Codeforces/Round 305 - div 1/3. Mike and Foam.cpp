/*Mike is a bartender at Rico's bar. At Rico's, they put beer glasses in a special shelf. 
There are n kinds of beer at Rico's numbered from 1 to n. i-th kind of beer has ai milliliters of foam on it.


Maxim is Mike's boss. Today he told Mike to perform q queries. Initially the shelf is empty. 
In each request, Maxim gives him a number x. If beer number x is already in the shelf, 
then Mike should remove it from the shelf, otherwise he should put it in the shelf.

After each query, Mike should tell him the score of the shelf. Bears are geeks. 
So they think that the score of a shelf is the number of pairs (i, j) of glasses in the shelf 
such that i < j and  where  is the greatest common divisor of numbers a and b.

Mike is tired. So he asked you to help him in performing these requests.

Input
The first line of input contains numbers n and q (1 ≤ n, q ≤ 2 × 105), the number of 
different kinds of beer and number of queries.

The next line contains n space separated integers, a1, a2, ... , an (1 ≤ ai ≤ 5 × 105), 
the height of foam in top of each kind of beer.

The next q lines contain the queries. Each query consists of a single integer integer x (1 ≤ x ≤ n), 
the index of a beer that should be added or removed from the shelf.

Output
For each query, print the answer for that query in one line.

Examples
inputCopy
5 6
1 2 3 4 6
1
2
3
4
5
1
output
0
1
3
5
6
2*/
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define M 500001
using namespace std;

int a[M],in[M],c[M],m[M],n,q,x,d;
vector<int> v[M];
long long r;

int main(){
	m[1]=1;
	for(int i=1;i<M;i++)
		for(int j=i;j<M;j+=i){
			v[j].push_back(i);
			if(i<j)
				m[j]-=m[i];
		}

	cin>>n>>q;
	rep(k,n) cin>>a[k];
	
	rep(i,q) {
		cin>>x;
		x--;
		for(int d:v[a[x]]) {
			c[d]-=in[x];
			r+=(in[x]?-1:1)*m[d]*c[d];
			c[d]+=!in[x];
		}

		in[x]^=1;
		cout<<r<<'\n';
	}
	return 0;
}

//////////////////////////////////////////////////////

#include <cstdio>

const int MAXN = 2E5 + 100, MAXM = 5E5 + 100;

int a[MAXN];
bool in[MAXN];

int len, fac[20];
int cnt[MAXM];

int DFS(int depth, int num, bool flag, int c){
	if (depth == len){
		cnt[num] += c;
		return flag ? cnt[num] : -cnt[num];
	}

	return DFS(depth + 1, num, flag, c) + DFS(depth + 1, num * fac[depth], flag ^ 1, c);
}

int main(){
	int n, Q;
	scanf("%d%d", &n, &Q);
	for (int i=1;i<=n;++i)
		scanf("%d", &a[i]);

	long long sum = 0;
	while (Q--){
		int s, t;
		scanf("%d", &s);
		t = a[s];

		len = 0;
		for (int i = 2; i * i <= t; ++i)
			if (t % i == 0)
				for (fac[len++] = i; t % i == 0; t /= i);
		if (t != 1)
			fac[len++] = t;

		if (in[s])
			sum -= DFS(0, 1, true, -1);
		else
			sum += DFS(0, 1, true, 1) - !len;
		in[s] = !in[s];

		printf("%I64d\n", sum);
	}
	return 0;
}

//////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 500005;
vector<int> p[MAX];
int cnt[MAX], mul[MAX], a[MAX], has[MAX];
long long ans;
void add(int val, int sign)
{
	for (int mask = 0; mask < (1 << p[val].size()); mask++)
	{
		if (!mask)
			mul[mask] = 1;
		else
			mul[mask] = mul[mask & (mask - 1)] * p[val][__builtin_ctz(mask)];
		if (sign < 0)
			cnt[mul[mask]]--;
		if (__builtin_popcount(mask) & 1)
			ans -= cnt[mul[mask]] * sign;
		else
			ans += cnt[mul[mask]] * sign;
		if (sign > 0)
			cnt[mul[mask]]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 2; i < MAX; i++)
		if (p[i].empty())
			for (int j = i; j < MAX; j += i)
				p[j].push_back(i);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		has[i] = 1;
	}
	while (q--)
	{
		int x;
		cin >> x;
		x--;
		add(a[x], has[x]);
		has[x] *= -1;
		cout << ans << '\n';
	}
	return 0;
}
