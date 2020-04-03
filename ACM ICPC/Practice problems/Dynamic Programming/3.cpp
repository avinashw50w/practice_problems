/*Samu is playing a shooting game in play station. There are two apples to aim in this shooting game. Hitting first apple will provide 
her X points and hitting second apple will provide her Y points. And if she misses the apple she chose to hit, she wont get any point.
Now she is having N coins and each shoot will cost her 1 coin and she needs to score at least W points to win the game.

Samu don't like to loose at any cost. At each turn, she has two choices. The choices include:-

Hitting first apple with probability P1 percent. However, she might miss it with probability (1-P1) percentage.
Hitting second apple with probability P2 percent. However, she might miss it with probability (1-P2) percentage.
She would like to know what is the maximal expected probability(as a percentage b/w 0 and 100) of winning the shooting game.

Input Format: 
First line contains the number of test cases T. 
Each test case consists of six space separated integers of the form X Y N W P1 P2 as described in the statement.

Output Format: 
For each test case, print the result as described above in a separate line.

Note:
Choosing to hit any apple is entirely her choice. Both are independent events meaning P1 + P2 may/may not exceed 100.
Output must contain 6 digits after decimal.

Constraints: 
1 ≤ T ≤ 10 
1 ≤ X,Y ≤ 10 
1 ≤ N,W ≤ 1000 
0 ≤ P1,P2 ≤ 100

SAMPLE INPUT 
1
2 3 2 5 50 25   

Quick Explanation:

Problem asks you to maximize your chances of winning i.e scoring atleast W points in this case. At each turn, you have two chances to choose from.

Solution:

The problem can be solved by DP.

Lets maintain a state F(idx, pts) where idx denotes the turn which you are on and pts denotes the number of points you have fetched till now. So, overall the state denotes the maximum expected probability you can achieve while you are at idxth turn and having pts points.

Lets look at the pseudo code to understand the implementation.

Pseudo Code:

F(idx, pts) {

       if ( idx == n ) return (pts >= w)

       //lets take choice #1
      //Now, we either hit the target with prob p1 or miss it with (1-p1)
       double  ans1 = p1*f(idx+1,pts+x) + (1-p1)*f(idx+1,pts)

       //lets take choice #2
      //Now we either hit the target with prob p2 or miss it with (1-p2)
       double ans2 = p2*f(idx+1,pts+y) + (1-p2)*f(idx+1,pts)

       return max(ans1,ans2)
}*/

const int MAXN = 1010;
/*========================================================================================*/
double dp[MAXN][MAXN];
int main() {
	int x,y,n,w,P1,P2;
	caset{
		cin>>x>>y>>n>>w>>P1>>P2;
		double p1 = 0.01 * P1;
		double p2 = 0.01 * P2;

		mset(dp,0);
		dp[0][0] = 1;
		rep(i,1,n+1) dp[i][0] = 1;  // prob. of scoring 0 pts. with +ve no of coins is 1
		rep(i,1,w+1) dp[0][i] = 0;  // prob. of scoring +ve pts. with 0 coins is 0

		rep(i,1,n+1){
			rep(j,1,w+1){
				double choice1 = p1*dp[i-1][max(j-x,0)] + (1-p1)*dp[i-1][max(j,0)];
				double choice2 = p2*dp[i-1][max(j-y,0)] + (1-p2)*dp[i-1][max(j,0)];

				dp[i][j] = max(choice1, choice2);
			}
		}
		printf("%.6lf\n", dp[n][w]*100);
	}

	return 0;
}
