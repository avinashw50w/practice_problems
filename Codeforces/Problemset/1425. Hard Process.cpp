/*You are given an array a with n elements. Each element of a is either 0 or 1.

Let's denote the length of the longest subsegment of consecutive elements in a, consisting of only numbers one, 
as f(a). You can change no more than k zeroes to ones to maximize f(a).

Input
The first line contains two integers n and k (1 ≤ n ≤ 3·105, 0 ≤ k ≤ n) — the number of elements in a 
and the parameter k.

The second line contains n integers ai (0 ≤ ai ≤ 1) — the elements of a.

Output
On the first line print a non-negative integer z — the maximal value of f(a) after no more than k 
changes of zeroes to ones.

On the second line print n integers aj — the elements of the array a after the changes.

If there are multiple answers, you can print any one of them.

Examples
inputCopy
7 1
1 0 0 1 1 0 1
outputCopy
4
1 0 0 1 1 1 1*/

#include <iostream>
using namespace std;

int main() {
	int n, k, i, j, st, en, cnt, ans = 0, a[300000+2];
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0, j = 0, cnt = 0; i <= n; cnt -= !a[i++]) {
		while (cnt <= k and j < n) cnt += !a[j++];
		if (j-i > ans) ans = j-i, st = i, en = j;
	}
	for (int i = 0; i < n; ++i) {
		if (st <= i and i <= en) cout << 1 << " ";
		else cout << a[i] << " ";
	}
}