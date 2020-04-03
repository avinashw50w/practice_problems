/*Little Elephant from Zoo of Lviv likes to paint.

He has n objects to paint, ordered in a row and numbered form left to right starting from 1. There are totally c colors, 
numbered from 0 to c-1. At the beggining all objects are colored in color with number 1. 
When object with color a is painted in color b, the resulting color will have number (a*b) mod c.

Little Elephant is going to make k turns. At i-th (0-based numeration) turn he will randomly choose 
any subset (even empty) of objects with indices in range [Li; Ri] (inclusive) and paint all objects in 
chosen subset with random color (the same for all objects in the subset).

Little Elephant wants to know the expected sum of all colors over all n objects after making all k turns. Help him.

Input
First line contain single integer T - the number of test cases. T test cases follow. First line of each 
test case contains three integers n, c and k. Next k lines of each test case contain 
k pairs of integers Li and Ri, one pair per line.

Output
In T lines print T real numbers - the answers for the corresponding test cases.

Any results within 10^-6 absolute error will be accepted.

Constraints
1 <= T <= 10

1 <= n, k <= 50

2 <= c <= 100

1 <= Li <= Ri <= n

Example
Input:
2
4 3 4
1 2
2 4
3 3
1 4
7 10 7
7 7
3 4
1 2
5 5
4 5
2 7
3 3

Output:
3.444444444
22.943125000*/

#include <bits/stdc++.h>
using namespace std;

int N, C, K;
int cnt[51];
bool vis[51][101];
double dp[51][101];

double solve(int n, int c) {
    if(n == 0) return c;

    if(vis[n][c])
        return dp[n][c];

    vis[n][c] = true;
    double &ret = dp[n][c];

    double p = 1.0/C;
    // if this ball is not choosen 
    ret = 0.5 * solve(n-1, c);

    // if this ball is choosen for coloring
    // then there are C number of colors with which it can be colored
    for(int i = 0; i < C; ++i)
        ret += 0.5 * p * solve(n-1, (c*i)%C);

    return ret;
}

int main() {
    int T; scanf("%d", &T);

    while(T--) {

        memset(vis, false, sizeof(vis));
        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        scanf("%d %d %d", &N, &C, &K);

        for(int i = 0; i < K; ++i) {
            int l, r;
            cin >> l >> r;
            for(int j = l; j <= r; ++j)
                cnt[j]++;
        }

        double ans = 0;
        for(int i = 1; i <= N; ++i)
            ans += solve(cnt[i], 1);

        printf("%.9f\n", ans);
    }
}

//////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

double dp[51][51][101]; // dp[k][n][c]
int n, c, k;

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> c >> k;

	for(int i = 0; i < n; ++i)
		dp[0][i][1] = 1;

	for(int i = 0; i < k; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;

		for(int j = 0; j < n; ++j) 
		{
			for(int x = 0; x < c; ++x) 
			{

				if(dp[i][j][x] < 1e-12)
					continue;
				if(l <= j and j <= r) 
				{
					// if the jth ball is not colored
					dp[i+1][j][x] += dp[i][j][x] * 0.5;

					// if the jth ball is colored
					double p = 0.5/c;

					for(int y = 0; y < c; ++y)
						dp[i+1][j][(x*y)%c] += dp[i][j][x] * p;
				}
				else 
				{
					dp[i+1][j][x] += dp[i][j][x];
				}
			}
		}
	}

	double ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < c; ++j)
			ans += dp[k][i][j] * j;

	cout << ans << endl;
}
int main() {
	int t;

	cin >> t;
	while(t--) {

		solve();
	}

}