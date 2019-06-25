#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18L;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    ll C;

    cin >> N >> C;

    vector<int> h(N);
    vector<ll> dp(N, INF);
    dp[0] = 0;

    for (int &x: h) cin >> x;

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            dp[j] = min(dp[j], dp[i] + (ll)pow(h[j] - h[i], 2) + C);
        }
    }
    cout << dp[N-1] << endl;
}