/*Tambourine has prepared a fitness program so that she can become more fit! The program is made of N sessions. During the i-th session, Tambourine will exercise for Mi minutes. The number of minutes she exercises in each session are strictly increasing.

The difficulty of her fitness program is equal to the maximum difference in the number of minutes between any two consecutive training sessions.

To make her program less difficult, Tambourine has decided to add up to K additional training sessions to her fitness program. She can add these sessions anywhere in her fitness program, and exercise any positive integer number of minutes in each of them. After the additional training session are added, the number of minutes she exercises in each session must still be strictly increasing. What is the minimum difficulty possible?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the two integers N and K. The second line contains N integers, the i-th of these is Mi, the number of minutes she will exercise in the i-th session.*/

#include <bits/stdc++.h>
using namespace std;

int a[100001];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 1, r = a[n-1] - a[0];

    while (l < r) {
        int mid = (l+r) >> 1;
        int k2 = 0;
        for (int i = 1; i < n; ++i) {
            int diff = a[i] - a[i-1];
            k2 += (diff-1)/mid;
        }
        if (k2 <= k) r = mid;
        else l = mid+1; 
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