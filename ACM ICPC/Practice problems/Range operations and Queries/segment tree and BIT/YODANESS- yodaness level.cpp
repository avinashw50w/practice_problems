/*Yoda is the wisest, and perhaps the most powerful Jedi of his time. Yoda is a mysterious figure and he has many oddities. One of them is that 
Yoda often changes the order of words in the sentence. For example, one of such phrases is "Or I will help you not." Let's call the yodaness 
level of any statement the number of pairs of words that changed their order, as to the order in which they were supposed to go in a normal 
statement. Write a program that determines the yodaness level of different statement of Yoda.

 
Input

The first line of input contains the number t - the number of tests. Next comes the description of t tests. Each test consists of three rows. 
The first line of the test contains an integer n - number of words in the statement. The next line contains n words separated by spaces - 
the statement as Yoda says it. The next line is n words separated by spaces - the same statement as it should be said normally. All the words 
in the statement are different and consist of small latin letters.

Constraints

1 <= t <= 10
1 <= n <= 30000
the length of each word does not exceed 20 characters

Output

For each test print the yodaness level of the statement.

Example

Input:
2
6
in the force strong you are
you are strong in the force
6
or i will help you not
or i will not help you

Output:
11
2
*/
/* the problem is to count the number of inversions (this can also be done using merge sort)*/

int n;
int bit[30000+9];

void update(int i) {
	for(; i<=n; i+=i&-i) bit[i]++;
}

ll query(int i) {
	ll ans = 0;
	for(; i>0; i-=i&-i) ans += bit[i];
	return ans;
}

int main() {
	int t; si(t);
	while(t--) {
		si(n);
		
		memset(bit, 0, sizeof(bit));
		map<string,int> m;
		vector<int> v;
		string s[n+1], str;

		rep(i,0,n) cin >> s[i];
		
		rep(i,0,n) {
			cin >> str;
			m[str] = i;
		}

		rep(i,0,n) {
			v.push_back(m[s[i]] + 1);
		}

		ll ans = 0;
		for(int i=n-1;i>=0;--i) {
			int x = query(v[i]-1);
			ans += x;
			update(v[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
