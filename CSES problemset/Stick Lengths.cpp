/*There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

What is the minimum total cost?

Input

The first input line contains an integer n: the number of sticks.

Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

Output

Print one integer: the minimum total cost.

Constraints
1≤n≤2⋅105
1≤pi≤109
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int p[n];
	for (int i = 0; i < n; ++i) cin >> p[i];
	sort(p, p + n);

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(p[i] - p[n / 2]);
	}
	cout << ans << "\n";
}