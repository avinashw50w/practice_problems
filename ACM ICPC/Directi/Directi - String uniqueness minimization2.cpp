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

typedef int64_t ll;

int main() {
	int t, n, f1[26], f2[26], lim;
	string s1, s2;

	cin>>t;

	while(t--) {

		cin>>n;

		cin>>s1>>s2;

		lim = 1<<n;

		int ans = n;

		for(int mask = 0; mask < lim; ++mask) {

			memset(f1, 0, sizeof(f1));
			memset(f2, 0, sizeof(f2));

			for(int i = 0; i < n; ++i) {

				if(mask & (1<<i)) {

					f2[s1[i]-'a'] = 1;
					f1[s2[i]-'a'] = 1;
				}

				else {

					f1[s1[i]-'a'] = 1;
					f2[s2[i]-'a'] = 1;
				}
			}

			int cnt1 = 0, cnt2 = 0;

			rep(i,0,26) {
				
				if(f1[i]) cnt1++;
				if(f2[i]) cnt2++;
			}

			ans = min(ans, max(cnt1, cnt2));
		}

		cout << ans << endl;
	}
}