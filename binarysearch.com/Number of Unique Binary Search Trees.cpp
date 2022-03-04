/*Given an integer n, return the number of unique binary search trees you can form with integers from [0, n). Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 1,000
Example 1
Input
n = 3
Output
5
Explanation
There are 5 unique trees.

0
 \
  1
   \
    2
0
 \
  2
 /
1
    2
   /
  1
 /
0
  2
 /
0
 \
  1
  1
 / \
0   2*/

const int mod = 1e9 + 7;

long long power(long long a, int b) {
    long long res = 1;
    for (; b; b >>= 1, a = (a * a) % mod) {
        if (b & 1) res = (res * a) % mod;
    }
    return res % mod;
}

int solve(int n) {
    // nth catalan number 2nCn/(n+1)
    long long res = 1;
    long long f[2*n+1];
    
    f[0] = f[1] = 1;
    for (int i = 2; i <= 2*n; ++i) f[i] = (i * f[i-1]) % mod;
    
    res = f[2*n];
    res = (res * power(f[n], mod-2)) % mod;
    res = (res * power(f[n+1], mod-2)) % mod;

    return res;
}