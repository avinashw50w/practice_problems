#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
vector<ll> dp; // dp[mask] - maximum score possible for the subset mask
vector<ll> score; // score[mask] - total score of a given mask

void solve(int idx, vector<int> &not_taken, ll score_so_far, int mask, int group) {
    if (idx == not_taken.size()) {
        dp[mask] = max(dp[mask], score_so_far + score[group]);
        return;
    }

    solve(idx+1, not_taken, score_so_far, mask, group);
    solve(idx+1, not_taken, score_so_far, mask ^ (1 << not_taken[idx]), group ^ (1 << not_taken[idx]));
}

int main() {
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    score.resize(1 << n);

    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = i+1; j < n; ++j) {
                    if (mask & (1 << j)) {
                        score[mask] += a[i][j];
                    }
                }
            }
        }
    }

    dp.resize(1 << n, -INF);
    dp[0] = 0;

    for (int mask = 0; mask < (1<<n); ++mask) {
        vector<int> not_taken;
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1<<i)))
                not_taken.push_back(i);
        }

        solve(0, not_taken, dp[mask], mask, 0);
    }

    cout << dp[(1 << n) - 1] << endl;
}