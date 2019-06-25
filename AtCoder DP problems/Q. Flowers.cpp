#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> height(n), cost(n);

    int base = 1;
    while (base <= n) {
        base <<= 1;
    }

    vector<ll> tree(base<<1);

    for (int i = 0; i < n; ++i) cin >> height[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];

    // dp[i] - the maximum beauty when the last picked flower is of height i
    vector<ll> dp(n+1);

    for (int flower = 0; flower < n; ++flower) {
        // the maximum dp[i] for i in [0...height[flower]-1]
        ll best = 0L;
        // query the tree
        for (int x = base + height[flower]; x > 1; x >>= 1) {
            if (x & 1) best = max(best, tree[x-1]);
        }

        dp[height[flower]] = best + cost[flower];
        // update the tree
        for (int x = base + height[flower]; x >= 1; x >>= 1) {
            tree[x] = max(tree[x], dp[height[flower]]);
        }
    }

    ll ans = *max_element(dp.begin(), dp.end());

    cout << ans << endl;
}