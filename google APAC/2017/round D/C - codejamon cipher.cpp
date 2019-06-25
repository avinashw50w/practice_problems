/**/

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

map<string, int> cnt;
set<string> pool;
int LIM, len, dp[MAXN];
string s;

string ord(string s) {
	sort(all(s));
	return s;
}

ll solve(int pos) {
	if(pos == len) return 1;

	ll &ans = dp[pos];
	if(ans != -1) return ans;

	string cur = "";
	ans = 0;
	int to = pos + LIM + 1;
	to = min(to, len);

	REP(i, 0, to) {
		cur += s[i];

		sort(all(cur));

		if(cnt[cur]) 
			ans = (ans + cnt[cur] * solve(i+1)) % MOD;
	}
}

int main() {
	int t, n, q
	string word;
	cin >> t;

	REP(test, 0, t) {
		cout << "Case #" << test << ": ";
		cin >> n >> q;

		cnt.clear(); pool.clear();

		LIM = 0;

		REP(i, 0, n) {
			cin >> word;

			LIM = max(LIM, (int)word.size());
			pool.insert(word);
			cnt[ord(word)]++;
		}

		while(q--) {
			cin >> s;

			len = s.size();
			memset(dp, -1, sizeof(dp));

			cout << solve(0);
		}

		cout << endl;
	}
}