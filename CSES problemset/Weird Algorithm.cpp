/*Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm
divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The
algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
3→10→5→16→8→4→2→1

Your task is to simulate the execution of the algorithm for a given value of n.

Input

The only input line contains an integer n.

Output

Print a line that contains all values of n during the algorithm.

Constraints
1≤n≤106*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    while (1) {
        cout << n << " ";
        if (n == 1) break;
        if (n & 1LL) n = n * 3LL + 1;
        else n >>= 1LL;
    }
}