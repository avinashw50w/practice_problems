   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define si(o) scanf("%d",&(o))
#define sl(o) scanf("%lld",&(o))
#define ss(o) scanf("%s",(o))
#define mset(a,o) memset((a),(o),sizeof(a))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
typedef long long int ll;typedef vector<int> vi;typedef pair<int,int> pii;
#define oo 0x3f3f3f3f
const int mod = 1000000007;
const int MAXN = 100000+9;
/*========================================================================================*/
int n,m;

int main() {
	caset{
		string s[11];
		si(n);si(m);
		rep(i,0,n) cin>>s[i];
		int ans = 0, cnt;
		rep(i,0,m){
			cnt = -1;
			rep(j,0,n){
				if(s[j][i]=='1') cnt++;
			}
			ans += cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
