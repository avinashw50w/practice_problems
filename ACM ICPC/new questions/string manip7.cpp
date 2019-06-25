/*He has a string S that consists of lowercase English letters ('a' - 'z'). 
Artur wants to find a substring T of S of the maximal length, so that T isn't a palindrome. 

Input
The input contains a single line, containing string S. String S consists of lower case English letters.*/

/*This is very simple problem :
Check for the case wher all characters are same like aaaa , bbbb. . .  In this case answer will be zero.
Otherwise check if string is palindromic or not if yes answer is n-1 where n is length of string
If string is not palindromic return n. */


int solve(string s) {
	int i, j, n = s.size();

	for(i = 1; i < n; ++i) {
		if(s[i] != s[i-1]) break;
	}
	if(i == n) return 0;
	
	i = 0; j = n-1;
	while(i < j) {
		if(s[i] != s[j]) break;
		i++; --j;
	}
	if(i >= j) return n-1;
	return n;
}

int main()
{
    string s; cin>>s;
   
   	cout << solve(s) << endl;
    return 0;
}
