#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		
		int n; cin>>n;
		int P[n+1];

		for(int i=1; i<=n;++i) cin>>P[i];

		int ans = 0, cnt = 0;

		for(int i=1; i<=n; ++i) {
			int x = i;
			cnt = 1;
			while(P[x] != i) {
				x = P[x];
				cnt++;
			}
			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}
}