/*You are given a string whose length is even, and each character of the string is either 'a', 'b' or '/' 
Your task is to replace each occurrence of '/' in string with either 'a' or 'b' such that the string becomes a palindrome.
You are also given two integers, aCost and bCost. Replacing '/' with 'a' costs aCost, and replacing '/' with 'b' costs bCost.

Return the minimum cost of replacing '/' by 'a' and 'b' such that the string turns into a palindrome. 
If it is impossible to obtain a palindrome, return -1.

SAMPLE INPUT 
1
baba//aaa/ab//
72
23
SAMPLE OUTPUT 
213   */

int main() {
	int t, acost, bcost;
	string s;
	
	cin>>t;
	while(t--) {
		cin>>s;
		cin>>acost>>bcost;
		
		int n = s.size();
		int ans = 0, f = 0;
		rep(i, 0, n/2) {
			if(s[i] != s[n-i-1]) {
				if(s[i] == '/') ans += (s[n-i-1] == 'a')? acost: bcost;
				else if(s[n-i-1] == '/') ans += (s[i] == 'a')? acost: bcost;
				else { f=1; break; }
			}
			else{
				if(s[i] == '/') ans += 2 * min(acost, bcost);
			}
		}
		cout << (f? -1 : ans);
		cout << endl;
	}
	return 0;
}