/*There is a certain "random number generator" (RNG) which takes one nonnegative integer as input and generates another 
nonnegative integer as output. But you know that the RNG is really not very random at all! It uses a fixed number K, 
and always performs one of the following three operations:

with probability A/100: return the bitwise AND of the input and K
with probability B/100: return the bitwise OR of the input and K
with probability C/100: return the bitwise XOR of the input and K
(You may assume that the RNG is truly random in the way that it chooses the operation each time, based on the values of A, B, and C.)

You have N copies of this RNG, and you have arranged them in series such that output from one machine will be the input 
for the next machine in the series. If you provide X as an input to the first machine, what will be the expected value of 
the output of the final machine in the series?

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of one line with 
six integers N, X, K, A, B, and C. Respectively, these denote the number of machines, the initial input, the fixed number 
with which all the bitwise operations will be performed (on every machine), 
and 100 times the probabilities of the bitwise AND, OR, and XOR operations.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the 
expected value of the final output. y will be considered correct if it is within an absolute or relative error of 10-9 of the 
correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits

1 = T = 50.
0 = A = 100.
0 = B = 100.
0 = C = 100.
A+B+C = 100.

Small dataset

1 = N = 10.
0 = X = 104.
0 = K = 104.
Large dataset

1 = N = 105.
0 = X = 109.
0 = K = 109.
Sample


Input 
 	
Output 
 
3
1 5 5 10 50 40
2 5 5 10 50 40
10 15 21 70 20 10

Case #1: 3.0000000000
Case #2: 3.6000000000
Case #3: 15.6850579098
In sample test case #1, the final output will be 5 if AND or OR happens and 0 if XOR happens. So the probability of getting 5 is (0.1 + 0.5) and the probability 
of getting 0 is 0.4. So the expected final output is 5 * 0.6 + 0 * 0.4 = 3.

In sample test case #2, the final output will be 5 with probability 0.72, and 0 otherwise.*/
#include<stdio.h>
double dp[100005][2];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,T,n,x,k,A,B,C,i,bk,bx,bit,j;
	double a,b,c,ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d %d %d %d %d",&n,&x,&k,&A,&B,&C);
		a=(double)A/100;
		b=(double)B/100;
		c=(double)C/100;
//		printf("%lf %lf %lf\n",a,b,c);
		ans=0.0;
		for(bit=0;bit<33;bit++)
		{
			dp[0][0]=0.0;
			dp[0][1]=1.0;
			bk=(k&(1ll<<bit))>0?1:0;
			bx=(x&(1ll<<bit))>0?1:0;
			for(i=1;i<=n;i++)
			{
				dp[i][0]=0.0;
				dp[i][1]=0.0;
				
				dp[i][0]+=a*dp[i-1][bk&0];
				dp[i][0]+=b*dp[i-1][bk|0];
				dp[i][0]+=c*dp[i-1][bk^0];
				dp[i][1]+=a*dp[i-1][bk&1];
				dp[i][1]+=b*dp[i-1][bk|1];
				dp[i][1]+=c*dp[i-1][bk^1];
			}
			ans+=dp[n][bx]*(double)(1<<bit);
		}
		printf("Case #%d: %.10lf\n",t,ans);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////

double dp[100005][2];  
int main()  
{  
    //freopen("/Users/fengguowen/Downloads/C-large-practice.in","r",stdin);  
    //freopen("/Users/fengguowen/Downloads/C-large-practice.out","w",stdout);  
    int T,t,N,X,K,A,B,C;  
    int i;  
    cin>>T;  
    for(t=1;t<=T;t++)  
    {  
        double ans=0;  
        cin>>N>>X>>K>>A>>B>>C;  
        double a=A*1.0/100;  
        double b=B*1.0/100;  
        double c=C*1.0/100;  
        int bx,bk;  
        int bit=1;  
        while(X||K)  
        {  
            bx=X&1;  
            bk=K&1;  
            X>>=1;  
            K>>=1;  
            dp[0][0]=0,dp[0][1]=0;  
            dp[0][bx]=1;  
            for(i=1;i<=N;i++)  
            {  
                dp[i][0]=0;  
                dp[i][1]=0;  
                  
                dp[i][bk&1]+=a*dp[i-1][1];  
                dp[i][bk&0]+=a*dp[i-1][0];  
  
                dp[i][bk|1]+=b*dp[i-1][1];  
                dp[i][bk|0]+=b*dp[i-1][0];  
                  
                dp[i][bk^1]+=c*dp[i-1][1];  
                dp[i][bk^0]+=c*dp[i-1][0];  
            }  
            ans+=dp[N][1]*bit;  
            bit<<=1;  
        }  
        printf("Case #%d: %.10lf\n",t,ans);  
    }  
    return 0;  
}  
