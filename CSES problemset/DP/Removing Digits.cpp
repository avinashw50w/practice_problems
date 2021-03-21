/*You are given an integer n. On each step, you may substract from it any one-digit number that appears in it.

How many steps are required to make the number equal to 0?

Input

The only input line has an integer n.

Output

Print one integer: the minimum number of steps.

Constraints
1≤n≤106
Example

Input:
27

Output:
5

Explanation: An optimal solution is 27→20→18→10→9→0.
*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, mod);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int t = i;
        while (t) {
            int digit = t % 10;
            t /= 10;
            dp[i] = min(dp[i], dp[i-digit] + 1);
        }
    }

    cout << dp[n] << "\n";
}

/////////////////////////////////////////////////////////////////
// another simple solution
int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, mod);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (char c: to_string(i)) {
            dp[i] = min(dp[i], dp[i-(c-'0')] + 1)
        }
    }

    cout << dp[n] << "\n";
}