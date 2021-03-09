/*There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1,h2,…,hn: the price of each ticket.

The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.

IDEA: for each person, find the largest ticket price <= the person's price
here i used set<pair<int,int>> instead of set<int> because there can be tickets
with the same price. So it is working as a multiset
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	set<pair<int, int>> st;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		st.insert({x, i});
	}

	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		auto it = st.lower_bound({x + 1, 0});
		if (it == st.begin()) {
			cout << "-1\n";
		}
		else {
			--it;
			cout << (*it).first << "\n";
			st.erase(it);
		}
	}
}