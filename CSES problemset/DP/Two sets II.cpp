/*Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}
Input

The only input line contains an integer n.

Output

Print the answer modulo 109+7.

Constraints
1≤n≤500
Example

Input:
7

Output:
4*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e2, M = 1e9 + 7;
ll dp[maxn * (maxn + 1) / 2 + 1];

int main() {

    int n; cin >> n;
    int s = (n * (n + 1)) / 2;
    if (s & 1) {
        cout << 0;
        return 0;
    }

    s /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i * (i + 1) / 2; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % M;
        }
    }
    // ans = dp[s]/2, since we are taking module M so we need to multiply dp[s]
    // by modulo multiplicative inverse of 2 which is (M+1)/2,
    // coz (2 * (M+1)/2) % M = 1
    cout << dp[s] * ((M + 1) / 2) % M;
}