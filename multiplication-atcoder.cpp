/*Given are
N
 integers
A
1
,
…
,
A
N
.

We will choose exactly
K
 of these elements. Find the maximum possible product of the chosen elements.

Then, print the maximum product modulo
(
10
9
+
7
)
, using an integer between
0
 and
10
9
+
6
 (inclusive).*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> ar, int K) {
    int n = ar.size();
    sort(ar.begin(), ar.end());

    if (K > n) return INT_MAX;
    vector<pair<int, int>> pre(n, {1, 0}), suff(n, {1, 0});
    map<int, int> p, s;

    pre[0] = {ar[0], 1};
    for (int i = 1; i < n; ++i) {
        if (pre[i - 1].first > ar[i]*pre[i - 1].first) {
            pre[i] = {pre[i - 1].first, pre[i - 1].second};
        }
        else {
            pre[i] = {ar[i]*pre[i - 1].first, pre[i - 1].second + 1};
        }
        p[pre[i].second] = max(p[pre[i].second], pre[i].first);
    }

    // for (auto x: pre) cout << x.first << " - " << x.second << endl; cout << "\n\n";

    suff[n - 1] = {ar[n - 1], 1};
    for (int i = n - 2; i >= 0; --i) {
        if (suff[i + 1].first > ar[i]*suff[i + 1].first) {
            suff[i] = {suff[i + 1].first, suff[i + 1].second};
        }
        else {
            suff[i] = {ar[i]*suff[i + 1].first, suff[i + 1].second + 1};
        }
        s[suff[i].second] = max(s[suff[i].second], suff[i].first);
    }
    // for (auto x: suff) cout << x.first << " - " << x.second << endl; cout << "\n\n";

    int ans = INT_MIN;
    for (int i = 1; i <= K; ++i) {
        ans = max(ans, p[i] * s[K - i]);
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    // for (int x: a) cout <<x <<" ";

    cout << solve(a, k) << endl;
}

// 8 4
// -9 -4 -2 1 2 2 3 5