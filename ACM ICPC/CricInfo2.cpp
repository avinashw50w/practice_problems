/* I guess the most visited site of the past 3 months is www.cricinfo.com. First World Cup Cricket, then Australia tour to Bangladesh and now
 IPL T20. I believe there are lots of cricket fans among you. So I do not need to describe the game rule. But for the purpose of this problem
  here is short description of scoring. Any rule out of this problem description is not applicable for this problem.
For this problem we will use only the following outcomes in a ball:

Possible Outcome in a Ball	Runs	Is the Ball valid?
. 							0		Yes
1							1		Yes
2							2		Yes
3							3		Yes
4							4		Yes
6							6		Yes
Wd							1		No
1Wd							2		No
2Wd							3		No
4Wd							5		No
Nb							1		No
1Nb							2		No
4Nb							5		No
6Nb							7		No
W							0		Yes
(Wd stands for Wide, Nb for No Ball and W for Wicket)
In cricinfo we always watch the score card. In cricket an over consists of 6 valid balls. A score card of an over may look like below:
1	.	W	.	Wd	Nb	.	6
In this over there were 1 wicket and 9 runs. In the last over of second innings of a match, a team requires N runs to win. You are to output 
number of ways of the outcome of the over. Note that, as you are watching second innings of the match, so it may be possible that he can 
score N runs in first 4 balls and win the match. That means, it is not necessary to play an entire over to score N runs. Also suppose 
you do not know how many wickets are already gone. So it may also be possible that after a few wicket falls they are all out. Also note that, 
if a team scores greater or equal to N runs the team wins and does not play any ball.
Input

First line contains number of test case T (T <= 10000). For each test a line contains N
(1 <= N <= 10000).
Output

For every test case, output the case number and number of ways of outcome of the last over where the team needs N runs to win. 
As the answer can be very big, so output in mod 10000007.
Example

Input:
1
1

Output:
Case 1: 946  
*/
#define FOR(i,a,b) for(i=a;i<b;++i)
#define SI ({int _x; scanf("%d",&_x); _x;})
#define FILL(a,b) memset(a,b,sizeof a)
LL BASE = 10000007;
LL dp[10001][7];
 
LL f(int r, int b)
{
 
	if(r <= 0) { return 1; }
	if(b == 0) { return 1; }
 
	LL &m = dp[r][b]; if(m != -1) { return m; }
 
	LL cnt = 0;
	cnt += f(r, b-1);
	cnt += f(r-1, b-1);
	cnt += f(r-2, b-1);
	cnt += f(r-3, b-1);
	cnt += f(r-4, b-1);
	cnt += f(r-6, b-1);
	cnt += f(r-1, b);
	cnt += f(r-2, b);
	cnt += f(r-3, b);
	cnt += f(r-5, b);
	cnt += f(r-1, b);
	cnt += f(r-2, b);
	cnt += f(r-5, b);
	cnt += f(r-7, b);
	cnt += f(r, b-1);
 
	return m = (cnt+1)%BASE;
}
 
int main()
{
	FILL(dp, -1);
 
	int T = SI, N, zz;
 
	FOR(zz,1,T+1)
	{
		N = SI;
 
		printf("Case %d: %lld\n", zz, f(N, 6));
	}
 
	return 0;
}