#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        ll a[n];

        for (int i = 0; i < n; ++i) cin >> a[i];

        ll ans = 0L;
        for (int i = 0; i < n; ++i) {
            ll b; cin >> b;
            ans = max(ans, (ll) k / a[i] * b);
        }

        cout << ans << "\n";
    }
}