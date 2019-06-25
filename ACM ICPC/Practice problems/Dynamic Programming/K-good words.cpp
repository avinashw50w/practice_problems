/*Chef Al Gorithm was reading a book about climate and oceans when he encountered the word “glaciological”. He thought it was quite curious, 
because it has the following interesting property: For every two letters in the word, if the first appears x times and the second appears y 
times, then |x - y| ≤ 1.

Chef Al was happy about this and called such words 1-good words. He also generalized the concept: He said a word was K-good if for every two 
letters in the word, if the first appears x times and the second appears y times, then |x - y| ≤ K.

Now, the Chef likes K-good words a lot and so was wondering: Given some word w, how many letters does he have to remove to make it K-good?

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case consists of a single line containing two things: a word w and an integer K, separated by a space.

Output

For each test case, output a single line containing a single integer: the minimum number of letters he has to remove to make the word K-good.*/
/*PROBLEM:
A string is K-good if for every two letters in the string, if the first appears x times and the second y times, then |x−y|≤K. 
Given K and a string ww, what is the minimum number of letters to remove to make ww KK-good?

QUICK EXPLANATION:
For every min frequency count m(1<=m<=N), define F[m] as follows:

Remove every letter that appears < m times.
For every letter that appears > m+K times, remove just enough letters so that it appears exactly m+K times.
Let the number of removed letters be F[m]F[m].
The answer is then the smallest among {F[1],F[2],…,F[N]}{F[1],F[2],…,F[N]}. To compute this quickly, simply precompute the letter frequencies 
in ww beforehand, and operate on that array when computing F[m]F[m].*/

int f[26];

int main() {
	string s;
	int n,k;
	caset{
		cin>> s;
		si(k);
		n = s.size();
		mset(f,0);
		rep(i,0,n) f[s[i]-'a']++;

		int ans = oo;
		rep(m,1,n){
			int count = 0;
			rep(i,0,26){
				if(f[i] < m) 
					count += f[i];
				else if(f[i] > m+k) 
					count += f[i] - (m+k);
			}
			ans = min(ans, count);
		} 
		printf("%d\n", ans);
	}
	return 0;
}
