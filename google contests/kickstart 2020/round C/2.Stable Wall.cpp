#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
int r, c;
vector<int> G[26];
vector<bool> act, vis;
bool ok;
string ans, wall[maxn];
unordered_set<char> st;

void dfs(int u) {
	act[u] = 1;
	vis[u] = 1;

	for (int v : G[u]) {
		if (act[v] and v ^ u) ok = false;
		else {
			if (!vis[v]) dfs(v);
		}
	}

	act[u] = 0;
	ans += (char) (u + 'A');
}

void solve() {
	act.assign(26, 0);
	vis.assign(26, 0);
	for (auto x : G) x.clear();

	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		cin >> wall[i];
		for (char c : wall[i]) st.insert(c);
		if (i) {
			for (int j = 0; j < c; ++j)
				G[wall[i - 1][j] - 'A'].push_back(wall[i][j] - 'A');
		}
	}

	ans = "";
	ok = true;

	for (char c : st) {
		if (!vis[c - 'A']) dfs(c);
	}

	if (!ok) ans = "-1";
	cout << ans << "\n";
}

int main() {
	int t; cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ": ";
		solve();
	}
}