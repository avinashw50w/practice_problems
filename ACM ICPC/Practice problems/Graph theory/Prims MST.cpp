#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
vii g[3030];
int vis[3030];
int n, m;

long long Prims(int s) {
	memset(vis, 0, sizeof vis);
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0,s});

	long long minCost = 0;

	while(!Q.empty()) {
		auto it = Q.top();
		Q.pop();
		int u = it.second;
		int d = it.first;
		if(vis[u]) continue;
		vis[u] = 1;
		minCost += d;

		for(auto i: g[u]){
			if(!vis[i.first]) Q.push({i.second, i.first});
		}
	}

	return minCost;
}

int main() {
	cin>>n>>m;

	int x, y, r;

	while(m--) {
		cin>>x>>y>>r;

		g[x].push_back({y,r});
		g[y].push_back({x,r});
	}

	int S; cin>>S;

	cout << Prims(S) << endl;
}
