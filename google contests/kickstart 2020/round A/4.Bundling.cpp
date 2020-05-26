/*Pip has N strings. Each string consists only of letters from A to Z. Pip would like to bundle their strings into groups of size K. Each string must belong to exactly one group.

The score of a group is equal to the length of the longest prefix shared by all the strings in that group. For example:
The group {RAINBOW, RANK, RANDOM, RANK} has a score of 2 (the longest prefix is 'RA').
The group {FIRE, FIREBALL, FIREFIGHTER} has a score of 4 (the longest prefix is 'FIRE').
The group {ALLOCATION, PLATE, WORKOUT, BUNDLING} has a score of 0 (the longest prefix is '').

Please help Pip bundle their strings into groups of size K, such that the sum of scores of the groups is maximized.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the two integers N and K. Then, N lines follow, each containing one of Pip's strings.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum sum of scores possible.*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int t[maxn][26];
int cnt[maxn];
int n, k, ans;

void dfs(int u = 0, int depth = 0) {
    for (int v = 0; v < 26; ++v) {
        if (t[u][v]) {
            dfs(t[u][v], depth+1);
            cnt[u] += cnt[t[u][v]];
        }
    }

    while (cnt[u] >= k) {
        cnt[u] -= k;
        ans += depth;
    }
}

void solve() {
    n, k; cin >> n >> k;
    int sz = 1;
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int u = 0;
        for (char c: s) {
            if (!t[u][c-'A']) t[u][c-'A'] = sz++;
            u = t[u][c-'A'];
        }

        cnt[u]++;
    }

    ans = 0;
    dfs();  

    cout << ans << endl;  
}

int main() {

    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}