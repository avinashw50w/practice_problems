/*A tree is given in which each edge is having some weight associated with it and you are given a number K. 

So starting from root in K-steps how much maximum weight you can collect. You can traverse in any direction 
either from parent to child or child to parent. You can visit a node multiple times. 

Eg:
			    O
			 5/   \ 6
			 O	   O
		   24/   1/ \11   

For K=1, ans=6
For K=2, ans=29 etc..*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 50

int root;
int weight[MAX_N]; // weight of each node
vector <int> g[MAX_N]; // adjacency list
int dp[MAX_N][MAX_N]; // initialized with -1

int solve(int node, int jumps){
	if(jumps == 0)
		return weight[node];
	if(dp[node][jumps] == -1){
		dp[node][jumps] = weight[node];
		for(int v : g[node])
			dp[node][jumps] = max(dp[node][jumps], weight[node] + solve(v, jumps - 1));
	}
	return dp[node][jumps];
}

void add(int x, int y) {
	g[x].push_back(y);
	g[y].push_back(x);
}
int main() {

	add(0,1);add(0,2);add(1,3);add(2,4);add(2,5);
	weight[0] = 0;
	weight[1] = 5;
	weight[2] = 6;
	weight[3] = 8;
	weight[4] = 10;
	weight[5] = 11;

	memset(dp,-1,sizeof(dp));

	cout << solve(0, 3);
}