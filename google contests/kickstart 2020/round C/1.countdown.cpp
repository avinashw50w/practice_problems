/*Avery has an array of N positive integers. The i-th integer of the array is Ai.

A contiguous subarray is an m-countdown if it is of length m and contains the integers m, m-1, m-2, ..., 2, 1 in that order.
For example, [3, 2, 1] is a 3-countdown.

Can you help Avery count the number of K-countdowns in her array?*/
#include <bits/stdc++.h>
using namespace std;

int a[(int)1e5 + 2];

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0, count = k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] != count) count = k;

        if (a[i] == count) {
            count--;
            if (count == 0) {
                count = k; ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}