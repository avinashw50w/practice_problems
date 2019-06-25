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

/* You are given a rooted Tree of N ( 10^5 nodes ). There would be M updates (10^5) to the tree which are of the form

Add x y – Add y to node x .

AddUp x y – Add y to x , parent of x , parent of parent of x  uptill Root.

After that there will be Q queries ( 10^5) queries where you will either be asked to give the value of a node 
or the sum of subtree rooted at that node.

Hint : Lazy Update as queries have no update value query.*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))

typedef int64_t ll;

const int mod = (int)1e9 + 7;
const int SZ = 100000 + 5;


struct node {

	ll value, upval, total;

} tree[SZ];

int par[SZ];


int main() {
	int test; cin>>test;

	int N, M, Q;

	while(test--) {

		cin >> N >> M >> Q;

		rep(i,1,N+1) {

			cin>>par[i];

			tree[i].value = tree[i].upval = tree[i].total = 0LL;

		}

		ll X, Y;

		string type;

		while(M--) {

			cin >> type >> X >> Y;

			if(type == "ADD") 
				tree[X].value = (tree[X].value + Y) % mod;

			else 
				tree[X].upval = (tree[X].upval + Y) % mod;

		}

		for(int i=N; i>=1; --i) {

			tree[i].value = (tree[i].value + tree[i].upval) % mod;

			tree[i].total = (tree[i].total + tree[i].value) % mod;

			tree[par[i]].upval = (tree[par[i]].upval + tree[i].upval) % mod;

			tree[par[i]].total = (tree[par[i]].total + tree[i].total) % mod;
		}

		while(Q--) {

			cin >> type >> X;

			if(type == "VAL") cout << tree[X].value << endl;

			else cout << tree[X].total << endl;
		}
	}
}