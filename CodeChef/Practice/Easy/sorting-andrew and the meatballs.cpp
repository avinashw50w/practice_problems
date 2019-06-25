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
#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

typedef long long int ll;

inline ll inp(){ ll n=0; register int c=getchar_unlocked(); while(c<'0' || c>'9') c=getchar_unlocked();
while(c>='0' && c<='9'){n = (n<<3) + (n<<1) + c-48; c=getchar_unlocked();} return n;}

char _str[19];
inline void pout(ll _x){ register int _i=0;ll _tmp=(_x); do{*(_str + _i++)=_tmp % 10 + 48;_tmp /= 10;}     
while (_tmp != 0);for (_i--; _i >= 0; _i--) putchar_unlocked(*(_str + _i)); }	     


int main() {
	int n,m;
	ll a[10];
	int t=inp();
	while(t--){
		n=inp();m=inp();
		rep(i,0,n) a[i]=inp();
		sort(a,a+n,greater<ll>());
		ll sum=0, i=0;
		for(i=0;i<n;++i) { sum += a[i];  if(sum >= m) break; }
		if(sum<m) printf("-1\n");
		else printf("%d\n", i);
	}
	return 0;
}
