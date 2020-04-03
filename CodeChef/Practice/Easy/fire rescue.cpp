/*Find the no of connected components along with the prod of the no of nodes in each component*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

vector<int> g[maxn];
int vis[maxn];
int n, m;

void dfs(int u, int &nodes) {
    vis[u] = 1;
    nodes++;
    for (int v: g[u]) {
        if (!vis[v]) {
            dfs(v, nodes);
        }
    }
}

void init() {
    for (int i = 0; i < maxn; ++i) {
        g[i].clear();
        vis[i] = 0;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;

        init();

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int cnt = 0;
        ll cap_select_option = 1L;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                int nodes = 0;
                dfs(i, nodes);
                cnt++;
                cap_select_option = (cap_select_option * nodes) % mod;
            }
        }

        cout << cnt << " " << cap_select_option << "\n";
    }
}