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

int men[505][505], women[505][505];
int Rank[505][505];
int nextOption[505];
int curr[505];

int main() {
	int m, w;
	caset{
		mset(curr, 0);

		int N; cin>>N;

		rep(i,1,N+1) {
			cin >> w;
			rep(j,1,N+1)
				cin >> women[w][j];
		}

		rep(i,1,N+1) {
			cin >> m;
			rep(j,1,N+1)
				cin >> men[m][j];
		}

		rep(i,1,N+1) 
			rep(j,1,N+1)
				Rank[i][women[i][j]] = j;

		queue<int> FreeMen;

		rep(i,1,N+1) {
			FreeMen.push(i);
			nextOption[i] = 1;
		}

		while(!FreeMen.empty()) {
			m = FreeMen.front();
			w = men[m][nextOption[m]++];

			if(curr[w] == 0) {
				curr[w] = m;
				FreeMen.pop();
			}

			else if(Rank[w][m] < Rank[w][curr[w]]) {
				curr[w] = m;
				FreeMen.pop();
				FreeMen.push(curr[w]);
			}
		}
		
		rep(i,1,N+1) 
			cout << curr[i] <<" "<< i << "\n";
	}
	return 0;
}
