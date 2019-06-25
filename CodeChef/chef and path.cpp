/*
Chef has a tree (with N nodes, numbered from 1 to N) where each edge has some length.
The Chef length of a path is the median of the lengths of all edges along the path. More formally: if we put lengths of all edges from the path into an array 
and sort it, then the Chef length of this path is the median of this array (element in the middle of the sorted array, and if we have two elements in the 
middle of the array, then the median is the bigger one). For example, if the array equals {3, 7, 9}, then its median is 7, and if the array equals {1, 2, 3, 4},
 then the median is 3.
Now, Chef wants to find minimum Chef length among simple paths having at least L and at most R edges. Please help him accomplish this task.
Input

The first line of input contains an integer T denoting the number of test cases. Description of T test cases follows.
The first line for a test case contains three space-separated integers - N, L, R - denoting the number of nodes in a tree, and the limits on number of edges 
in any chosen path.
Each of next N - 1 lines contains three space-separated integers - a, b and c - describing an edge in the tree. This edge connects vertex a with vertex b and 
has length c.
Output

For each test case, output a single line containing the shortest Chef length amongst paths satisfying the given conditions. If there are no paths with at least
 L and at most R edges, output -1.
Constraints

1 = T = 5×104
2 = N = 105
2 = L = R = 50
1 = a, b = N
1 = c = 109
The sum of N over all the test cases in one file is at most 3×105
The given graph denotes a tree
Subtasks

Subtask 1 (27 points)
The sum of N over all the test cases in one file is at most 1000
Time Limit is 1 second
Subtask 2 (73 points)
Original constraints
Time Limit is 6 seconds
Example

Input:
2
6 2 3
1 3 3
1 2 1
2 4 1
2 5 2
3 6 2
5 3 4
1 2 3
2 3 1
3 4 4
4 5 2

Output:
1
2
Explanation

Test #1
Let's look at all correct simple paths:
1-3-6, lengths = {3, 2} => Chef length = 3
1-2-4, lengths = {1, 1} => Chef length = 1
1-2-5, lengths = {1, 2} => Chef length = 2
2-1-3, lengths = {1, 3} => Chef length = 3
2-1-3-6, lengths = {1, 3, 2} => Chef length = 2
4-2-5, lengths = {1, 2} => Chef length = 2
4-2-1-3, lengths = {1, 1, 3} => Chef length = 1
5-2-1-3, lengths = {2, 1, 3} => Chef length = 2
And the reverse of these paths. So, the smallest value we get is 1 and it is the answer.
Test #2
All correct paths:
1-2-3-4, lengths = {1, 3, 4} => Chef length = 3
2-3-4-5, lengths = {1, 2, 4} => Chef length = 2
1-2-3-4-5, lengths = {1, 2, 3, 4} => Chef length = 3
The shortest Chef length is 2.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
 
typedef long long LL;
LL MOD = 10000007;
 
int N = 1, L = 0, R = 0;
vector<pii> List[100001];
vector<int> nodes;
int dp[100001][55];
int nn = 0;
 
class RMQ
{
public:
	RMQ(int AA[]){
		Ar[0] = AA[0];
		dq.push_back({AA[0],0});
		st = 1;
		for(int i = 1; i <= R; ++i) A[i] = AA[i];
	};
	void do_it(int mx){
		for(int i = st; i <= mx; ++i){
			int el = (i <= R ? A[i] : -MOD);
			while(!dq.empty() && dq.back().X <= el) dq.pop_back();
			dq.push_back({el, i});
			while(!dq.empty() && dq.front().Y <= i - k) dq.pop_front();
			Ar[i] = dq.front().X;
		}
		st = mx;
	}
	inline int get_mx(int l, int r){
		if(l != 0) r = l+R-L;
		if(r >= st) do_it(r);
		return Ar[r];
	}
private:
	int Ar[105], st;
	int A[55];
	deque<pii> dq;
	int k = (R - L + 1);
};
 
inline void Unique(vector<int>& v){
	vector<int> tmp;
	sort(v.begin(), v.end());
	tmp.push_back(v.front());
	for(int i = 1; i < (int)v.size(); ++i){
		if(tmp.back() != v[i]) tmp.push_back(v[i]);
	}
	v = tmp;
	tmp.clear();
	return;
}
inline void init()
{
	vector<bool> vis(N+1, 0);
	queue<int> Q;
	Q.push(1);
	vis[1] = true;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		nodes.push_back(v);
		int par = -1, c = -1;
		for(int i = 0; i < (int)List[v].size(); ++i){
			c = List[v][i].first;
			if(!vis[c]) Q.push(c), vis[c] = true;
			else par = i;
		}
		if(par != -1) List[v].erase(List[v].begin() + par);
	}
	reverse(nodes.begin(), nodes.end());
	return ;
}
 
inline bool check(int Lim){
	for(int v : nodes){
		dp[v][0] = 0;
		for(int i = 1; i <= R; ++i) dp[v][i] = -MOD;
		if(List[v].size() == 0) continue;
		for(pii p : List[v]){
			RMQ rmq(dp[v]);
			int c = p.X;
			int w = p.Y;
			int cnt = (w <= Lim ? 1 : -1);
			for(int k = 0; k < R; ++k){
				cnt += dp[c][k];
				if(k+1 >= L && cnt > 0) return 1;
				int ll = max(0, L - k - 1);
				int rr = R - k - 1;
				assert(ll <= rr);
				if(cnt + rmq.get_mx(ll, rr) > 0) return 1;
				dp[v][k+1] = max(dp[v][k+1], cnt);
				cnt -= dp[c][k];
			}
		}
	}
	return 0;
}
 
int main()
{
	int T, u, v, w;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &N, &L, &R);
		nn = R + 1 + R - L + 1;
		vector<int> edgeWt;
		for(int i = 0; i < N-1; ++i){
			scanf("%d %d %d", &u, &v, &w);
			List[u].push_back({v, w});
			List[v].push_back({u, w});
			edgeWt.push_back(w);
		}
		Unique(edgeWt);
		init();
		int low = 0, high = (int)edgeWt.size()-1, mid = 0;
		while(high - low > 1){
			mid = (low + high) / 2;
			if(check(edgeWt[mid])) high = mid;
			else low = mid;
		}
		if(check(edgeWt[low])) mid = edgeWt[low];
		else if(check(edgeWt[high])) mid = edgeWt[high];
		else mid = -1;
		printf("%d\n",mid);
		for(int i = 1; i <= N; ++i) List[i].clear();
		nodes.clear();
	}
	return 0;
}
