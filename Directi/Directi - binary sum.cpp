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
#define BOOST ios_base::sync_with_stdio(0)

typedef int64_t ll;

int n;
ll ans, a[555];

bool isleaf(int x) {
	return ((n+1)/2 <= x and x <= n);
}

ll solve(int node) {
	if(node<1 || node>n) return 0;

	if(isleaf(node)) return a[node];

	ll ls = solve(node<<1);
	ll rs = solve((node<<1)|1);

	if(!isleaf(node)) {

		ans = max(ans, ls + rs + a[node]);

		return max(ls, rs) + a[node];
	}
}

int main() {
	int t; cin>>t;

	while(t--) {

		cin>>n;

		rep(i,1,n+1) cin>>a[i];

		ans = -(ll)1e9;

		solve(1);

		cout << ans << endl;
	}
}