#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n; cin >> n;

    int matching[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matching[i][j];

    int sz = (1 << n);
    vector<ll> dp(sz);

    dp[0] = 1;

    for (int mask = 0; mask < sz; ++mask) {
        int a = __builtin_popcount(mask);
        for (int b = 0; b < n; ++b) {
            if (matching[a][b] and !(mask & (1 << b))) {
                int new_mask = mask | (1 << b);
                dp[new_mask] += dp[mask];
                if (dp[new_mask] >= mod) dp[new_mask] -= mod;
            }
        }
    }

    cout << dp[sz-1] << "\n";
}