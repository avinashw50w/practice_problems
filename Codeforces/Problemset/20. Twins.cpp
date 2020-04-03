/* Given a list of coins, split the coins into two groups such that the sum of coins in group 1 
is strictly larger than the sum of coins in group 2. Find the min no of coins that should be taken in group 1

inputCopy
2
3 3
outputCopy
2
inputCopy
3
2 1 2
outputCopy
2*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[101], n; cin >> n;
	int sum = 0, psum = 0, ans = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
	sum >>= 1;
	sort(a, a+n);
	for (int i = n-1; i >= 0; --i) {
		if (psum > sum) break;
		psum += a[i];
		ans++;
	} 

	cout << ans << endl;
}