/*You have a square N by N matrix M of nonnegative integers. We would like to make a list of the maximum values in every sub-matrix of size K by K within M, and then find the sum of those values together. (Note that the same entry of M might be the maximum value in more than one sub-matrix, in which case it will show up multiple times in the list.) Can you find that sum?

To simplify the input of the matrix, you are given two arrays A and B of length N, and two integers C and X. Then the entry Mij (for the ith row and jth column of the matrix) equals (Ai*i+Bj*j + C) mod X, where i and j are in the range [1, N].

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with one line with four integers, N, K, C and X. Then there are two lines with N integers each, representing the arrays A and B.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the sum of the maximum values in all sub-matrices of size K by K.

Limits

1 ≤ T ≤ 100.
1 ≤ Ai, Bi ≤ 100000.
1 ≤ C ≤ 100000.
1 ≤ X ≤ 1000000007.
1 ≤ K ≤ N. 
Small dataset

1 ≤ N ≤ 50.
Large dataset

1 ≤ N ≤ 3000.
Sample


Input 
 	
Output 
 
3
1 1 1 5
1
1
2 1 5 11
1 2
3 4
3 2 3 109
6 4 3
2 1 5

Case #1: 3
Case #2: 19
Case #3: 80
In the first test case, the matrix is:
3
So the sum of maximum values is 3.

In the second test case, the matrix is:
9 3
1 6
So the sum of maximum values is 19.

In the third test case, the matrix is:
11 11 24
13 13 26
14 14 27
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct zkw2d {
	int n, m; 
	int ma[10000][10000];
	void init(int t) {
		for(n = 1; n <= t; n += n) ;
		m = n;
	}
	void _update(int o, int y, int v, int flag) {
		y += m;
		if(flag) { ma[o][y] = v; y>>=1; }
		for(; y; y >>= 1) {
			if(flag) {
				ma[o][y] = max(ma[o][y<<1], ma[o][y<<1|1]);
			} else {
				ma[o][y] = max(ma[o<<1][y], ma[o<<1|1][y]);
			}
		}
	}
	void update(int x, int y, int v) {
		int flag = 1;
		for(x += n; x; x >>= 1, flag = 0) {
			_update(x, y, v, flag);
		}
	}
	int Max;
	void _query(int o, int y1, int y2) {
		for(y1 = y1 + m - 1, y2 = y2 + m + 1; y1 ^ y2 ^ 1; y1 >>= 1, y2 >>= 1) {
			if(~y1&1) { Max = max(Max, ma[o][y1^1]); }
			if( y2&1) { Max = max(Max, ma[o][y2^1]); }
		}
	}
	void query(int x1, int y1, int x2, int y2) {
		 Max = 0;
		for(x1 = x1 + n - 1, x2 = x2 + n + 1; x1 ^ x2 ^ 1; x1 >>= 1, x2 >>= 1) {
			if(~x1&1) _query(x1^1, y1, y2);
			if( x2&1) _query(x2^1, y1, y2);
		}
	}
} tree;
int main() {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		ll n, k, c, x;
		static ll a[3010], b[3010];
		scanf("%lld%lld%lld%lld", &n, &k, &c, &x);
		tree.init(n);
		for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		for(int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
			tree.update(i, j, (a[i] * i + b[j] * j + c) % x);
		}
		ll ans = 0;
		for(int i = k; i <= n; ++i) for(int j = k; j <= n; ++j) {
			tree.query(i - k + 1, j - k + 1, i, j);
			ans += tree.Max;
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}