/*how many integer sequences A1, A2, .., An of length N satisfies the following conditions:
1.0 <= Ai <= 9
2.There exists some i such that Ai = 0 holds
3.There exists some i such that Ai = 9 holds
print the ans modulo 10^9 + 7
 */

const int mod = 1e9 + 7;
typedef long long ll;

ll p(ll a, ll b) {
	ll res = 1LL;
	for (; b; b >>= 1, a = (a * a) % mod) if (b & 1) res = (res * a) % mod;
}

int solve() {
	/**
	 * ans = total sequences - sequences having no 0's - sequences having no 9's + sequences having neither 0 nor 9
	 * ans = 10^n - 9^n - 9^n + 8^n
	 */
	int n; cin >> n;
	return (p(10, n) - 2 * p(9, n) + p(8, n)) % mod;
}