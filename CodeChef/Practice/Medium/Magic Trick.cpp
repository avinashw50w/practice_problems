/*Vidhi went to a magic show last week where she was astounded by a 
magic trick performed by the great Mandwarf, the brown. His trick was as follows :

Ask a volunteer from the audience to write down a list L of N integers.
Ask another volunteer from the audience to provide three integers A, B, C
Ask another volunteer from the audience to provide N length string called S where each letter is either 'R', 'A' or 'M'
Close his eyes for a split second and give the output of The Ancient Algorithm on this input.
We all know that The Ancient Algorithm is as follows :

for i from 1 to N do 

    if ith letter of S is 'R'
        reverse L[i...N]
    else if ith letter of S is 'A'
        add A to all numbers of L[i..N].
    else if ith letter of S is 'M'
        multiply B to all numbers of L[i..N].

    for all number in L[i..N], module them by C.

    announce L[i] out loud

end

Vidhi's boyfriend got jealous when he saw her getting impressed by Mandwarf, the brown's wisdom. 
He wants to learn the trick to gain her undivided admiration. How about you help him?

Constraints:
1 ≤ T ≤ 100 
1 ≤ N ≤ 1000
0 ≤ L[i] ≤ 1018
0 ≤ A,B ≤ 1018
2 ≤ C ≤ 1018
Input
First line contains a single integer T, denoting the number of test cases. Then follow T test case scenarios. 
Each test case begins with an integer N, the size of the list L. 
Then in next line, you'd find N space separated integers - the list L itself. In next line, 
there'd be three space separated integers A, B, C followed by string S in the next line.

Output
For each test case you've to output N space separated integers - the numbers announced by Mandwarf, the brown.

Example
Input:
2
3
1 1 1
2 3 1000
ARM
4
1 2 3 4
0 1 1000
AMAM

Output:
3 3 9
1 2 3 4*/

#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; ++i)
typedef long long ll;
const int MAXN = 1e3 + 5;

ll A[MAXN];

ll mul(ll a, ll b, ll M) {
    if(b == 0) return 0;
    ll x = mul(a, b>>1, M);
    x = (x + x) % M;
    if(b & 1) x = (x + a) % M;
    return x % M;
}


int main() {
    int t; cin >> t;
    int n;
    ll a, b, c;
    string s;

    while(t--) {
        cin >> n;

        REP(i, 0, n) cin >> A[i];

        cin >> a >> b >> c;
        cin >> s;

        ll X = 1, Y = 0;
        int start = 0, end = n;
        int rev = 0;

        REP(i, 0, n) {
            if(s[i] == 'R') rev ^= 1;
            else if(s[i] == 'A') Y = (Y + a) % c;
            else if(s[i] == 'M')  X = mul(X, b, c), Y = mul(Y, b, c);
            
            ll cur = A[rev ? --end : start++];
            ll ans = (mul(cur, X, c) + Y) % c;
            cout << ans << " ";
        }
        cout << endl;
    }
}