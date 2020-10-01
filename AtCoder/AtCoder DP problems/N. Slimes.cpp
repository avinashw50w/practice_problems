#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 400 + 5;
const ll INF = 1e18L;
ll dp[maxn][maxn];
ll prefix_sum[maxn];

void min_self(ll &a, ll b) {
    a = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> slimes(n);
    for (int &x: slimes) cin >> x;

    fill(&dp[0][0], &dp[n][0], INF);
    for (int i = 0; i < n; ++i) {
        
        dp[i][i] = 0LL;
        prefix_sum[i] += i > 0 ? prefix_sum[i-1] + slimes[i] : slimes[i];
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n-len; ++i) {
            int j = i + len - 1;
            ll sum = prefix_sum[j] - (i > 0 ? prefix_sum[i-1] : 0);
            for (int k = i; k < j; ++k) {
                min_self(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
            }
        }
    }

    cout << dp[0][n-1] << "\n";

}