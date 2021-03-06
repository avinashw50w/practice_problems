/*You have N (3 ≤ N ≤ 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 ≤ Li ≤ 1,000,000). Your friend
 has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle with them (degenerate 
 triangles included), he wins; otherwise, you win. You are not sure if your friend is trying to trick you, so you would like to determine your 
 chances of winning by computing the number of ways you could choose three sticks (regardless of order) such that it is impossible to form a 
 triangle with them.

Input

The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the integers L1, ..., LN.
 The input is terminated with N = 0, which should not be processed.

Output

For each test case, output a single line containing the number of triples.

Example

Input:
3
4 2 10
3
1 2 3
4
5 2 9 6
0

Output:
1
0
2

For the first test case, 4 + 2 < 10, so you will win with the one available triple. For the second case, 1 + 2 is equal to 3; since degenerate 
triangles are allowed, the answer is 0.*/

int main() {
	int n,a[2000+2];
	while(si(n)==1 and n){
		rep(i,0,n) si(a[i]);
		sort(a,a+n);
		int ans = 0;
		rep(i,0,n-1){
			rep(j,i+1,n){
				int x = a[i]+a[j];
				int h = upper_bound(a,a+n, x) - a;
				ans += (n-h);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
