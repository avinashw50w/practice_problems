#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    /* 1^2 = 3(2*2-1), 3^4 = 7(2*2*2-1), 7^8 = 15(2*2*2*2-1) ....
       all other combinations give 1, 3 or 7
     */
    int t; cin >> t;
   
    while (t--) {
        ll n; cin >> n;
        if (n == 1) {
            cout << "2\n";
            continue;
        }

        int t = n;
        while (n&1) {
            n >>= 1;
        }

        if (n != 0) {
            cout << "-1\n";
        } else {
            cout << (t/2) << "\n";
        }
    }
}