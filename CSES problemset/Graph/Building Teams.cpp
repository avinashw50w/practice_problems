/*There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils 
into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of 
the teams.
Input
The first input line has two integers n and m: the number of pupils and friendships. The pupils are 
numbered 1,2,\dots,n.
Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b 
are friends.
Every friendship is between two different pupils. You can assume that there is at most one friendship 
between any two pupils.
Output
Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team 
the pupil will be assigned. You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 <= n <= 10^5
1 <= m <= 2 \cdot 10^5
1 <= a,b <= n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2

IDEA: check whether the graph is bipartite.
If not print IMPOSSIBLE
If yes, print the colors of each node
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int> adj[maxn], c;

void dfs(int u, int color = 0) {
    if (c[u] != -1) {
        if (c[u] != color) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        return;
    }
    c[u] = color;
    for (int v: adj[u]) {
        dfs(v, 1-color);
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    c.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (c[i] < 0) dfs(i);
    }

    for (int e: c) {
        cout << e + 1 << " ";
    }
}