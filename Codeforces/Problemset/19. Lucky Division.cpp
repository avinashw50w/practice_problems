/*outputstandard output
Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal 
representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky 
and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. 
Help him find out if the given number n is almost lucky.

Input
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output
In the only line print "YES" (without the quotes), if number n is almost lucky. 
Otherwise, print "NO" (without the quotes).

Examples
inputCopy
47
outputCopy
YES*/

#include <iostream>
using namespace std;

int main() {
	int a[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
	int n; cin >> n; int l = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < l; ++i) {
		if (a[i] <= n and (n%a[i]) == 0) {cout << "YES\n"; return 0; } 
	}
	cout << "NO\n";
}