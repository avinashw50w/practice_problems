   //*+++++++++++++++++++++++++++++++++++++++++*//
  //		   ~~~~~ @VIN@SH ~~~~~             //
 //           ~~~~IIEST SHIBPUR~~~~           //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
#define endl '\n'
#define oo  0x3f3f3f3f
#define mod 1000000007
#define mp  make_pair
#define mt  make_tuple
#define pb  emplace_back
#define ll  long long int
#define ull long long unsigned int
#define SZ(X) ((int)(X).size())
#define RS(X) scanf("%s",(X))
#define RI(X) cin>>(X)
#define RII(X,Y) cin>>(X)>>(Y)
#define RIII(X,Y,Z) cin>>(X)>>(Y)>>(Z)
#define DRI(X) int X; cin>>(X)
#define DRII(X,Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X,Y,Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define FILL(X,n) memset(X,n,sizeof X)
#define ALL(X) (X).begin(),(X).end()
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define REP(i,a,b) for(int i=a;i<b;++i)
#define PER(i,b,a) for(int i=b;i>=a;i--)
#define FORE(i,X) for(auto &i:(X))
#define CASET  int __T,case_n=1; cin>>__T; while(__T--)
#define runtime printf("\nRunning time:%.2f\n",(double)clock()/CLOCKS_PER_SEC);
#define BOOST ios_base::sync_with_stdio(0);
#define gc getchar_unlocked 
const ll inf = (1LL<<60);
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;
inline ll input(){register ll n=0;int s=1;char c=gc();if(c=='-'){s=-1;c=gc();}while(c>='0'&&c<='9'){n=(n<<3)+(n<<1)+(c-48);c=gc();}return n*s;}

int fun(int n){
	int res = 0;
	if(n>=5) res += n/5, n %= 5;
	if(n>=2) res += n/2, n %= 2;
	res += n;
	return res;
}
int main(){
	BOOST;
	CASET{
		DRI(n);
		int a[n+1];
		int mine = oo;
		REP(i,0,n) RI(a[i]);
	 	mine = *min_element(a,a+n);
		ll s[6];
		REP(i,0,6){
			s[i] = 0;
			REP(j,0,n){
				int diff = abs(a[j] - (mine-i));
				s[i] += fun(diff);
			}
		}
		cout << *min_element(s,s+6) << endl;
	}
	return 0;
}
