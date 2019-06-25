/* You are given a grid of size M x N, where each square is colored with some random color among K colors with each having equal probability.

A Good Rectangle is defined as one where all squares lying on the inner border are of the same color.

What is the expected number of Good Rectangles in the given grid.
 
Input

First Line contains M, N, K
Output

A single value rounded off to the nearest Integer corresponding to the required answer.
Constraints

1 <= N <= 105
1 <= M <= 105
1 <= K <= 105
 
Example

Input:
1 3 1

Output:
6  */
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
 
vd pw(1000, 0);
ll n,m,k;
 
double f(int a, int b) {
  ll mul = (n-a+1)*(ll)(m-b+1);
  if (b < a) swap(a, b);
  if (a == 1) return mul * k * pw[b];
  return mul * k * pw[2*a+2*b-4];
}
 
int main() {
    cin >> n >> m >> k;
    if (k == 1) {
      cout << n * (n + 1) / 2 * m * (m + 1) / 2 << endl;
      return 0;
    }
    double res = 0;
    pw[0] = 1;
    for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i-1] / k;
    for (int l = 1; l <= n; ++l) {
      for (int j = 1; j <= min((int)m, 200 - l); ++j) {
        res += f(l, j);
      }
    }
    cout << (ll)round(res) << endl;
    return 0;
}
 
