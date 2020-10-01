/*Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

Input

The only input line contains an integer n.

Output

Print n integers: the results.

Constraints
1≤n≤10000
Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;
	// total - no of ways to place 2 knights such that they attack each other
	for (int k = 1; k <= n; ++k) {
		ll total = k * k;
		// nC2 - choose two positions out of k*k possible positions
		ll p = total * (total - 1) / 2;
		if (k > 2) p -= 4 * (k - 1) * (k - 2);
		cout << p << "\n";
	}
}