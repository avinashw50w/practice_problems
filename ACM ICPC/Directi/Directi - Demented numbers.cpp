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

typedef long long ll;

int digitSum(ll x) {
	int ret = 0, p;
	while(x) {
		p = x%10;
		ret += p*p;
		x /= 10;
	}
	return ret;
}

int demented(ll x) {

	int a[1000] = {};

	int hit = 1;

	while(true) {

		int tmp = digitSum(x);

		if(!a[tmp]) {
			
			a[tmp] = 1;

			x = tmp;
		}
		
		else {

			hit = 0;
			break;
		}

		if(x == 1) break;
	}

	return hit? 1 : 0;
}

int main() {

	int t; cin>>t;
	
	int A, B;

	while(t--) {

		cin >> A >> B;

		int ans = 0;

		for(ll i=A; i<=B; ++i) if(demented(i)) ans++;

		cout << ans << endl;
	}
}