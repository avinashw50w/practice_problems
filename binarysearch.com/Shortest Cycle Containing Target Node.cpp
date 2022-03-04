/*You are given a two-dimensional list of integers graph representing a directed graph as an adjacency list. You are also given an integer target.

Return the length of a shortest cycle that contains target. If a solution does not exist, return -1.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in graph
Example 1
Input
Visualize
graph = [
    [1],
    [2],
    [0]
]
target = 0
Output
3*/
const int inf = 1e9 + 7;
int n;
vector<int> vis, dist;
vector<vector<int>> adj;

int dfs(int u, int target) {
    if (u == target) return 0;
    vis[u] = 1;
    // find the min dist from each children of u from target
    int minDist = inf;
    for (int v: adj[u]) {
        if (vis[v] == 0) {
            minDist = min(minDist, dfs(v, target));
        }
        // if we have already traversed the subtree v, then just return the min dist
        else if (vis[v] == 2) {
            minDist = min(minDist, dist[v]);
        }
    }

    vis[u] = 2;
    dist[u] = minDist == inf ? inf : minDist + 1;
    return dist[u];
}

int solve(vector<vector<int>>& graph, int target) {
    adj = graph;
    n = adj.size();
    vis.assign(n, 0);
    dist.assign(n, inf);

    int res = inf;
    for (int i : adj[target]) {
        res = min(res, 1 + dfs(i, target));
    }

    return res == inf ? -1 : res;
}