/*In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members, who will be all attending the festival.
You know the starting and ending time of each movie. What is the maximum total number of movies the club members can watch entirely if they act optimally?
Input
The first input line has two integers n and k: the number of movies and club members.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending time of a movie.
Output
Print one integer: the maximum total number of movies.
Constraints

1 <= k <= n <= 2 \cdot 10^5
1 <= a < b <= 10^9

Example
Input:
5 2
1 5
8 10
3 6
2 5
6 9

Output:
4*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<array<int,2>> a(n);

    for (int i = 0; i < n; i++)  // read start time, end time
        cin >> a[i][1] >> a[i][0];

    sort(begin(a), end(a));  // sort by end time

    set<array<int,2>> st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = st.upper_bound({a[i][1]});
        if (it != st.begin()) {
            --it;
            st.erase(it);
        }
        if (st.size() < k) {
            st.insert({a[i][0], i});
            ans++;
        }
    }
    cout << ans;
}

////////////////////////////////////////////////////////////////
int main() {
    int n, k;
    cin >> n >> k;
    vector<array<int,2>> a(n);
    for (int i = 0; i < n; i++)  // read start time, end time
        cin >> a[i][1] >> a[i][0];
    sort(begin(a), end(a));  // sort by end time

    int maxMovies = 0;
    multiset<int> end_times;  // times when members will finish watching movies
    for (int i = 0; i < k; ++i) {
        end_times.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = end_times.upper_bound(a[i].second);
        if (it == begin(end_times)) continue;
        // assign movie to be watched by member in multiset who finishes at time
        // *prev(it)
        end_times.erase(--it);
        // member now finishes watching at time v[i].first
        end_times.insert(a[i].first);
        ++maxMovies;
    }

    cout << maxMovies;
}