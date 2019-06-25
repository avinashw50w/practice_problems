/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 31/01/2016
time  : 11:16:05
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;

double p[100100][2][2][2];
double dp[2][2][2];

void solve(){
	int n, x, K;
	double a, b, c;
	cin >> n >> x >> K;
	cin >> a >> b >> c;
	a *= 0.01;
	b *= 0.01;
	c *= 0.01;
	// p[x][k]
	for(int i = 0; i <= n; ++i) rep(j, 2) rep(jj, 2) rep(ii, 2) p[i][j][jj][ii] = 0;
	p[0][0][0][0] = 1;
	p[0][0][1][0] = 1;
	p[0][1][0][1] = 1;
	p[0][1][1][1] = 1;
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	dp[0][1][0] = a;
	dp[0][1][1] = b+c;
	dp[1][0][0] = a;
	dp[1][0][1] = b+c;
	dp[1][1][0] = c;
	dp[1][1][1] = a+b;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 2; ++j){
			for(int k = 0; k < 2; ++k){
				for(int l = 0; l < 2; ++l) {
					for(int m = 0; m < 2; ++m) {
						p[i][j][k][m] += p[i-1][j][k][l] * dp[l][k][m];
					}
				}
			}
		}
	}
	vector<double> ans(31);
	for(int i = 0; i < 31; ++i) {
		bool j = (x & (1<<i));
		bool k = (K & (1<<i));
		ans[i] = p[n][j][k][1];
	}
	double s = 0;
	for(int i = 0; i < 31; ++i){
		s += ans[i] * pow(2, i);
	}
	printf("%.11lf\n",s);
}

int main()
{
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		printf("Case #%d: ",tc);
		solve();
	}	
	return 0;
}
