/*Chef and Roma are playing a game. Rules of the game are quite simple.
Initially there are N piles of stones on the table.
In each turn, a player can choose one pile and remove it from the table.
Each player want to maximize the total number of stones removed by him.
Chef takes the first turn.

Please tell Chef the maximum number of stones he can remove assuming that both players play optimally.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of piles.

The second line contains N space separated integers A1, A2, ..., AN denoting the number of stones in each pile.

Output

For each test case, output a single line containg the maximum number of stones that Chef can remove.

Constraints

1 ≤ Ai ≤ 109
Subtask 1 (35 points): T = 10, 1 ≤ N ≤ 1000
Subtask 2 (65 points): T = 10, 1 ≤ N ≤ 105*/

ll a[100000+2];
int main() {
	int t=inp();
	while(t--){
		int n=inp();
		rep(i,0,n) a[i]=inp();
		sort(a,a+n, greater<ll>());
		ll sum = 0;
		for(int i=0;i<n;i+=2) sum += a[i];
		printf("%lld\n", sum);
	}
	return 0;
}
