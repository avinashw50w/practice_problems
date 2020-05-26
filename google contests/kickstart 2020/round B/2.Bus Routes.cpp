/*Bucket is planning to make a very long journey across the countryside by bus. Her journey consists of N bus routes, numbered from 1 to N in the order she must take them. The buses themselves are very fast, but do not run often. The i-th bus route only runs every Xi days.

More specifically, she can only take the i-th bus on day Xi, 2Xi, 3Xi and so on. Since the buses are very fast, she can take multiple buses on the same day.

Bucket must finish her journey by day D, but she would like to start the journey as late as possible. What is the latest day she could take the first bus, and still finish her journey by day D?

It is guaranteed that it is possible for Bucket to finish her journey by day D.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the two integers N and D. Then, another line follows containing N integers, the i-th one is Xi.*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll D, X[1001];

ll works(ll k) {
    for (int i = 0; i < N; ++i) {
        // if the ith bus does not run on kth day,
        // then the no of days we have to wait till the ith bus arrives is (X[i] - k % X[i])
        if (k % X[i] != 0) {
            k += X[i] - k % X[i];
        }
    }

    return k <= D;
}

void solve() {
    cin >> N >> D;
    for (int i = 0; i < N; ++i) cin >> X[i];

    // at worst we start at day 1 and at best start at day D
    ll l = 1, r = D;
    while (l < r) {
        ll mid = (l+r+1)/2;
        if (works(mid)) l = mid;
        else r = mid-1;
    }    

    cout << l << "\n";
}

int main() {

    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}

/////////////////////////////////////
// simple solution
void solve() {
    cin >> N >> D;
    for (int i = 0; i < N; ++i) cin >> X[i];

    for (int i = N-1; i >= 0; --i)
        D = D - D % X[i];

    cout << D << "\n";
}
////////////////////////////////////////////////////////
// Simple python solution:
import sys
readline = sys.stdin.readline
flush = sys.stdout.flush

T = int(readline())

for t in range(1, T+1):
    N, D = [int(_) for _ in readline().split()]
    X = [int(_) for _ in readline().split()]
    
    latest = D
    for i in range(N-1, -1, -1):
        latest = latest - (latest % X[i])
    
    print("Case #%d: %d" % (t, latest))

