/*Chef has an array A consisting of N integers. He also has an intger K.

Chef wants you to find out number of different arrays he can obtain from array A by applying the following operation exactly K times.

Pick some element in the array and multiply it by -1
As answer could be quite large, print it modulo 109 + 7.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space separated integers N, K as defined above.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
Output

For each test case, output a single line containing an integer corresponding to the number of different arrays Chef can get modulo 109 + 7.
Constraints

1 ≤ T ≤ 10
1 ≤ N, K ≤ 105
-106 ≤ Ai ≤ 106 

Example

Input:
3
1 3
100
3 1
1 2 1
3 2
1 2 1

Output:
1
3
4
Explanation

Example case 1.
Chef has only one element and must apply the operation 3 times to it. After applying the operations, he will end up with -100. That is the 
only array he will get.

Example case 2.
Chef can apply operation to one of three elements. So, he can obtain three different arrays.

Example case 3.
Note that other than applying operation to positions (1, 2), (1, 3), (2, 3), Chef can also apply the operation twice on some element and 
get the original.

In summary, Chef can get following four arrays.

[1, 2, 1]
[-1, -2, 1]
[-1, 2, -1]
[1, -2, -1]*/

/* This is a simple n choose k problem, the only thing we have to take care is the number zeroes in the array */
#include <cstdio>
#include <string.h>
using namespace std;
typedef long long int ll;
#define gc getchar_unlocked
inline int inp(){register int n,c;while((c=gc())<='0');n = c-'0';
while((c=gc())>='0'){n=(n<<1)+(n<<3)+c-'0';}return n;}
#define rep(i,a,b) for(int i=a;i<b;++i)
#define MAXN  100002
#define mod 1000000007

int t, n, k, z;
ll fac[MAXN], ifac[MAXN];

ll mpow(ll a, ll b){
	if(b == 0) return 1;
	ll x = mpow(a,b/2);
	x = (x*x)%mod;
	if(b&1) x = (x*a)%mod;
	return x;
}

void prec(){
	fac[0] = fac[1] = 1;
	for(int i=2;i<MAXN;++i) 
		fac[i] = (i*fac[i-1])%mod;
	ifac[MAXN-1] = mpow(fac[MAXN-1], mod-2);
	for(ll i=MAXN-2;i>=0;--i)
		ifac[i] = ((i+1)*ifac[i+1])%mod;
}

int fun1(int n, int k) {
	ll ret = 0;
	for(int i=0; i<=k; ++i) ret = (ret + ifac[i] * ifac[n-i]) % mod;
	ret *= fac[n];
	ret %= mod;
	return (int)ret;
}

int fun2(int n, int k, int start) {
	ll ret = 0;
	for(int i=start; i<=k; i+=2) ret = (ret + ifac[i] * ifac[n-i]) % mod;
	ret *= fac[n];
	ret %= mod;
	return (int)ret; 
}

int solve() {
	if(n == 1 || k == 1) return n;
	if(z == n) return 1;
	int rn = n-z;
	if(z > 0){
		if(k >= rn) return mpow(2, rn);
		else return fun1(rn, k);
	}
	else{
		if(k >= rn) return mpow(2, rn-1);
		else return fun2(rn, k, k&1);
	}
}

int main() {
	prec();
	
	t = inp();
	while(t--) {
		n = inp();
		k = inp();
		z = 0;
		rep(i,0,n) if(inp() == 0) z++;
		printf("%d\n", solve());
	}
}