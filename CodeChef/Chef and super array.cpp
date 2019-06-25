/*Chef has a an array A consisting of N elements. He wants to add some elements into the array as per the below mentioned process.
After each minute, Chef iterates over the array in order from left to right, and takes every two neighbouring pair of elements, say x and y, 
he adds a new element x + y in the middle of elements x and y.
For example, if initial array A = {1, 6, 9}.
After first minute, the array A will be equal to {1, 7, 6, 15, 9}. Please note that the elements shown in the bold font are the newly added 
elements during first minute. As you can observe that 7 = 1 + 6, and 15 = 6 + 9.
After second minute, the array will be {1, 8, 7, 13, 6, 21, 15, 24, 9}. Once again, elements added during the second minute, are shown in bold.
Chef wants to know the sum of elements between xth and yth positions in the array A (i.e. Ax + Ax + 1 + ... + Ay) after m minutes. As the answer 
could be large, output it modulo 109+7 (1000000007). Please note that we use 1 based indexing in the problem.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains four space-separated integers N, m, x, y denoting the number of elements in the array A in the 
beginning, amount of minutes and range for finding sum.
The second line contains N space-separated integers A1, A2, ..., AN denoting the array A in the beginning.
Output

For each test case, output a single line containing an integer corresponding to the sum of elements between xth and yth positions in the 
array A after m minutes modulo 109+7.
Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 103
1 ≤ m ≤ 30
1 ≤ x ≤ y ≤ size of the array A (|A|) after m minutes
Example

Input:
2
3 1 1 5
1 6 9
3 2 6 7
1 6 9

Output:
38
36
Explanation

Example case 1.
After the first minute A = {1, 7, 6, 15, 9} and sum of all elements will be 38.
Example case 2.
After the second minute the array A will be {1, 8, 7, 13, 6, 21, 15, 24, 9} and sum of elements between 6th and 7th equals to 21 + 15 = 36.*/

const int N = 100000 + 5;
const int MOD = (int)1e9 + 7;
 
int n, m;
long long l, r;
int a[N];
map<pair<int, long long>, int> mem;
 
long long getValue(int layer, long long r)
{
	if (layer == 0) return a[r - 1];
	if (mem.count(make_pair(layer, r))) {
		return mem[make_pair(layer, r)];
	}
	int &ret = mem[make_pair(layer, r)];
	if (r % 2) {
		ret = getValue(layer - 1, r / 2 + 1);
	} else {
		ret = getValue(layer - 1, r / 2) + getValue(layer - 1, r / 2 + 1);
		if (ret >= MOD) ret -= MOD;
	}
	return ret;
}
 
long long calc(int layer, long long r)
{
	if (r == 0) return 0;
	if (r == 1) return a[0];
	if (layer == 0) {
		long long ret = 0;
		for(int i = 0; i < r; ++ i) {
			ret += a[i];
		}
		return ret % MOD;
	}
	long long ret = calc(layer - 1, r / 2 + 1) * 3 - a[0];
	ret -= getValue(layer - 1, r / 2 + 1) * (2 - r % 2);
	return (ret % MOD + MOD) % MOD;
}
 
void solve()
{
	cin >> n >> m >> l >> r;
	for(int i = 0; i < n; ++ i) {
		scanf("%d", a + i);
	}
	mem.clear();
	cout << (calc(m, r) - calc(m, l - 1) + MOD) % MOD << endl;
}
 
int main()
{
	int t;
	for(cin >> t; t --; ) solve();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
typedef long long ll;
int const modbase = 1000000007;
 
int N, S[100001];
 
inline void increase_mod(int &a, int const &b) {
	a = (a+b)%modbase;
}
 
pair<int, vector<int>> get_coeff(int m, ll base) {
	vector<int> current = {1};
	while (m-->0) {
		vector<int> nextup((base + current.size() + 3)/2 - base/2);
		for (ll pos=base; pos<base + current.size(); ++pos) {
			increase_mod(nextup[pos/2 - base/2], current[pos-base]);
			increase_mod(nextup[pos/2 + 1 - base/2], current[pos-base]);
			increase_mod(nextup[(pos+1)/2 - base/2], current[pos-base]);
		}
		current.swap(nextup);
		base /= 2;
	}
	return pair<int, vector<int>> ((int)base, current);
}
 
int add_mod (int a, int b) {return (a+b)%modbase;}
int mul_mod (int a, int b) {return (int)(((ll)a*b)%(ll)modbase);}
 
int main () {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T-->0) {
		int m; ll x, y;
		cin >> N >> m >> x >> y; --x;
 
		for (int i=1; i<=N; ++i) {
			cin >> S[i];
			S[i] += S[i-1];
		}
 
		auto init = get_coeff(m, x);
		auto fin = get_coeff(m, y);
		int result = inner_product(fin.second.begin(), fin.second.end(), S+fin.first, 0, add_mod, mul_mod)
					- inner_product(init.second.begin(), init.second.end(), S+init.first, 0, add_mod, mul_mod);
		cout << (result + modbase)%modbase << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
