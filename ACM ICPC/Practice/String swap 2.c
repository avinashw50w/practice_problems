/* Bob has become insanely good at competitive programming of late. After having solved the problem "String Swap" easily, he asked for a harder problem to be 
given to him. "String Swap" was thus modified to form the following problem.
In this problem, you are given a string of N characters(1-indexed), and an integer D.(D is always an even integer). We perform multiple operations on this string. 
In every operation, we perform 2 steps.
In the first operation we select the first D characters of the string, ie. the substring S[1...D] and modify this substring by applying the following two steps:
In the first step, we separate the substring into two equal halves S[1...(D/2)] and S[(D/2 + 1).....D]. These two halves are then interleaved among each other to
 form the following string:
S1SD/2+1S2SD/2+2....SD/2SD
In the second step, we perform a K-right circular shift on the substring obtained after step 1. Thus, if the substring at the end of step 1 is abcde, 
performing a 2-right circular shift on this will change it to deabc.
Note that both these steps are performed on the D-length substring only. All other characters of the main string remain unchanged.

The original string is then thrown away, and the new string thus obtained will be used for the subsequent operations.
In the next operation, we select the next D characters, ie the substring S[2...D] of the current string and perform the same two steps as described above. 
This constitutes the second operation. We continue performing these operation a total of N-D+1 times (selecting substring S[i....(i+D-1)] in the i operation.
Bob was asked to tell the string at the end of all these operations have been performed. This problem however proved to be a tad too difficult for Bob. Can you help him?
Input

The first line of the input contains a single integer T, the number of test cases.The description of T test cases follows.
Every test case has two lines. The first line contains the string S. The next line contains two space separated integers D and K corresponding to that test case.
Output

For each test case output a single line, containing the value oft the string at the end.
Constraints

1 = T = 10
2 = |S| = 105
2 = D = |S|
0 = K < D
D is guaranteed to be even
 
Example

Input:
1
hello
4 2

Output:
eholl
 
Explanation

After the first operation, in first step, the string hello becomes hlelo. And in second step, it becomes, elhlo
After the second operation, in the first step the string becomes ellho and in second step it becomes eholl.

Thus the answer is eholl.*/

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
 
vector < int > vc[100001];
string S;
int ar[200001], vis[100001];
vector < int > cycles[100001], path;
int isPath[100001], id[100001];
void dfs1(int c){
    isPath[c] = 1;
    path.pb(c);
    vis[c] = 1;
    id[c] = path.size();
    if(vc[c][0] == 0) return;
    dfs1(vc[c][0]);
}
void dfs(int c, int f){
    isPath[c] = 0;
    id[c] = f;
    cycles[f].pb(c);
    vis[c] = cycles[f].size();
 
    if(vis[ vc[c][0] ] == 0) dfs(vc[c][0], f);
}
char pp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> S;
        int D, K; cin >> D >> K;
        REP(i, D/2) {
            ar[i*2] = i;
            ar[i*2+1] = i+(D/2);
        }
 
        REP(i, D) ar[i+D] = ar[i];
        K = D - K;
        REP(i, D) ar[i] = ar[i+K];
 
        REP(i, D+1) vc[i].clear();
        REP(i, D){
            vc[ar[i]+1].pb(i);
        }
 
        path.clear();
        REP(i, D+1) cycles[i].clear();
        set0(vis);
 
        dfs1(D);
        int cc = 0;
        FOR(i, 1, D){
            if(vis[i] == 0){
                dfs(i, ++cc);
            }
        }
 
 
        int n = S.size();
        set0(pp);
        FOR(i, 1, D){
            if(isPath[i] == 1){
                int p = path.size() - id[i] + 1;
                if(p <= n-D+1) pp[p] = S[i-1];
                else {
                    pp[n-D+1 + path[ id[i]+n-D ] ] = S[i-1];
                }
            } else {
                int p = cycles[ id[i] ].size();
                int v = (vis[i]-1 + n-D+1) % p;
                pp[n-D+1 + cycles[ id[i] ][v] ] = S[i-1];
            }
        }
 
        int lft = 1;
        for(int i = D; i <= n; i++){
            int p = path.size() - id[D] + 1;
            if(p <= n-D-lft+2) pp[p+lft-1] = S[i-1];
            else {
                pp[n-D+1 + path[ id[D]-1+n-D-lft+2 ] ] = S[i-1];
            }
            lft++;
        }
 
        FOR(i, 1, n+1) cout << pp[i];
        cout  << endl;
    }
}
