/*You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2⋅105
1≤x,ai≤109
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (mp.count(x - a)) {
			cout << mp[x - a] + 1 << " " << i + 1 << "\n";
			return 0;
		}
		mp[a] = i;
	}

	cout << "IMPOSSIBLE\n";
}