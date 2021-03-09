/*FInd the longest path in a DAG
IDEA: do a dfs on a node only if its indegree is 0
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> G[maxn];
int dist[maxn];
int indegree[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;

    for (int v : G[u]) {
        dist[v] = max(dist[v], dist[u] + 1);
        --indegree[v];
        if (indegree[v] == 0)
            dfs(v);
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        ++indegree[b];
    }

    for (int i = 1; i <= N; ++i) {
        if (!vis[i] and indegree[i] == 0)
            dfs(i);
    }

    int ans = 0;

    for (int i = 1; i <= N; ++i)
        ans = max(ans, dist[i]);

    printf("%d\n", ans);
}