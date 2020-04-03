/*
	               _            .                                 .x+=:.
	              u            @88>                              z`    ^%    .uef^"
	             88Nu.   u.    %8P      u.    u.                    .   <k :d88E
	      u     '88888.o888c    .     x@88k u@88c.       u        .@8Ned8" `888E
	   us888u.   ^8888  8888  .@88u  ^"8888""8888"    us888u.   .@^%8888"   888E .z8k
	.@88 "8888"   8888  8888 ''888E`   8888  888R  .@88 "8888" x88:  `)8b.  888E~?888L
	9888  9888    8888  8888   888E    8888  888R  9888  9888  8888N=*8888  888E  888E
	9888  9888    8888  8888   888E    8888  888R  9888  9888   %8"    R88  888E  888E
	9888  9888   .8888b.888P   888E    8888  888R  9888  9888    @8Wou 9%   888E  888E
	9888  9888    ^Y8888*""    888&   "*88*" 8888" 9888  9888  .888888P`    888E  888E
	"888*""888"     `Y"        R888"    ""   'Y"   "888*""888" `   ^"F     m888N= 888>
	 ^Y"   ^Y'                  ""                  ^Y"   ^Y'               `Y"   888
	                                                                             J88"
	                                                                             @%
	                                                                           :"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))
#define caset int __T,case_n=1;cin>>__T;while(__T--)
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define runtime printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);

#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{
    template<typename T>debugger& operator ,(const T& v) { cerr<<v<<" ";return *this; }
}dbg;

typedef long long int ll; typedef vector<int> vi;
typedef pair<int,int> pii; typedef vector<pii> vii;
typedef map<int,int> mii;

#define oo 0x3f3f3f3f
#define eps 1e-9
const int mod = 1000000007;
const int MAXN = 100000+9;


int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t, n;
	string s[1001];

	cin>>t;
	while(t--) {
		cin>>n;
	
		rep(i, 0, n) cin>>s[i];

		int rayX[n][n], rayY[n][n];

		rep(i, 0, n) {
			per(j, n-1, 0) {
				if(s[i][j] == '.')
					rayX[i][j] = j != n-1 ? rayX[i][j+1]: 1;
				else rayX[i][j] = 0;

				if(s[j][i] == '.') 
					rayY[j][i] = j != n-1 ? rayY[j+1][i]: 1;
				else rayY[j][i] = 0;
			}
		}

		int cnt = 0;

		rep(i, 0, n) rep(j, 0, n) {
			if(rayX[i][j] == 1 and rayY[i][j] == 1) cnt++;
		}

		cout << cnt << endl;
	}
	return 0;
}
