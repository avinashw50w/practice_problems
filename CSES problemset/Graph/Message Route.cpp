/*Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a 
message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are 
numbered 1,2,...,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a 
connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. 
After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 <= n <= 10^5
1 <= m <= 2 \cdot 10^5
1 <= a,b <= n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

IDEA: use bfs to find the shortest path from 1 to n. 
Also keep track of the path to backtrack*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector<int> adj[maxn];

int main() {
    int n, m;
    cin>>n>>m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> p(n, -1);
    queue<int> q;
    q.push(0);
    p[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            if (p[v] < 0) {
                p[v] = u;
                q.push(v);
            }
        }
    }

    if (p[n-1] < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        int u = n-1;
        while (u) {
            ans.push_back(u);
            u = p[u];
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        cout<< ans.size()<<'\n';
        for (int e: ans) cout<<e+1<< " ";
    }
}