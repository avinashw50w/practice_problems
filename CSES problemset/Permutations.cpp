/*A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation exists.

Input

The only input line contains an integer n.

Output

Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example 1

Input:
5

Output:
4 2 5 3 1

Example 2

Input:
3

Output:
NO SOLUTION*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	// 3 1 2
	if (n < 4) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	if (n % 2 == 0) {
		// 2 4 1 3
		for (int i = 2; i <= n; i += 2) cout << i << " ";
		for (int i = 1; i < n; i += 2) cout << i << " ";
	}
	else {
		// 1 3 5 2 4
		for (int i = 1; i <= n; i += 2) cout << i << " ";
		for (int i = 2; i < n; i += 2) cout << i << " ";
	}

	cout << "\n";
}