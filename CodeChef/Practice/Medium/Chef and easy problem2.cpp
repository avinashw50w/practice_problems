/*Roma gave Chef an array of intergers.
Chef wants to make all integers in the array equal to 1.
In a single operation, he can select a prime number p and a subset of the integers, 
and then divide all of the integers in the subset by p.
Chef can make this operation only if every integer in the selected subset is divisible by p.

Please help Chef to make all the integers in the array equal to 1 with minimum number of operations.

Input
The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the length of the array that Roma gave Chef.

The second line contains N space-separated integers A1, A2, ..., AN denoting the integers in the array.

Output
For each test case, output a single line containing one integer - 
the minimum number of operations needed to make all numbers equal to 1.

Constraints
Subtask 1 (10 points): T = 5, 1 ≤ N ≤ 105, 1 ≤ Ai ≤ 3
Subtask 2 (40 points): T = 3, 1 ≤ N ≤ 10, 1 ≤ Ai ≤ 106
Subtask 3 (50 points): T = 3, 1 ≤ N ≤ 105, 1 ≤ Ai ≤ 106
Example
Input:
1
3
1 2 4

Output:
2*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+2;
typedef long long ll;
int p[MAXN];
int f[MAXN];

void sieve() {
    for(int i = 1; i < MAXN; ++i)
        p[i] = i;
    for(ll i = 2; i*i < MAXN; i++) {
        if(p[i] == i) {
            
            for(int j = i+i; j < MAXN; j += i) p[j] = i;
        }
    }
}


int main() {
    sieve();
    int T; cin >> T;
    int N;

    while(T--) {
        cin >> N;
        memset(f, 0, sizeof(f));

        ll ans = 0;
        for(int i = 0; i < N; ++i) {
            int x;
            cin >> x;

            while(x > 1) {
                int d = p[x];
                int cnt = 0;

                while(x % d == 0) {
                    x /= d;
                    cnt++;
                }

                if(f[d] < cnt) {
                    ans += cnt - f[d];
                    f[d] = cnt;
                }
            }
        }

        cout << ans << endl;
    }
}