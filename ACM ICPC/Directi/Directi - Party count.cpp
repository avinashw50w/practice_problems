#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> v;

int n;

bool comp(const pii& a, const pii& b) { return a.second < b.second; }

int main() {

	int t; cin>>t;

	while(t--) {

		cin>>n;

		int a, b;

		for(int i=0;i<n;++i) {
			cin>>a>>b;
			v.push_back({a, b});
		}

		sort(v.begin(), v.end(), comp);

		int cnt = 0, ans = 0;

		for(int i=0; i<v.size(); ++i) {

			int cnt = 1;

			for(int j=i+1; j<v.size(); ++j) {
				
				if(v[j].first < v[i].second) cnt++;
			}

			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}
}