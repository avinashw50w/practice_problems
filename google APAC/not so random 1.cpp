/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


long double dp[100011][2];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        LL n, X, K; cin >> n >> X >> K;
        long double A, B, C; cin >> A >> B >> C;
        A /= 100.0; B /= 100.0; C /= 100.0;

        long double res = 0.0;
        REP(i, 33){
            dp[n][1] = 1.0;
            dp[n][0] = 0.0;
            int v1 = (K & (1ll<<i)) > 0 ? 1 : 0;
            int v2 = (X & (1ll<<i)) > 0 ? 1 : 0;
            for(int j = n-1; j >= 0; j--){
                REP(k, 2){
                    dp[j][k] = 0.0;
                    dp[j][k] += A * dp[j+1][k & v1];
                    dp[j][k] += B * dp[j+1][k | v1];
                    dp[j][k] += C * dp[j+1][k ^ v1];
                }
            }

            res += dp[0][v2] * (long double)(1ll<<i);
        }

        cout << "Case #" << ts << ": ";
        cout << fixed << setprecision(15) << res << endl;
    }
}

