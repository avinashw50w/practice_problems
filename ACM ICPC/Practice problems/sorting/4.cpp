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
typedef long long int ll;typedef vector<int> vi;typedef pair<int,int> pii;
#define MAXN 200+2
/*========================================================================================*/

int a[MAXN][MAXN], r[MAXN], c[MAXN], sr[404], sc[404];
int main() {
	caset{
		int n,k,cnt; si(n);si(k);
		rep(i,0,n){
			rep(j,0,n){
				si(a[i][j]);
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
		memset(sr,0,sizeof sr);
		memset(sc,0,sizeof sc);
 
		rep(i,1,k+1){
			sort(r,r+n);
			sort(c,c+n);
			sr[i] = sr[i-1]+r[0];
			r[0] += n;
			sc[i] = sc[i-1]+c[0];
			c[0] += n;
		}
		ll ans = (1<<40);
		rep(i,0,k) ans = min(ans, (ll)(sr[i]+sc[k-i])+(ll)i*(k-i));
		printf("%lld\n", ans);
	}
	return 0;
}
