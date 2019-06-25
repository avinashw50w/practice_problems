/*Andrew likes meatballs very much.

He has N plates of meatballs, here the ith plate contains Pi meatballs. You need to find the minimal number of plates Andrew needs to take to his trip to Las Vegas, if he wants to eat there at least M meatballs. Note that each plate is already packed, i.e. he cannot change the amount of meatballs on any plate.

Input

The first line of the input contains an integer T, denoting the number of test cases. The description of T test cases follows. The first line of each test case contains two space-separated integers N and M. The second line contains N space-separated integers P1, P2, ..., PN.

Output

For each test case, output an integer, denoting the minimum number of plates. If it's impossible to take at least M meatballs, print -1.

Constraints

1 ≤ T ≤ 7777
1 ≤ N ≤ 7
1 ≤ M, Pi ≤ 1018 */

/*Explanation:
Sort the plates in descending order of meatballs. Then keep adding plates until you cross the threshold M. This number is your answer.*/
 
int main() {
	ll n,m;
	ll a[10];
	int t=inp();
	while(t--){
		n=inp();m=inp();
		rep(i,0,n) a[i]=inp();
		sort(a,a+n);
		int ans=0;
		for(int i=n-1;i>=0;--i) { m-=a[i]; ans++; if(m<=0) break; }
		if(m>0) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}