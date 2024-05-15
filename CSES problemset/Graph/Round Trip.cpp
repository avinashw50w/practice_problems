/*Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a 
city, goes through two or more other cities, and finally returns to the starting city. Every intermediate 
city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,...,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 <= n <= 10^5
1 <= m <= 2 \cdot 10^5
1 <= a,b <= n

Example
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m;
vector<int> adj[maxn], vis, par;

void dfs(int u = 0, int p = -1) {
    vis[u] = 1;
    par[u] = p;
    for (int v: adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            vector<int> ans;
            int u2 = u;
            while (u != v) {
                ans.push_back(u);
                u = par[u];
            }
            ans.push_back(v);
            ans.push_back(u2);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int e: ans) {
                cout<<e+1<<" ";
            }
            exit(0);
        } else 
        dfs(v, u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.assign(n, 0);
    par.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";
}