#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, t; cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, prev, curr, flag = 0;
        cin >> prev;
        for (int i = 1; i < n; ++i) {
            cin >> curr;
            if (prev == curr) flag = 0;
            else {
                if (flag) ans++;
                else ans += 2;
                flag = 1;
            }

            prev = curr;
        }

        cout << ans << "\n";
    }
}