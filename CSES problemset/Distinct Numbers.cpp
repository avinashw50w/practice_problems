/*You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input

The first input line has an integer n: the number of values.

The second line has n integers x1,x2,…,xn.

Output

Print one integers: the number of distinct values.

INTERSTING OBSERVATION: set worked, but unordered_set gave TLE
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    set<int> st;
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; ++i) cin >> x, st.insert(x);
    cout << st.size() << "\n";
}