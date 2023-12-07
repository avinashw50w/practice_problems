/*Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a 
route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 
1,2,...,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road 
between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 <= n <= 10^5
1 <= m <= 2 \cdot 10^5
1 <= a,b <= n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3

IDEA: find the # of connected components. Then we can connect every component with the first component via a road.
So # of roads required = # of connected components - 1
to print the roads, just print any node in the first component and any node in another component
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int> adj[maxn], ans;
int vis[maxn];

void dfs(int u) {
    vis[u] = 1;
    for (int v: adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << ans.size() - 1 << '\n';
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[0] + 1 << " " << ans[i] + 1 << '\n';
    }
}