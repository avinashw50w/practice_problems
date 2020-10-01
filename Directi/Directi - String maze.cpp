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

int dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
int dy[] = {1, 0, 0, -1, 1, -1, 1, -1};

int n, m;

char grid[128][128];
bool vis[128][128];
char s[32];

bool dfs(int x, int y, int k) {

	if (k == strlen(s) - 1) return true;

	vis[x][y] = 1;

	rep(i, 0, 8) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!(nx >= 0 and nx<m and ny >= 0 and ny < n)) continue;

		if (vis[nx][ny]) continue;

		if (grid[nx][ny] == s[k + 1])
			if (dfs(nx, ny, k + 1)) return true;
	}

	vis[x][y] = 0;

	return false;
}

bool solve() {

	int flag = 0;

	rep(i, 0, m) {

		if (flag == 1) break;

		rep(j, 0, n) {

			if (grid[i][j] == s[0]) {

				memset(vis, 0, sizeof(vis));

				if (dfs(grid, vis, s, m, n, i, j, 0)) {

					flag = 1;
					break;
				}
			}
		}
	}

	if (flag) return true;

	else return false;
}

int main() {

	cin >> m >> n;

	rep(i, 0, m) rep(j, 0, n) scanf(" %c", &grid[i][j]);

	int q; cin >> q;

	while (q--) {

		scanf(" %s", s);

		if (solve(grid, m, n, s)) printf("%s: true\n", s);

		else printf("%s: false\n", s);
	}

}