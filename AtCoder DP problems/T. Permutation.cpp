#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 3002;
// dp[len][j] - the no of permutations such that the prefix length is 'len' and the last digit is j
int dp[maxn][maxn]; 

void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; string s;
    cin >> n >> s;

    dp[1][1] = 1;
    for (int len = 2; len <= n; ++len) {
        // calculate prefix sum of dp[len-1]
        vector<int> prefix(len);
        for (int i = 1; i <= len-1; ++i)
            prefix[i] = (prefix[i-1] + dp[len-1][i]) % mod;

        for (int b = 1; b <= len; ++b) {
            int L, R;
            if (s[len-2] == '<') L = 1, R = b-1;
            else L = b, R = len-1;

            if (L <= R) {
                add_self(dp[len][b], (prefix[R] - prefix[L-1] + mod) % mod);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        add_self(ans, dp[n][i]);
    }

    cout << ans << endl;
}