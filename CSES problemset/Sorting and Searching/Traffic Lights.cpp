/*There is a street of length x whose positions are numbered 0,1,...,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
Input
The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
Then, the next line contains n integers p_1,p_2,...,p_n: the position of each set of traffic lights. Each position is distinct.
Output
Print the length of the longest passage without traffic lights after each addition.
Constraints

1 <= x <= 10^9
1 <= n <= 2 \cdot 10^5
0 < p_i < x

Example
Input:
8 3
3 6 2

Output:
5 3 3*/

/*IDEA: we maintain 2 things:
- the position of traffic lights in a set
- the length of path between traffic lights in a map

 while adding traffic lights one by one
- find the position of traffic lights in the set.
- remove the previous path length from the map
- insert the new path lengths in the map
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n, p;
    cin >> x >> n;
    map<int, int> mp;
    mp[x] = 1;
    set<int> st;
    st.insert(0);
    st.insert(x);

    for (int i = 0; i < n; ++i) {
        cin >> p;
        auto it = st.lower_bound(p);
        int r = *it;
        --it;
        int l = *it;
        --mp[r-l];
        if (!mp[r-l]) mp.erase(r-l);
        ++mp[r-p];
        ++mp[p-l];
        st.insert(p);

        cout << (--mp.end())->first << " ";
    }
}