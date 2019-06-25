/*A string is called unique if all characters of string are distinct.

String s1 is called subsequence of string s2 if s1 can be produced from s2 by removing some characters of s2.

String s1 is stronger than s2 if s1 is lexicographically greater than s2.

You are given a string. Your task is to find the strongest unique string which is subsequence of given string.
Input:
The first line contains a single integer N indicating the size of the list. This is followed by N lines where each line contains a name listed by Sumit.

Output:
In a single line print minimum number of groups in a partition that satisfy above conditions*/

/*first find the largest char from 0 to s.size() which has not been visited yet(let's say its index is i), add it to the ans, and 
again find the largest char from i+1 to s.size() which has not been visited yet, add it to the ans and again proceed similarly */

string s;
int n;
int vis[26];

void  solve(int idx, string &ans) {
	if(idx == s.size()) return;

	char c = 'A';
	int k = -1;

	for(int i = idx; i<s.size(); ++i) {
		if(s[i] > c and !vis[s[i]-'a']) c = s[i], k = i;
	}

	if(k == -1) return;

	ans += c;
	vis[c-'a'] = 1;
	
	solve(k+1, ans);
}

int main()
{
	cin>>n;
    cin>>s;

    string ans = "";

    solve(0, ans);
    
    cout << ans << endl;

    return 0;
}
