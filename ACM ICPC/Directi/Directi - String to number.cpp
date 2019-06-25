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

vector<int> G[256];
int vis[256];

int dfs(int u) {
	int cycle = 0;

	int ret = -1;

	vis[u] = 1;

	for(auto i: G[u]) {
		if(!vis[i]) {

			if(i>='0' and i<='9') { ret = i; break; }

			else return dfs(i);
		}

		else {
			cycle = 1;
			break;
		}
	}

	if(cycle) return 0; 
	else return ret;
}

void solve(string &s) {

	int ret = 0;
	string ans = "";

	rep(i,0,s.size()) { 
		if(G[int(s[i])].empty()) {
			cout << -1 << endl;
			return;
		}
	}

	rep(i,0,s.size()) {

		memset(vis, 0, sizeof(vis));

		ret = dfs(int(s[i])); 

		if(ret >= '0' and ret <= '9') { 
			to_string(ret-'0'); 
			ans += ret; 
			continue; 
		}

		else if(ret == 0) { ans += "0"; continue; }

		else if(ret == -1) break;

	}

	if(ret == -1) cout << -1;
	else cout << ans;
	cout << endl;
}

int main() {

	int t;
	cin>>t;

	rep(test, 1, t+1) {

		cout<<"#"<<test<<endl;

		int n;

		cin>>n;

		char a, b;

		rep(i,0,n) {
			cin>>a>>b;
			G[int(a)].push_back(int(b));
		}

		int k; cin>>k;

		while(k--) {
			string s;
			cin>>s;
			solve(s);
		}
	}
}