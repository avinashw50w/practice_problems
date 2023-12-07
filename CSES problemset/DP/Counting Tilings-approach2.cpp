#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, m;
// dp[col][mask] = # of ways to fill board upto column col such that the col has configuration mask,
// where mask represents the rows which are occupied
int dp[1001][1<<10];


void solve(int row, int col, int mask, int next_mask) {
    if (row >= n) {
        dp[col+1][next_mask] = (dp[col+1][next_mask] + dp[col][mask]) % mod;
        return;
    }

    if (mask>>row&1) solve(row+1, col, mask, next_mask);
    else {
        solve(row+1, col, mask, next_mask | (1<<row));
        if (row+1 < n and (mask&(1<<(row+1))) == 0)
            solve(row+2, col, mask, next_mask);
    }
}

int main() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int col = 0; col < m; ++col) {
        for (int mask = 0; mask < (1<<n); ++mask) {
            solve(0, col, mask, 0);
        }
    }

    cout<< dp[m][0];
}
