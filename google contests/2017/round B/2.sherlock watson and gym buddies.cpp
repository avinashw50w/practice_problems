/*Watson and Sherlock are gym buddies.

Their gym trainer has given them three numbers, A, B, and N, and has asked Watson and Sherlock to pick two different positive integers i and j, where i and j are 
both less than or equal to N. Watson is expected to eat exactly i^A sprouts every day, and Sherlock is expected to eat exactly j^B sprouts every day.

Watson and Sherlock have noticed that if the total number of sprouts eaten by them on a given day is divisible by a certain integer K, then they get along well 
that day.

So, Watson and Sherlock need your help to determine how many such pairs of (i, j) exist, where i != j. As the number of pairs can be really high, please output 
it modulo 109+7 (1000000007).
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with 4 integers A, B, N and K, as 
described above.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the required answer.

Limits

1 ≤ T ≤ 100.
0 ≤ A ≤ 106.
0 ≤ B ≤ 106.
Small dataset

1 ≤ K ≤ 10000.
1 ≤ N ≤ 1000.
Large dataset

1 ≤ K ≤ 100000.
1 ≤ N ≤ 1018.
Sample


Input 
 	
Output 
 
3
1 1 5 3
1 2 4 5
1 1 2 2

Case #1: 8
Case #2: 3
Case #3: 0

In Case 1, the possible pairs are (1, 2), (1, 5), (2, 1), (2, 4), (4, 2), (4, 5), (5, 1), and (5, 4).
In Case 2, the possible pairs are (1, 2), (1, 3), and (4, 1).
In Case 3, No possible pairs are there, as i != j.

IDEA: we have to find the # of pairs (i, j) 1 <= i, j <= N such that (i^A + j^B) mod K = 0

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXK = 1e5;
const ll MOD = 1e9 + 7;
ll i_A[MAXK+1], j_B[MAXK+1], i_j_same[MAXK+1];
 
int pow_mod(int a, int n, int mod){
    int r = 1 % mod;
    while (n) {
        if (n&1)
            r = (ll)r*a%mod;
        a = (ll)a*a%mod;
        n >>= 1;
    }
 
    return r;
}

int main() {
 
    int T;
    int A, B;
    ll N, K;
 
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        memset(i_A, 0, sizeof(i_A));
        memset(j_B, 0, sizeof(j_B));
        memset(i_j_same, 0, sizeof(i_j_same));
 
        cin >> A >> B >> N >> K;
        ll res = 0;
 
        for (int p = 1; p <= min(N, K); p++)
        {
            ll cnt = ((N - p) / K + 1) % MOD;
            int tmp_A = pow_mod(p, A, K), tmp_B = pow_mod(p, B, K);
            i_A[tmp_A] += cnt;
            j_B[tmp_B] += cnt;
            if ((tmp_A + tmp_B) % K == 0) // (0 + 0) != K, but (0 + 0) % K == 0
                i_j_same[p%K] += cnt;
        }
 
        for (int p = 0; p < K; p++)
        {
            int q = (K - p) % K; // Convert (0, K) to (0, 0)
            res += ((i_A[p] % MOD) * (j_B[q] % MOD)) % MOD;
            res -= i_j_same[p];
            res %= MOD;
        }
 
        res += MOD;
        res %= MOD;
 
        cout << "Case #" << i << ": " << res << endl;
    }
}
//////////////////////////////////////////////////////////////////////////

ll power(ll x,ll y,ll mod){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t%mod;
}

ll cta[N],cot[N];
ll ctb[N],rv[N];
int main(){
	int q; scanf("%d",&q);
	REP(aa,q){
		ll a,b,n,k;
		scanf("%lld%lld%lld%lld",&a,&b,&n,&k);
	//	a=b=1000000,n=INF,k=100000;
		REP(i,k) rv[i]=0;
		REP(i,k){
			cot[i]=(n/k+(n%k>=i))%mod;
			if(i==0) cot[i]--;
			cta[i]=power(i,a,k);
			ctb[i]=power(i,b,k);
			rv[ctb[i]]=(rv[ctb[i]]+cot[i])%mod;
		}
		ll sum=0;
		REP(i,k){
			sum=(sum+cot[i]*rv[(k-cta[i])%k]%mod)%mod;
			if((cta[i]+ctb[i])%k==0){
				sum=(sum-cot[i])%mod;
			}
		}
		sum=(sum%mod+mod)%mod;
		printf("Case #%d: %lld\n",aa+1,sum);
	}
	return 0;
}