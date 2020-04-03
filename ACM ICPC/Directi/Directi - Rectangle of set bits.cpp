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

const int oo = (int)1e9;
typedef long long ll;

int main() {
	int t; cin>>t;
	while(t--) {

		int N, M;
		cin >> N >> M;

		int row[4][2];
		
		rep(i,1,4) {
			row[i][0] = oo;
			row[i][1] = -oo;
		}

		rep(i,0,M) {
			int x, l, r;
			cin>>x>>l>>r;

			row[x][0] = min(row[x][0], l);
			row[x][1] = max(row[x][1], r);
		}
//cout<<row[3][0]<<" "<<row[3][1]<<endl;
		ll ans = 0;
		rep(i,1,4){

			if(row[i][0] == oo) continue;

			int l = row[i][0]; 
			int r = row[i][1];

			for(int j=i; j<=3; ++j){

				if(row[j][0] == oo) break;

				l = max(l, row[j][0]); 
				r = min(r, row[j][1]);

				if(l<=r) {
					ll tmp = (j-i+1) * (r-l+1); 

					ans = max(ans, tmp); //cout << i<<","<<j<<":"<<tmp<<endl;
				}
			}
		}

		for(int i=3;i>=1;--i){
			if(row[i][0] == oo) continue;

			int l = row[i][0]; 
			int r = row[i][1];

			for(int j=i; j>=1;--j) {
				if(row[j][0] == oo) break;

				l = max(l, row[j][0]); 
				r = min(r, row[j][1]);

				if(l<=r) {
					ll tmp = (j-i+1) * (r-l+1); 

					ans = max(ans, tmp); //cout << i<<","<<j<<":"<<tmp<<endl;
				}
			}

		}
		

		cout << ans << endl;
	}
	
}
