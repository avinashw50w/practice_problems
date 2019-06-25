/* Given an array of size N ( N<=10^4 ) ( all elements are less than or equal to 300 and greater than 1) you need to find the length of the longest subsequence 
which follows the following property :
Let x[1]... x[n] be a subsequence , let p[1],p[2]..p[m] be prime numbers which divide atleast one of the numbers in x[1],..x[n] . 
Now for each p from 1 to m lets do the following let productX ( a variable ) =1 :

1) If p[i] divides only 1 number in 1..n then find the largest power of this prime which divides that number and multiply it to productX.

2) If p divides more than 1 number, then find the largest power of this prime which divides each of the numbers. 
Now you have n numbers like y[1],y[2]...y[n] ( y[i] is basically the largest power of prime p which divides x[i]; that is y[i]=p^k where k>=0). 
Reject all y[i] that are equal to 1. Among the remaining numbers, select the smallest and the largest number and multiply it to productX. 
For example, if the sequence y[ ] is {1,1,2,8,3}, we will multiply 2 and 8 to productX.
Now if productX is equal to the product of numbers in that subsequence then it is a valid subsequence .
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows .
The first line of each test case contains a single integer N denoting the size of the array . The second line contains N space-separated integers A1, A2, ..., AN 
denoting the .the array .
 
Output

For each test case, output a single line containing maximum possible length of the subsequence .
 
Constraints

1 = T = 20
1 = N = 10000
2 = A[i] = 300
 
Example

Input:
1
4
2 2 4 3

Output:
3
 
Explanation

Example case 1. In this case answer is 3 ( Subarray is 2 2 3 or 2 4 3 ). 2 2 4 3 wont be valid because product of numbers is 48 and productX is 2 * 4 * 3 = 24 .*/

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
 
int isp[301], cnt[301], fl[301];
vector < int > prime[301];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 300; i++){
        if(isp[i] == 0){
            for(int j = i; j <= 300; j += i) {
                isp[j] = 1;
                prime[j].pb(i);
            }
        }
    }
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        set0(cnt);
        REP(i, n){
            int x; cin >> x;
            cnt[x]++;
        }
        FOR(i, 2, 301) cnt[i] = min(2, cnt[i]);
        int res = cnt[1];
 
        set0(fl);
        for(int i = 1; i <= 4; i++){
            FOR(j, 2, 301){
                if(prime[j].size() != i) continue;
                REP(k, cnt[j]){
                    int f = 0;
                    REP(l, i) if(fl[ prime[j][l] ] == 2) f = 1;
                    if(f) continue;
                    REP(l, i) fl[ prime[j][l] ]++;
                    res++;
                }
            }
        }
 
        cout << res << endl;
    }
}
 
