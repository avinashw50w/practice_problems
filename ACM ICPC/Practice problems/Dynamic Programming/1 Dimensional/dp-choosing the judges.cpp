/*Harry was contesting to be the most stylist person in his college. He had to collect maximum points from the judges to be able to win. However there was a 
problem. The judges were sitting in a line and each pair of adjacent judges had ego issues with each other. So if one judge gave X points to Harry then the next 
judge won’t give him any points. Harry had a friend in the organizing team and through him he had found out the exact points he would get from each judge if 
he chose their score to be considered. Help him find out the maximum points he can score.

INPUT
The first line of input contains the number of test cases, T.
0 < T < = 10
Each test case starts with a number N, the number of judges.
0 <= N < = 10^4. 
The next line will have N numbers, number of points each judge gave Harry
0 < = X(i) < = 10^9.
The order of the judges does not change.

OUTPUT
For each test case print “Case T: A” without quotes in a single line. 
T is the case number, starting with 1.
A is the maximum number of points Harry can collect.
SAMPLE INPUT 
2
5
1 2 3 4 5
1
10
SAMPLE OUTPUT 
Case 1: 9
Case 2: 10*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	int n, a[10101], dp[10101];
	int test = 1;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];

		memset(dp,0,sizeof(dp));

		dp[0] = 0;
		dp[1] = a[1];

		for(int i=2;i<=n;++i)
			dp[i] = max(dp[i-1], a[i]+dp[i-2]);
		

		printf("Case %d: %d\n",test++, dp[n] );
	}
}