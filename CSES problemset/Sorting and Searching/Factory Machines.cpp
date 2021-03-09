/*A factory has n machines which can be used to make products. Your goal is to make a total of t products.

For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.

What is the shortest time needed to make t products?

Input

The first input line has two integers n and t: the number of machines and products.

The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.

Output

Print one integer: the minimum time needed to make t products.

Constraints
1≤n≤2⋅105
1≤t≤109
1≤ki≤109
Example

Input:
3 7
3 2 5

Output:
8*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

int a[maxn];

int main() {

	int n, t; cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll l = 1, r = 1e18;

	while (l < r) {
		ll mid = (l + r) / 2;
		ll p = 0;
		for (int i = 0; i < n; ++i) {
			p += min(mid / a[i], (ll) 1e9);
		}

		if (p >= t) r = mid;
		else l = mid + 1;
	}

	cout << l << "\n";
}