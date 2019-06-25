/*To test Ryotsu's knowledge of primes, his father gave him a simple task. The task is to find the sum of every Kth prime numbers in given list of numbers. He's having trouble solving it, being an elementary school student. Help him accomplish the task.

Input Format:
The first line of the input contains an integer T denoting the number of test cases.
Each test case contains two space separated integers N and K followed by N space separated numbers.

Output Format:
For each test case, output the sum of every Kth prime number followed by newline.

Constraints:

1 ≤ T ≤ 10000
1 ≤ N ≤ 106
1 ≤ K ≤ 100
0 ≤ Ai ≤ 106 */
// simply iterate through the array and keep checking whether the number in prime or not

const int maxn = 1000001;
int p[maxn];

void seive() {
	p[0] = p[1] = 1;
	long long i,j;
	for(i=2;i*i<maxn;++i) {
		if(!p[i]){
			for(j=i*i;j<maxn;j+=i) p[j]=1;
		}
	}
}

int main()
{
	seive();
    int t, n, k;
    cin>>t;
    while(t--) {
    	cin>>n>>k;
    	int a, cnt = 0;
    	long long sum = 0;
    	for(int i=0; i<n; ++i){
    		cin>>a;
    		if(!p[a]) cnt++;
    		if(cnt == k) sum += a, cnt = 0;
    	}
    	
    	cout << sum << endl;
    }
    return 0;
}