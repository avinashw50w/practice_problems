/*Alien tech company G has a very old file transfer tool that is still in use today. While the tool is running, it reassures users by giving status updates on both the percentage of files transferred so far and the number of files transferred so far. The status updates during the process might look like this:

 20% |==>-------|     1 files transferred
100% |==========|     5 files transferred
But the percentage isn't precise; it is simply truncated before the decimal point (i.e. floored to the next lowest or equal 1%). That is, both 1.2% and 1.7% would be displayed as 1%.

Some users may want to know the exact total number of files, so you want to modify the tool so that the status updates look like this:

 20% |==>-------|     1 out of 5 files transferred
100% |==========|     5 out of 5 files transferred
But you've realized that it may or may not be possible to know the number of files. Given the status updates that the tool displays, either figure out how many files there are, or determine that it can't be done (i.e., there are multiple possible values for the number of files). The status updates are not guaranteed to occur at regular intervals and are not guaranteed to occur whenever a file is transferred.

Input

The first line contains T, the number of test cases. T test cases follow. Each test case consists of one line with an integer N, the number of status updates output by the tool, followed by N lines with the format Pi Ki, where Pi and Ki are integers representing the percentage and number of files transferred at some point in the process. The updates are given listed in chronological order -- that is, both the Pi values and the Ki values are nondecreasing throughout a test case.

Output

For each case, output a line starts with "Case #x: y", where x is the number of the case (starting from 1), and y is either the total number of files, or -1 if that number is ambiguous.

Limits

1 ≤ T ≤ 50.
1 ≤ N ≤ 100.
0 ≤ Pi ≤ 100
Small dataset

0 ≤ Ki ≤ 2000
The answer is guaranteed not to exceed 2000.

Large dataset

0 ≤ Ki ≤ 1015
The answer is guaranteed not to exceed 1015.

Sample


Input 
 	
Output 
 
3
2
20 1
100 5
10
25 241
27 262
43 407
44 413
57 536
64 601
67 637
84 789
95 893
96 903
10
0 0
8 2
8 2
17 4
30 7
39 9
69 16
73 17
82 19
91 21
Case #1: 5
Case #2: -1
Case #3: 23
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1000000000000000LL + 10;
ll lb(ll p, ll k, ll n = inf) {
	ll cur = max(k, 1LL);
	while(n > 0) {
		ll step = n / 2;
		ll t = cur + step;
		if(100 * k / t > p) {
			cur = ++t;
			n -= step + 1;
		}
		else n = step;
	}
	return cur;
}

ll ub(ll p, ll k, ll n = inf) {
	ll cur = max(k, 1LL);
	while(n > 0) {
		ll step = n / 2;
		ll t = cur + step;
		if(!(p > 100 * k / t)) {
			cur = ++t;
			n -= step + 1;
		}
		else n = step;
	}
	return cur;
}

int main() {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; ++kase) {
		int n;
		cin >> n;
		vector<ll> p(n), k(n);
		ll l = 1, r = inf;
		for(int i = 0; i < n; ++i) {
			cin >> p[i] >> k[i];
			l = max(l, lb(p[i], k[i]));
			r = min(r, ub(p[i], k[i]) - 1);
		}
		printf("Case #%d: ", kase);
		if(l == r) printf("%lld\n", l);
		else puts("-1");
	}
	return 0;
}