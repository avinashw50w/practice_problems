/* You are given a tree with N vertices rooted at 1. You consider all the N subtrees (rooted at 1,2..N such that subtree rooted at i consists
 of i and all nodes which contain i as an ancestor).

Each node in the graph also consists of a color. The colors can be between 1 to K. 

For each subtree find the no. of distinct colours in that subtree. 

Output the sum of all these N numbers.
 
Input

First line of input contains 2 integers N,K.

Next N-1 lines (from line 2 to line N) contain 1 integer each. (i + 1) th line contains the parent of i+2 and is guaranteed to be lesser 
than i+2. 1 is the root of the tree. 

Next line contains N integers , each from 1 to K representing the colors of each node. 
Output

Single integer corresponding to the required answer.
Constraints

1 <= N <= 10^5
1 <= K <= 10^5
 
Example

Input:
3 4
1
1
1 2 3

Output:
5
 
Explanation


The 3 subtrees are [1,2,3] , [2], [3] , which have 3,1,1 distinct colours respectively. So the answer is 5.*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define ft first
#define se second
#define mp make_pair
int fenwick[100001], n, k;
int start[100001], color[100001];
bool visit[100001];
vector<int> adj[100001];
int star = 0;
ll ans = 0;
void init () {
    memset(fenwick, 0, sizeof fenwick);
    memset(start, -1, sizeof start);
    memset(visit, 0, sizeof visit);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n - 1; ++i) {
    	int x;
    	scanf("%d", &x);
    	x--;
    	adj[i].pb(x);
    	adj[x].pb(i);
    }
    for (int i = 0; i < n; ++i) scanf("%d", &color[i]);
}
void update (int pos, int extra) {
    while (pos < 100001) {
        fenwick[pos] += extra;
        pos |= (pos + 1);
    }
}
int query (int pos) {
    int ans=0;
    while (pos >= 0) {
        ans += fenwick[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return ans;
}
void dfs(int rt) {
	visit[rt] = 1;
	star++;
	int tmp = star;
	for (int i = 0; i < adj[rt].size(); ++i) {
		if (!visit[adj[rt][i]]) dfs(adj[rt][i]);
	}
	if (start[color[rt]] == -1) {
		start[color[rt]] = tmp;
		update(tmp, 1);
	} else if (start[color[rt]] < tmp){
		update(start[color[rt]], -1);
		update(tmp, 1);
		start[color[rt]] = tmp;
	}
	// cout << query(100000) - query(tmp - 1) << " " << rt << endl;
	ans += query(100000) - query(tmp - 1);
}
int main(int argc, char const *argv[]){
	init();
    dfs(0);
    printf("%lld\n", ans);
	return 0;
} 

