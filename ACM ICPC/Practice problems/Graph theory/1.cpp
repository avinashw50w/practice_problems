/*Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. 
Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains 
two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ M ≤ 105
0 ≤ Ai ≤ 1012

SAMPLE INPUT 
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT 
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.  */

vi *g, vist;
ll bananas[MAXN+2], coins = 0;
int n, m;

void dfs(int u){
	vist[u] = 1;
	coins += bananas[u];
	for(int i=0;i<g[u].size();++i){
		int v = g[u][i];
		if(!vist[v]){
			dfs(v);
		}
	}
}

int main() {
	int u,v;
	caset{
		si(n); si(m);
		g = new vi[n+2];
		rep(i,0,m){
			si(u);si(v);
			g[u-1].push_back(v-1);
			g[v-1].push_back(u-1);
		}
		rep(i,0,n) sl(bananas[i]);
		ll ans = 0;
		vist.assign(n,0);
		rep(i,0,n){
			if(!vist[i]){
				coins = 0;
				dfs(i);
				ans = max(ans, coins);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
