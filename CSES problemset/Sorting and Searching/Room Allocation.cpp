/*There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

Input

The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

Output

Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k. You can print any valid solution.

Constraints
1≤n≤2⋅105
1≤a≤b≤109
Example

Input:
3
1 2
2 4
4 4

Output:
2
1 2 1*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

array<int, 3> a[maxn];
int ans[maxn];

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][1] >> a[i][0];
		a[i][2] = i;
	}
	// sort based on end time
	sort(a, a + n);
	// st will store the pair { end time, assigned room # }
	set<array<int, 2>> st;

	for (int i = 0; i < n; ++i) {
		// find any previous interval such that its end time >= curr start time
		// NOTE a[i][1] is the start time here
		auto it = st.lower_bound({a[i][1]});
		if (it != st.begin()) {
			--it;
			ans[a[i][2]] = (*it)[1];
			st.erase(it);
		}
		else
			ans[a[i][2]] = st.size();
		st.insert({ a[i][0], ans[a[i][2]] });
	}

	cout << st.size() << "\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << " ";
	}
}