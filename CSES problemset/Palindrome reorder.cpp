/*Given a string, your task is to reorder its letters in such a way that it becomes a
palindrome (i.e., it reads the same forwards and backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example

Input:
AAAACACBA

Output:
AACABACAA*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int odd = 0;
	vector<int> f(26, 0);
	for (char c : s) f[c - 'A']++;
	for (int e : f) if (e & 1) odd++;
	if (odd > 1) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	string t = "";

	for (int i = 0; i < 26; ++i) {
		if (f[i] & 1 ^ 1) t += string(f[i] / 2, i + 'A');
	}
	cout << t;
	for (int i = 0; i < 26; ++i) {
		if (f[i] & 1) cout << string(f[i], i + 'A');
	}
	reverse(t.begin(), t.end());
	cout << t;
	cout << "\n";
}