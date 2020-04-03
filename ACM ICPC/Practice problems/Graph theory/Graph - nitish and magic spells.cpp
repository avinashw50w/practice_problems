#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
const int MAXN = 10002;
const int INF = (1<<30);

vi vist, order, Rank;
vector<int> G[MAXN];

int N, M, K;

int C[MAXN];
ll dp[MAXN][303];

void init() {
	vist.clear();
	order.clear();
	Rank.clear();
	for(int i=0;i<N;++i) G[i].clear();
}


void dfs(int u) {
	vist[u] = 1;
	for(auto i: G[u])
		if(!vist[i]) dfs(i);

	order.push_back(u);
}

vi topoSort() {
	vist.assign(N, 0);
	Rank.resize(N);

	for(int i=0; i<N; ++i) {
		if(!vist[i]) 
			dfs(i);
	}
	reverse(order.begin(), order.end());

	for(int i=0;i<order.size();++i) Rank[order[i]] = i;

	for(int i: order)
		for(int j: G[i])
			if(Rank[i] >= Rank[j]) return vector<int>();

	return order;
}  

void input() {
	cin>>N>>M>>K;

	for(int i=0;i<N;++i) cin>>C[i];

	for(int i=0;i<N-1;++i) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
	}
}


void solve() {
	init();

	vi seq = topoSort();

	fill(&dp[0][0], &dp[MAXN][0], -INF);

	for(int x: seq) {
		dp[x][0] = max(dp[x][0], (ll)C[x]);
		dp[x][1] = max(dp[x][1], (ll)M * C[x]);

		for(int r=0; r<=K; ++r) {
			ll cost = dp[x][r];

			if(cost == -INF) continue;

			for(auto y: G[x]) {
				dp[y][r] = max(dp[y][r], cost + C[y]);
				if(r != K)
					dp[y][r+1] = max(dp[y][r+1], cost + M * C[y]);
			}
		}
	}

	ll res = *max_element(&dp[0][0], &dp[MAXN][0]);

	cout << res << endl;
}

int main() {
	int t; cin>>t;
	while(t--) {
		input();

		solve();
	}
}