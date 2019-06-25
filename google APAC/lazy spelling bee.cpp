/*n the Lazy Spelling Bee, a contestant is given a target word W to spell. The contestant's answer word A is acceptable if it is the same length as the target word, 
and the i-th letter of A is either the i-th, (i-1)th, or (i+1)th letter of W, for all i in the range of the length of A. (The first letter of A must match either the 
first or second letter of W, since the 0th letter of W doesn't exist. Similarly, the last letter of A must match either the last or next-to-last letter of W.) 
Note that the target word itself is always an acceptable answer word.

You are preparing a Lazy Spelling Bee, and you have been asked to determine, for each target word, how many distinct acceptable answer words there are. Since this number 
may be very large, please output it modulo 1000000007 (109 + 7).

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of one line with a string consisting only of lowercase English letters 
(a through z).

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the number of distinct acceptable answer words, 
modulo 109 + 7.

Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ length of each string ≤ 5.
Large dataset

1 ≤ length of each string ≤ 1000.
Sample


Input 
 	
Output 
 
4
ag
aa
abcde
x

Case #1: 4
Case #2: 1
Case #3: 108
Case #4: 1

In sample case #1, the acceptable answer words are aa, ag, ga, and gg.

In sample case #2, the only acceptable answer word is aa.*/

int main() {
	int n;
	string s;
	#if 0
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif

	caset{
		cin>>s;
		n=s.size();
		int a[n];
		fill(a,a+n,1);
		printf("Case #%d: ", case_n++);
		if(n==1){ printf("1\n"); continue; }
		
		if(s[0]!=s[1]) a[0]++;
		rep(i,1,n-1){
			if(s[i]!=s[i-1]) a[i]++;
			if(s[i-1]!=s[i+1] && s[i]!=s[i+1]) a[i]++;

		}
		if(s[n-1]!=s[n-2]) a[n-1]++;
		
		ll ans = 1LL;
		rep(i,0,n){ ans = (ans * a[i]) % mod; }
		printf("%lld\n",ans);
	}
	return 0;
}
