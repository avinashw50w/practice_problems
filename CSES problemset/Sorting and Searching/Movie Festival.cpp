/*In a movie festival n movies will be shown. You know the starting and ending time of each 
movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1≤n≤2⋅105
1≤a<b≤109

IDEA: sort the movie timings based on end time.
NOTE: when we want to find the maximum no of intervals, then sort by end time
and for minimum no of intervals sort by start time.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	pair<int, int> p[n];
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		p[i] = {s, e};
	}

	sort(p, p + n, [](auto & a, auto & b) { return a.second < b.second; });

	int ans = 1, last = p[0].second;
	for (int i = 1; i < n; ++i) {
		if (last <= p[i].first) ans++, last = p[i].second;
	}
	cout << ans << "\n";
}