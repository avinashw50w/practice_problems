/*Given a number N, find the minimum number of primatic numbers which sum upto N.
A primatic number refers to a number which is either a prime number or can be expressed 
as power of prime number to itself i.e. prime^prime e.g. 4, 27, etc.

Input Format:
The first line will contain two integers: T, the number of test cases.
Each test case consists of a single integer N.

Output Format:
For each query output the minimum number of primatic numbers which can sum upto N.

Constraints:
1 <= T <= 105
2 <= N <= 104 */

typedef long long ll;
const int maxn = 1e4+5;

bool p[maxn];
vector<int> prime;
int dp[maxn];

void seive() {
	ll i, j;
	for(i = 2; i*i<maxn; ++i) {
		if(!p[i]) {
			prime.push_back(i);
			for(j = i*i; j < maxn; j+=i) p[j] = 1;
		}
	}
	while(i < maxn) {
		if(!p[i]) prime.push_back(i);
		++i;
	}
	
	prime.push_back(4); prime.push_back(27); prime.push_back(3125);
	
	for(int i=0; i<maxn; ++i) dp[i] = INT_MAX;
	
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i = 2; i < maxn; ++i) {
		for(int j = 0; j < prime.size(); ++j) {
			if(i >= prime[j])
				dp[i] = min(dp[i], dp[i-prime[j]] + 1);
		}
	}
	
}

int main()
{
	seive();
    int t, n;
    cin>>t;
    while(t--) {
    	cin>>n;
    	cout << dp[n] << endl;
    }
    return 0;
}


/*We see that to make up any number N using the primatic numbers , we would use the primatic numbers which are <= N. 
So , we will only use the primatic numbers <= 104 . There are only 1232 primatic numbers less than 104 and thus we 
can generate them easily.

Now , for calculating the minimum number of primatic numbers we would use a dynamic programming approach.
Let V be the list of primatic numbers less than 104 and DP[i] denote the minimum number of primatic numbers 
which sum up to i , then DP can be calculated using the following relation , 
DP[i] = min(DP[i - V[j]] + 1) for all j such that ( i >= V[j] )*/