/*You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers?

Input

The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output

Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅105
1≤a<b≤109*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200002;

int main() {
	int n; cin >> n;
	map<int, int> f;
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		f[s]++;
		f[e + 1]--;
	}

	int ans = 0, s = 0;
	for (auto p : f) {
		s += p.second;
		ans = max(ans, s);
	}

	cout << ans << "\n";
}