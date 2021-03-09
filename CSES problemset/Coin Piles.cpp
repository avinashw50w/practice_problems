/*You have two coin piles containing a and b coins. On each move, you can either remove one
coin from the left pile and two coins from the right pile, or two coins from the left pile and
one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

Output

For each test, print "YES" if you can empty the piles and "NO" otherwise.

Constraints
1≤t≤105
0≤a,b≤109
Example

Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES

IDEA: at each operation we reduce the no of coins by 3
so total no of coins should be divisible by 3,
one pile can have atmost twice the no of coins than the other pile
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        string ans = ((a + b) % 3 == 0 and 2 * a >= b and 2 * b >= a) ? "YES\n" : "NO\n";

        cout << ans;
    }
}