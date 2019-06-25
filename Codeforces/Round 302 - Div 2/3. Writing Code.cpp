/*Programmers working on a large project have just received a task to write exactly m lines of code. 
There are n programmers working on a project, the i-th of them makes exactly ai bugs in every line of code that he writes.

Let's call a sequence of non-negative integers v1, v2, ..., vn a plan, if v1 + v2 + ... + vn = m. 
The programmers follow the plan like that: in the beginning the first programmer writes the first v1 lines 
of the given task, then the second programmer writes v2 more lines of the given task, and so on. In the end, 
the last programmer writes the remaining lines of the code. Let's call a plan good, 
if all the written lines of the task contain at most b bugs in total.

Your task is to determine how many distinct good plans are there. As the number of plans can be large, 
print the remainder of this number modulo given positive integer mod.

Input
The first line contains four integers n, m, b, mod (1 ≤ n, m ≤ 500, 0 ≤ b ≤ 500; 1 ≤ mod ≤ 109 + 7) — 
the number of programmers, the number of lines of code in the task, the maximum total number of bugs 
respectively and the modulo you should use when printing the answer.

The next line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 500) — 
the number of bugs per line for each programmer.

Output
Print a single integer — the answer to the problem modulo mod.*/

/*Let's create the solution, which will work too slow, but after that we will improve it. Let's calculate the 
following dynamic programming z[i][j][k] — answer to the problem, if we already used exactly i programmers, 
writed exactly j lines of code, and there are exactly k bugs. How we can do transitions in such dp? We can 
suppose that we i-th programmer will write r lines of code, then we should add to z[i][j][k] value z[i - 1][j - r][k - ra[i]]

But let's look at transitions from the other side. It's clear, that there are exactly 2 cases. The first case, 
we will give any task for i-th programmer. So, we should add to z[i][j][k] value z[i - 1][j][k]. 
The second case, is to give at least one task to i-th programmer. So, this value will be included in that state: 
z[i][j - 1][k - a[i]]. In that solution we use same idea, which is used to calculate binomial coefficients 
using Pascal's triangle. So overall solution will have complexity: O(n3)*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < int(n); i++)

const int N = 505;
int a[N];
int z[2][N][N];

int main() {
  int n, bl, bugs, md;
  scanf("%d %d %d %d", &n, &bl, &bugs, &md);
  rep(i, n) scanf("%d", &a[i]);
  z[0][0][0] = 1;

  for(int i = 1; i <= n; i++){
    int ii = i & 1;
    for(int j = 0; j <= bl; j++) {
      for(int k = 0; k <= bugs; k++) {
        z[ii][j][k] = z[ii ^ 1][j][k]; // if the ith programmer doesn't write any line of code
        if (j > 0 && k >= a[i - 1])
          z[ii][j][k] += z[ii][j - 1][k - a[i - 1]]; // if the ith programmer writes this jth line of code
        while (z[ii][j][k] >= md) z[ii][j][k] -= md;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= bugs; i++) {
    ans += z[n & 1][bl][i];
    while (ans >= md) ans -= md;
  }
  printf("%d\n", ans);
}

/////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int dp[505][505]; // dp[i][j] stores the no of ways to write i lines of code with a total of j bugs by all the n programmers

int main(){
	int n,i,j,a,m,b,mod;
	cin>>n>>m>>b>>mod;
	dp[0][0]=1;
	while(n--){
		cin>>a;
		for(i=1;i<=m;++i)
			for(j=a;j<=b;++j)
				dp[i][j] = (dp[i][j] + dp[i-1][j-a])%mod;
	}
	int ret=0;
	for(i=0;i<=b;++i)
		ret = (ret + dp[m][i])%mod;
	cout<<ret<<endl;
}