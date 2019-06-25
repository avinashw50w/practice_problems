   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define si(o) scanf("%d",&(o))
#define ss(o) scanf("%s",(o))
#define mset(a,o) memset((a),(o),sizeof(a))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
typedef long long int ll;typedef vector<int> vi;typedef pair<int,int> pii;
#define oo 0x3f3f3f3f
const int mod = 1000000007;
const int MAXN = 100000;
/*========================================================================================*/
int n,m,x;
string s;
int main() {
	caset{
		si(n); si(m);
		priority_queue<int> a;
		priority_queue<int,vi,greater<int>> b;
		rep(i,0,n) {
			si(x);
			a.push(x);
		}
		rep(i,0,m){
			si(x);
			b.push(x);
		}
		cin>>s;
		int sum = 0, ans = 0;
		rep(i,0,n+m){
			if(s[i] == '+'){
				if(!a.empty()){
					sum += a.top();
					a.pop();
				}
			}
			else{
				if(!b.empty()){
					if(sum - b.top() < 0) ans++;
					else sum -= b.top();
					b.pop();
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
