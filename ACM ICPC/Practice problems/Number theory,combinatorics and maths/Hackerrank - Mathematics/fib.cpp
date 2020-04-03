   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define si(o) scanf("%d",&(o))
#define sl(o) scanf("%lld",&(o))
#define ss(o) scanf("%s",(o))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
typedef long long int ll;typedef vector<ll> vi;typedef pair<int,int> pii;
const int MAXN = 100000;
const int mod = 1000000007;
/*========================================================================================*/
/* problem : F0 = A, F1 = B,  return Fn % (1e9+7) */

typedef vector<vi> vvi;

vvi mul(vvi a, vvi b){
	vvi res(2,vector<ll>(2,0));
	rep(i,0,2){
		rep(j,0,2){
			rep(k,0,2)
				res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%mod)%mod;
		}
	}
	return res;
}

vvi mpow(vvi a, ll n){
	vvi res {{1,0},{0,1}};
	while(n) {
		if(n&1) res = mul(res, a);
		a = mul(a,a);
		n >>= 1;
	}
	return res;
}

int main() {
	ll A,B,n;
	caset{
		cin>>A>>B>>n;
		vector<vi> a {{1,1},{1,0}};
		vvi g = mpow(a,n-1);
		printf("%lld\n", (A*g[0][1] + B*g[0][0])%mod);
	}
	return 0;
}
