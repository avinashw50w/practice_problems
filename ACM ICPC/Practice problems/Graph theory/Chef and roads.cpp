/*Chef lives in Chefland. Chefland can be accurately represented by a certain number of intersections and the roads connecting them. 
Chefland is a strange place, because all the roads there are one-way. Also, for any two intersections A and B, once you travel from A to B, 
you can never return to A again because there is simply no route you can take to get back to A.

Unaware of this, Chef set out to visit his friend, and now he can't return home! So, Chef decides to travel to the townhall and complain 
about this ridiculous system. Studying the map of Chefland, Chef wonders about the number of ways in which he can travel to the townhall. 
Help him find this number. As the number may be very large, print it modulo 10^9+7.*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int mod = (int)1e9 + 7;

vi G[100000+5];
ll dp[100000+5];
int d;

ll dfs(int u) {
	if(u == d) return 1;

	if(dp[u] != -1) return dp[u];
	ll ans = 0;
	
	for(int v: G[u])
		ans = ((ans % mod) + dfs(v) % mod) % mod;

	return dp[u] = ans;
}


int main() {
	int N, M, src, dest, a, b;

	cin >> N >> M;

	cin >> src >> dest;

	while(M--) {
		cin >> a >> b;
		G[a].push_back(b);
	}

	memset(dp, -1, sizeof(dp));
	d = dest;

	cout << dfs(src) << endl;
	return 0;
}

/*PROBLEM:
Given a DAG (directed acyclic graph) with N nodes and M edges, the problem requires one to find the number of different paths 
that exist from a given node P to another node Q.

QUICK EXPLANATION:
The first step is to toposort the given graph. If dp[u] be the number of paths from node u to node Q. 
Then dp[u] = summation of dp[v] for all v for each edge directed from u to v. We obtain dp[u] for each node u in the graph 
in reverse topological order. Then dp[P] is the required answer.

Thus, our trivial function would look something like
function f(u)
    if u equals Q
        return 1
    sum = 0
    for each edge u→v
        sum = sum + f(v)
    return sum

another approach :
Kahn's algorithm for toposorting a DAG is provided below 
L = empty list
D = array of indegrees for each node
S = list of all nodes u with D[u] = 0
while S is not empty repeat
    remove a node u from S
    append u to the end of L
    for each edge u→v
        D[v] = D[v] - 1
        if D[v] equals 0
            add v to S
The next step is to use dynamic programming to calculate our f values. We also need to make sure to store the values modulo 109+7.
dp = array to store f values
set dp[u] = 0 for each node u
dp[Q] = 1
for each node u in revere order of L
    for each edge u→v
        dp[u] = dp[u] + dp[v]
        dp[u] = dp[u] % 1000000007

*/
