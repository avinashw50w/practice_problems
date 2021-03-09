#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int dp[n + 1][m + 1];
pair<int, int> p[n + 1][m + 1];

int main() {

    string s, t;
    cin >> s >> t;

    s = ' ' + s;
    t = ' ' + t;

    int n = s.length(), m = t.length();

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i - 1][j];
            p[i][j] = { i - 1, j };
            if (dp[i][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                p[i][j] = { i, j - 1 };
            }
            if (s[i] == t[j] and dp[i][j] < 1 + dp[i - 1][j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                p[i][j] = { i - 1, j - 1 };
            }
        }
    }

    string ans = "";
    int i = n - 1, j = m - 1;

    while (i and j) {
        if (p[i][j].first == i - 1 and p[i][j].second == j - 1)
            ans += s[i];
        i = p[i][j].first;
        j = p[i][j].second;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}