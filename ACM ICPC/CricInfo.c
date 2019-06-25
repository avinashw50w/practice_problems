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
#include <stdio.h>
 
int run[15]={0,1,2,3,4,6,1,2,3,5,1,2,5,7,0};      //  runs taken
int ball[15]={1,1,1,1,1,1,0,0,0,0,0,0,0,0,1};     // is the ball valid(1) or not(0)    ,refer the table given above
long count,n;
long a[10000][7]={0};
 
void fun(long runs,int balls)
{
	
	long nb,nr,i,bn,rn,c;
	c=0;	
 
	for(i=0;i<15;i++)
	{
		bn=balls-ball[i];	
		rn=runs-run[i];		
	
		if(bn>=0)        // if no of balls needed is 0 or positive
		{
			if(i==14)	c++;      // if a wicket is taken
			if(rn<=0)		      // if required runs can be scored in the ith run
			{
				c++;
	
			}
			else
			{
				if(bn>0)        // if runs required are more and there are remaining balls
					c=c+a[rn][bn];
				else
					c++;
			}
		}
	}
	a[runs][balls]=c%10000007;
}
 
 
int main()
{
	int i,j,t,b,r;
	
	scanf("%d",&t);
 
	
	for(i=1;i<10001;i++)
	{
	for(j=1;j<7;j++)
		{
		fun(i,j);
 
		}
 
	}
	
	for(i=0;i<t;i++)
	{
		scanf("%ld",&n);
		printf("Case %d: %ld\n",i+1,a[n][6]);	
	}
 
	
 
	return 0;
}