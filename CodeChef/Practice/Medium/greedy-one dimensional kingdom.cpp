/*N one dimensional kingdoms are represented as intervals of the form [ai , bi] on the real line.
A kingdom of the form [L, R] can be destroyed completely by placing a bomb at a point x on the real line if L
≤ x ≤ R.

Your task is to determine minimum number of bombs required to destroy all the one dimensional kingdoms.

Input

First line of the input contains T denoting number of test cases.
For each test case, first line contains N denoting the number of one dimensional kingdoms.
For each next N lines, each line contains two space separated integers ai and bi.
Output

For each test case , output an integer denoting the minimum number of bombs required.*/

bool comp(const pii& a, const pii& b) { return a.second<b.second; }
int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	BOOST;
	int n, a, b;
	caset{
		cin>>n;
		vector<pii> v;
		rep(i,0,n){
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
		sort(all(v), comp);
		int j=0, cnt = 1;
		rep(i,1,n){
			if(v[j].second < v[i].first) { cnt++; j = i; }
		}
		cout << cnt << "\n";
	}
	return 0;
}
