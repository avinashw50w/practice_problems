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

const int maxx = 10101;
const int maxn = 101;

int W[maxn], color[maxn];
bool dp[maxn][maxx];

vector<int> v[maxn];

int main() {
	int t; cin>>t;

	int N, M, X;

	while(t--) {
		
		cin >> N >> M >> X;

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		rep(i,0,M+1) v[i].clear();

		rep(i,1,N+1) cin >> W[i];

		rep(i,1,N+1) {
			
			cin >> color[i];
			v[color[i]].push_back(W[i]);
		}

		rep(i,1,M+1) {
			
			int sz = v[i].size();
			
			rep(j,0,sz) {
				
				for(int k=0; k+v[i][j]<=X; ++k)
				
					dp[i][k+v[i][j]] |= dp[i-1][k];
				
			}
		}

		int ans = -1;

		for(int k=0; k<=X;++k) 
			if(dp[M][k])
				ans = X-k;

		cout << ans << endl;
	}

	return 0;
}