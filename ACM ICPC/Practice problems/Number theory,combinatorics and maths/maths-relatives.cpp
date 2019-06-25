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
/*========================================================================================*/
int phi(int n){
	int ans = n;
	for(ll i=2; i*i<=n;++i){
		if(n%i == 0) ans -= ans/i;
		while(n%i == 0) n /= i;
	}
	if(n>1) ans -= ans/n;
	return ans;
}

int main() {
	int n;
	if(n == 1) {
		cout << 0 << endl; continue;
	}
	while(cin>>n and n){
		cout << phi(n) << endl;
	}
	return 0;
}
