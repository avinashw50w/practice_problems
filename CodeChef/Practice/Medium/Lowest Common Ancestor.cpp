/*In a rooted tree, the lowest common ancestor (or LCA for short) of two vertices u and v 
is defined as the lowest vertex that is ancestor of both that two vertices.

Given a tree of N vertices, you need to answer the question of the form "r u v" 
which means if the root of the tree is at r then what is LCA of u and v.

 

Input
The first line contains a single integer N. Each line in the next N - 1 lines contains a pair of 
integer u and v representing a edge between this two vertices.

The next line contains a single integer Q which is the number of the queries. Each line in the 
next Q lines contains three integers r, u, v representing a query.

1 ≤ N, Q ≤ 2 × 105 

Output
For each query, write out the answer on a single line.*/

/*There are two interesting observations that you can make:

Given the query "r u v" what can be the answer? 
The possible answers are r, u, v, LCA(r, u), LCA(r, v), LCA(u, v) 
where LCA(x, y) is LCA of x and y when the tree is rooted at 1.

The LCA of u and v when the root is at r is the vertex x such that the 
sum of shortest path from x to u, x to v and x to r is smallest.*/

#define maxn 300111
#define logN 20

vector <int> adj[maxn];
int par[maxn][logN], depth[maxn], n;

void dfs(int u) {
    for (int i = 1; i < logN; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];

    for (int v: adj[u]) {

        if (!depth[v]) {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = logN - 1; i >= 0; i--)
        if (depth[par[u][i]] >= depth[v]) {
            u = par[u][i];
        }

    if (u == v) return u;

    for (int i = logN - 1; i >= 0; i--)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = f[v][i];
        }

    return par[u][0];
}

int dist (int u, int v) {
    int x = lca(u, v);
    int res = depth[u] + depth[v] - 2 * depth[x];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);

    int q;
    cin >> q;

    pair<int, int> p[6];
    while (q--) {
        int u, v, r;

        cin >> r >> u >> v;

        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r, u);
        p[4].second = lca(r, v);
        p[5].second = lca(u, v);

        for (int i = 0; i < 6; i++) {
            int x = p[i].second;
            p[i].first = dist(x, r) + dist(x, u) + dist(x, v);
        }

        sort(p, p + 6);

        cout << p[0].second << endl;
    }
}