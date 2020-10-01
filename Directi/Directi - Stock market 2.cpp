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

ll a[1010];

int main() {

	int t; cin>>t;

	while(t--) {

		int N, K;
		cin>>N>>K;

		rep(i,1,N+1) cin>>a[i];

		int i = 1, buy_idx = 0, sell_idx = 0;

		ll profit = 0LL, ans = 0LL;

		while(i <= N) {

			while(i < N && (a[i+1] <= a[i])) i++;

			if(i==N) break; 

			if(buy_idx == 0) { 
				buy_idx = i; 
				profit = profit - a[i] - K; 
			}

			else {

				if(profit - a[i] - K < 0) 
					profit = profit - a[sell_idx] + K;

				else {

					buy_idx = i;
					profit = profit - a[i] - K;
				}
			}

			i++;

			while(i <= N && (a[i] >= a[i-1])) i++;

		//	profit = profit + a[i] - K;

			if(profit + a[i-1] - K < 0) 
				profit = profit + a[buy_idx] + K;

			else {
				
				sell_idx = i-1;
				profit = profit + a[i-1] - K;
			}

			ans = max(ans, profit);

		}

		cout << ans << endl;
	}
}