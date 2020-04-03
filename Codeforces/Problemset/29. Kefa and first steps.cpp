#include <iostream>
using namespace std;

int main() {
	int n, a[(int)1e5+2]; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int cnt = 1, mx = 0;
	for (int i = 0; i < n-1; ++i)
		if (a[i] <= a[i+1]) cnt++, mx = max(mx, cnt);
		else cnt = 1;

	cout << mx << endl;
}