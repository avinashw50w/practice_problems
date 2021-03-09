/*There are n apples with known weights. Your task is to divide the apples into two groups so
that the difference between the weights of the groups is minimal.

Input

The first input line has an integer n: the number of apples.

The next line has n integers p1,p2,…,pn: the weight of each apple.

Output

Print one integer: the minimum difference between the weights of the groups.

Constraints
1≤n≤20
1≤pi≤109
Example

Input:
5
3 2 7 4 1

Output:
1*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	ll total = 0, ans = 1e18;
	for (int &e : a) cin >> e, total += e;

	for (int i = 0; i < 1 << n; ++i) {
		ll sum = 0;
		for (int j = 0; j < n; ++j) if (i >> j & 1) sum += a[j];
		ans = min(ans, abs(total - 2 * sum));
	}

	cout << ans << "\n";
}