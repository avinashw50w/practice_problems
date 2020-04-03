/*Given a string and several queries on the substrings of the given input string to check whether the substring is a palindrome or not.

The idea is similar to Rabin Karp string matching. We use string hashing. What we do is that we calculate cumulative hash values of the string in the original 
string as well as the reversed string in two arrays- prefix[] and suffix[].
How to calculate the cumulative hash values ?

Suppose our string is str[], then the cumulative hash function to fill our prefix[] array used is-

prefix[0] = 0
prefix[i] = str[0] + str[1] * 101 + str[2] * 1012 + 
                              ...... + str[i-1] * 101i-1

For example, take the string- “abaaabxyaba”

prefix[0] = 0
prefix[1] = 97  (ASCII Value of ‘a’ is 97)
prefix[2] = 97 + 98 * 101
prefix[3] = 97 + 98 * 101 + 97 * 1012
...........................
...........................
prefix[11] = 97 + 98 * 101 + 97 * 1012 +
                         ........+ 97 * 10110 
Now the reason to store in that way is that we can easily find the hash value of any substring in O(1) time using-

 hash(L, R) = prefix[R+1] – prefix[L]
For example, hash (1, 5) = hash (“baaab”) = prefix[6] – prefix[1] = 98 * 101 + 97 * 1012 + 97 * 1013 + 97 * 1014 + 98 * 1015 = 1040184646587 [We will use this
 weird value later to explain what’s happening].

Similar to this we will fill our suffix[] array as-

suffix[0] = 0
suffix[i] = str[n-1] + str[n-2] * 101 + str[n-3] * 1012 +
                                   ...... + str[n-i] * 101i-1

For example, take the string- “abaaabxyaba”

suffix[0] = 0
suffix[1] = 97  (ASCII Value of ‘a’ is 97)
suffix[2] = 97 + 98 * 101
suffix[3] = 97 + 98 * 101 + 97 * 1012
...........................
...........................
suffix[11] = 97 + 98 * 101 + 97 * 1012 + ........+ 97 * 10110
Now the reason to store in that way is that we can easily find the reverse hash value of any substring in O(1) time using

reverse_hash(L, R) = hash (R, L) = suffix[n-L] – suffix[n-R-1] 
where n = length of string.

For “abaaabxyaba”, n = 11
reverse_hash(1,5) = reverse_hash(“baaab”) = hash(“baaab”) [Reversing “baaab” gives “baaab”]

hash(“baaab”) = suffix[11-1] – suffix[11-5-1] = suffix[10] – suffix[5] = 98 * 1015 + 97 * 1016 + 97 * 1017 + 97 * 1018 + 98 * 1019 = 108242031437886501387

Now there doesn’t seem to be any relation between these two weird integers – 1040184646587 and 108242031437886501387

Think again. Is there any relation between these two massive integers ?

Yes, there is and this observation is the core of this program/article.

1040184646587 * 1014 = 108242031437886501387

Try thinking about this and you will find that any substring starting at index- L and ending at index- R (both inclusive) will be a palindrome if

(prefix[R + 1] – prefix[L]) / (101^L) = (suffix [n - L] – suffix [n – R- 1] ) / (101^n – R - 1)
The rest part is just implementation.*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)

const int mod = 1000000007;
const int MAXN = 100000+9;

#define b1 101

ll p[MAXN], prefix[MAXN], suffix[MAXN];

string s;
int N;

bool isPalindrome(int l, int r) {
	while(l < r){
		if(s[l++] != s[r--]) return false;
	}
	return true;
}

ll modpow(ll a, ll b) {
	if(b == 0) return 1;
	ll x = modpow(a, b/2);
	x = (x*x)%mod;
	if(b&1) x = (x*a)%mod;
	return x;
}

void prec() {
	p[0] = 1;

	rep(i,1,MAXN) p[i] = (p[i-1] * b1) % mod;
}

void CalculateHash() {
	prefix[0] = 0;
	prefix[1] = s[0];

	rep(i,2,N+1) prefix[i] = (prefix[i-1] + (s[i-1] * p[i-1]) % mod) % mod;

	suffix[0] = 0;
	suffix[1] = s[N-1];

	for(int i=N-1, j=2; i>=0 && j<=N; --i, ++j)
		suffix[j] = (suffix[j-1] + (s[i-1] * p[j-1]) % mod) % mod;
}

bool query(int l, int r) {

	ll hash = ((prefix[r+1] - prefix[l] + mod) % mod * modpow(p[l], mod-2) % mod);

	ll rev_hash = ((suffix[N-l] - suffix[N-r-1] + mod) % mod * modpow(p[N-r-1], mod-2)) % mod; 

	if(hash == rev_hash) {
		if(isPalindrome(l, r)) return true;
		else return false;
	}
	else return false;
}
int main() {

	prec();

	cin >> s;
	N = s.size();

	CalculateHash();

	int Q; cin >> Q;
	while(Q--) {
		int l, r;
		cin >> l >> r;

		cout << query(l ,r);
	}
	return 0;
}
