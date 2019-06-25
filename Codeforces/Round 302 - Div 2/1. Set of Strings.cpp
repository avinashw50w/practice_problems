/*You are given a string q. A sequence of k strings s1, s2, ..., sk is called beautiful, if the concatenation of these strings 
is string q (formally, s1 + s2 + ... + sk = q) and the first characters of these strings are distinct.

Find any beautiful sequence of strings or determine that the beautiful sequence doesn't exist.

Input
The first line contains a positive integer k (1 ≤ k ≤ 26) — the number of strings that should be in a beautiful sequence.

The second line contains string q, consisting of lowercase Latin letters. 
The length of the string is within range from 1 to 100, inclusive.

Output
If such sequence doesn't exist, then print in a single line "NO" (without the quotes). 
Otherwise, print in the first line "YES" (without the quotes) and in the next k lines 
print the beautiful sequence of strings s1, s2, ..., sk.

If there are multiple possible answers, print any of them.

Examples
inputCopy
1
abca
output
YES
abca
inputCopy
2
aaacas
output
YES
aaa
cas*/

#include <iostream>
using namespace std;

string str, V[26];
int f[256], k, m = -1;

int main() {
	cin >> k >> str;

	for(char c: str)
		V[(!f[c]++ && m+1 < k) ? ++m: m] += c; // if c appears for the first time and m <= k them increment m otherwise do nothing

	if(m == k-1) {
		cout << "YES";
		for(int i = 0; i < m; ++i) cout << "\n" << V[i];
	}
	else cout << "NO";
}

