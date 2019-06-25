#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, A, B, C, D;
    int R, R1;
    cin >> T;

    while(T--) {
        cin >> A >> B >> C >> D;

        int P = __gcd(C, D);

        R = abs(A-B) % P;
        R1 = P - R;

        cout << min(R, R1) << endl;
    }
}