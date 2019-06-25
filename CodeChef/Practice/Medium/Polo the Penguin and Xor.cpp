/*Polo, the Penguin, likes the XOR operation. Please read NOTE if you are not familiar with XOR operation.

XOR-sum of a list of numbers is the result of XOR-ing all of them. XOR-sum of (A[1] XOR A[2] XOR ... XOR A[N]) 
is defined as A[1] XOR (A[2] XOR (A[3] XOR ( ... XOR A[N]))).

He has an array A consisting of N integers. Index in the array are numbered from 1 to N, inclusive. 
Let us denote by F(L, R), the XOR-sum of all integers in the array A whose indices lie from L to R, inclusive, 
i.e. F(L, R) = A[L] XOR A[L+1] XOR ... XOR A[R]. Your task is to find the total sum of XOR-sums F(L, R) 
over all L and R such that 1 ≤ L ≤ R ≤ N.

Input
The first line of the input contains an integer T denoting the number of test cases. 
The description of T test cases follows. The first line of each test case contains a single integer N 
denoting the size of A. The second line contains N space-separated integers A[1], A[2], ..., A[N].

Output
For each test case, output a single line containing the total sum to the corresponding test case.

Constraints
1 ≤ T ≤ 100,000
1 ≤ N ≤ 100,000
0 ≤ A[i] ≤ 1,000,000,000 (10^9)
The total sum of all N over all test cases will not exceed 100,000.
Example
Input:
1
2
1 2

Output:
6*/

/*find sum[L] xor sum[R] for every l, R where 0 <= L < R < N 
and sum[i] = A[0] xor A[1] xor .... xor A[i].

We have to solve at the bit level:
for each bit position j count how many sum[i], 0 <= i < N has jth bit 1, lets say it cnt.
Then the number of sum[i] having jth bit as 0 are N-cnt.
Now sum[p] ^ sum[q] = 1, only if (sum[p]=1, sum[q]=0) or (sum[p]=0, sum[q]=1).
So the no pairs which will give 1 is cnt * (N-cnt) */

vector<int> v;
int A[MAX];
int main()
{
	int T;
	scanf("%d",&T);
//	T = 1;
	while(T--)
	{
		int N;
		scanf("%d",&N);
		A[0] = 0;
		for(int i=  1 ; i <= N; i++)
		{
			scanf("%d",A+i);
			A[i] ^= A[i-1];
		}
		long long ans = 0;
		for(int i = 30 ; i >= 0 ; i--)
		{
			int c = 0;
			int t = 1 << i;
			for(int j = 0 ; j <= N ; j++ )
			{
				if(t & A[j])
					c++;
			}
			ans += (c)*((long long)(N-c+1))*((long long)(t));
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
///////////////////////////////////////////////////////

int main(){
    int t;
    t= read();
    while(t--){
        int n,cur=0,sum[31]={0};
        n = read();
        for(int i=0;i<n;++i){
            cur^= read();
            for(int j=0;j<31;++j){
	            if(cur&(1<<j)){
	            sum[j]++;
	            //printf("%d\t",sum[j]);
	            }
            }
        }
        long long ans=0;
        for(int i=0;i<31;++i){
          long long temp = sum[i];
          temp*=1+n-sum[i];
          temp*=1<<i;
          ans+=temp;
          sum[i]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
} 
