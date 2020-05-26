/*There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

What is the maximum number of houses you can buy?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing the two integers N and B. The second line contains N integers. The i-th integer is Ai, the cost of the i-th house.*/

#include <bits/stdc++.h>
using namespace std;

int a[100005];
void solve() {
	int n, b;
	cin >> n >> b;

	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);

	int ans = 0;
	
	for (int i = 0; i < n; ++i)
		if (b >= a[i]) b-=a[i], ans++;

	cout << ans << "\n";
	
}

int main() {

	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ": ";
		solve();
	}
}
