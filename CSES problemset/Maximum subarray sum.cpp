/*Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅105
−109≤xi≤109
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	int n;
	cin >> n;
	ll ans = -1e18, sum = -1e18;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		sum = max(sum + a, (ll)a);
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}

