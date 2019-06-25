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


int main() {
	int t; cin>>t;

	while(t--) {

		int n, m;
		cin>>n>>m;

		set<int> st[3];

		while(m--) {
			vector<int> v;

			int a; cin>>a;
			a <<= 1;

			while(a--) {
				int x; cin>>x;
				v.push_back(x);
			}

			char c; cin>>c;

			if(c == '<') { rep(i,0,v.size()) if(st[1].find(v[i]) == st[1].end()) st[1].insert(v[i]); }

			else if(c == '>') { rep(i,0,v.size()) if(st[2].find(v[i]) == st[2].end()) st[2].insert(v[i]); }

			else if(c == '=')  { rep(i,0,v.size()) if(st[0].find(v[i]) == st[0].end()) st[0].insert(v[i]); }

		}

		int ans = 0;
		for(set<int>::iterator i=st[0].begin(); i!=st[0].end();++i) {
			
			set<int>::iterator it = st[1].find(*i);
			if(it != st[1].end()) st[1].erase(it);

			it = st[2].find(*i);
			if(it != st[2].end()) st[2].erase(it);
		}

		if(st[1].size() == 1) { ans = *st[1].begin(); }

		else if(st[2].size() == 1) { ans = *st[1].begin(); }

		else ans = 0;

		cout << ans << endl;
	}
}