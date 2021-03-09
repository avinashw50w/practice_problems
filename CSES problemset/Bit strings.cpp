/*Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

The only input line has an integer n.

Output

Print the result modulo 109+7.

Constraints
1≤n≤106

just find ( 2^n ) % 10^9 + 7
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
	int res = 1;
	long long a = 2, b;
	cin >> b;
	for (; b; b >>= 1, a = (a * a) % mod) if (b & 1) res = (res * a) % mod;

	cout << res << "\n";
}