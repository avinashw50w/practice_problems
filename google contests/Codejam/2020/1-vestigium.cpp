/*Problem
Given an NxN matrix, containing numbers from 1 to N.
Find its trace(sum of diagonal elements), number of bad rows and bad colums. 
A row or column is bad if that row or column contains duplicate elements.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each starts with a line containing a single integer N: the size of the matrix to explore. Then, N lines follow. The i-th of these lines contains N integers Mi,1, Mi,2 ..., Mi,N. Mi,j is the integer in the i-th row and j-th column of the matrix.

Output
For each test case, output one line containing Case #x: k r c, where x is the test case number (starting from 1), k is the trace of the matrix, r is the number of rows of the matrix that contain repeated elements, and c is the number of columns of the matrix that contain repeated elements.

Limits
Test set 1 (Visible Verdict)
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
2 ≤ N ≤ 100.
1 ≤ Mi,j ≤ N, for all i, j.

Input 
3
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
4
2 2 2 2
2 3 2 3
2 2 2 3
2 2 2 2
3
2 1 3
1 3 2
1 2 3

Output 
Case #1: 4 0 0
Case #2: 9 4 4
Case #3: 8 0 2*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

void solve() {
    int n; cin >> n;
    int a[n+1][n+1];
    vector<set<int>> row(n), col(n);

    ll trace = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >> a[i][j];
            if (i == j) trace += a[i][i];
            row[i].insert(a[i][j]);
            col[j].insert(a[i][j]);
        }
    }
    int bad_rows = 0, bad_cols = 0;
    rep(i,0,n) {
        if (row[i].size() != n) bad_rows++;
        if (col[i].size() != n) bad_cols++;
    }

    printf("%lld %d %d\n", trace, bad_rows, bad_cols);
}

int main() {
    int t, caset = 0; cin >> t;
    while (t--) {
        printf("Case #%d: ", ++caset);
        solve();
    }
}
