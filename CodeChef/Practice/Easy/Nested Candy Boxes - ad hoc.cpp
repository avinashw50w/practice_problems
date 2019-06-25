#include <iostream>
using namespace std;

typedef long long ll;

ll a[30000 + 5];

int main() {
	ll n, m, x;

	cin >> n >> m;

	ll totalLeaf = 0;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ll  ans;
	for(int i = 0; i < m; ++i) {
		cin >> x;
		int last = n-1;
		ans = 0;

		while(x/a[last]) {

			ll rem = x/a[last] + ((x % a[last]) != 0);
			ans += rem;
			x = rem;
			last--;
		}

		ans++;

		if(ans < n) ans = n;

		cout << ans << endl;
	}
}