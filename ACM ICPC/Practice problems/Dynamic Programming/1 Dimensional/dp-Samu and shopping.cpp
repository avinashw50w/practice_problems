/*Samu is in super market and in a mood to do a lot of shopping. She needs to buy shirts, pants and shoes for herself and her family. There are N different shops. 
Each shop contains all these three items but at different prices. Now Samu has a strategy that she won't buy the same item from the current shop if she had 
already bought that item from the shop adjacent to the current shop.

Now Samu is confused, because although she want to follow her strategy strictly but at the same time she want to minimize the total money she spends on shopping. 
Being a good programmer, she asks for your help.

You are provided description about all N shops i.e costs of all three items in each shop. You need to help Samu find minimum money that she needs to spend such 
that she buys exactly one item from every shop.

Input Format: 
First line contain number of test cases T. Each test case in its first line contain N denoting the number of shops in Super Market. Then each of next N lines 
contains three space separated integers denoting cost of shirts, pants and shoes in that particular shop.

Output Format:
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Constraints :
1 ≤ T ≤ 10 
1 ≤ N ≤ 105*/

int main() {
	int N;
	caset{
		si(N);
		int cost[N][3], dp[N][3];
		rep(i,0,N)
			rep(j,0,3)
				si(cost[i][j]);

		rep(i,0,3)
			dp[0][i] = cost[0][i];

		rep(i,1,N)
			rep(j,0,3)
				dp[i][j] = cost[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);

		int ans = min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
		
		printf("%d\n",ans);
	}
	return 0;
}