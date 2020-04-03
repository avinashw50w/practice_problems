#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
 
vector<int> t_parent;
vi t_ord;
 
void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();
 
	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)g[i].size()-1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int N, L, R;
		scanf("%d%d%d", &N, &L, &R);
		vector<vi> g(N);
		vector<vpii> gw(N);
		rep(i, N-1) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b;
			g[a].push_back(b);
			g[b].push_back(a);
			gw[a].push_back(mp(b, c));
			gw[b].push_back(mp(a, c));
		}
		tree_getorder(g, 0);
		vector<int> pw(N, 0);
		reu(i, 1, N) each(j, gw[i]) if(j->first == t_parent[i])
			pw[i] = j->second;
		vector<int> costs;
		reu(i, 1, N)
			costs.push_back(pw[i]);
		sort(all(costs));
		vector<vector<int> > paths(N, vector<int>(R+1));
		int xl = 0, xu = (int)costs.size();
		while(xu - xl > 0) {
			int xmid = (xl + xu) / 2;
			int midw = costs[xmid];
			rep(i, N) {
				fill(all(paths[i]), -1);
				paths[i][0] = 0;
			}
			bool ok = false;
			for(int ix = N-1; ix > 0; -- ix) {
				int i = t_ord[ix], p = t_parent[i];
				int *v = &paths[i][0], *w = &paths[p][0];
				bool b = pw[i] <= midw;
				rer(k, 1, R) {
					int t = v[k - 1];
					if(t < 0) break;
					t += b;
					rer(l, max(0, L - k), R - k) {
						int u = w[l];
						if(u < 0) break;
						ok |= (t + u) * 2 > k + l;
					}
				}
				rep(k, R) {
					int t = v[k];
					if(t < 0) break;
					t += b;
					amax(w[k + 1], t);
				}
				if(ok) break;
			}
			if(ok)
				xu = xmid;
			else
				xl = xmid + 1;
		}
		int ans = xu == costs.size() ? -1 : costs[xu];
		printf("%d\n", ans);
	}
	return 0;
}
