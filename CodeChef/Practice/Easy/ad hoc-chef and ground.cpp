/*Today Chef wants to clean his garden. Chef has N columns of ground. Each column has it's height . Chef can choose any column and increase its height by 1 using 1 cube of ground.

Chef wants to spend exactly M cubes. Can he make this in such way that the heights of all columns will become equal?

Input

First line of input contains an integer T denoting number of test cases.
Then for each test case, The first line contains two integers N and M.
The second line contains N space-separated integers A1, A2, ..., AN denoting the initial heights of the columns".
Output

If Chef can spend all cubes and make the columns equal print Yes else print No.
Constraints

1 ≤ T ≤ 10^2
1 ≤ N ≤ 10^2
1 ≤ Ai ≤ 10^2
0 ≤ M ≤ 10^4
Example

Input:
3
5 7
3 3 4 2 1
5 6
3 3 4 2 1
5 8
3 3 4 2 1

Output:
Yes
No
No*/

int main() {
	int t,n,m,a[101];
	t=inp();
	while(t--){
		n=inp(); m=inp();
		int mx = -1;
		rep(i,0,n) {
			a[i]=inp();
			if(a[i]> mx) mx=a[i];
		}
		int cnt = 0;
		rep(i,0,n){
			cnt += mx-a[i];
		}
		
		if(cnt <= m && ((m-cnt) % n) == 0) puts("Yes");
		else puts("No");
	}
	return 0;
}
