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
const int MAXN = 100000;
/*========================================================================================*/
int f[101];
int main() {
	caset{
		int n,q; 
		si(n); si(q);
		mset(f,1);
		while(q--){
			char c; int x;
			cin>>c>>x;
			if(c=='-') f[x] = f[n-x+1] = 0;
			else if(c='?'){
				int cnt = 0;
				rep(i,1,n+1){
					if(f[i]) cnt++;
					if(cnt == x){
						printf("%d\n", i);
						break;
					}
				}
			}
		}
	}
	return 0;
}
