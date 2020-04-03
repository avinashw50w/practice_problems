#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000+4;

multiset<int> st;

int w[MAXN], par[MAXN];
int N, Q;

int root(int x) {
	return par[x] = (x==par[x]? x: root(par[x]));
}

void input() {
	cin>>N>>Q;

	for(int i=1;i<=N;++i) {
		cin>>w[i];
		st.insert(w[i]);
		par[i] = i;
	}
}

void solve() {
	int a, b;

	while(Q--) {
		cin >> a >> b;
		
		a = root(a);
		b = root(b);

		if(a != b) {
			st.erase(st.find(w[a]));
			st.erase(st.find(w[b]));

			w[a] += w[b];
			w[b] = 0;

			st.insert(w[a]);

			par[b] = a;
		}

		cout << *st.begin() << endl;
	}
}

int main() {
	
	input();

	solve();
}