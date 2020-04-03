/*Kevin has a string S consisting of N lowercase English letters.

Kevin wants to split it into 4 pairwise different non-empty parts. For example, string "happynewyear" can be splitted into 
"happy", "new", "ye" and "ar". He can't delete any characters or change the order of the characters.

Help Kevin and find if there exist at least one possible spliting.
For every test case output "YES" if it is possible to split the string and "NO" otherwise.*/

/*The key observation: if the length of S is greater or equal to 1+2+3+4 =10 than the answer is always YES as we can just split S in 
for 4 substrings with pairwise different lenghtes. Otherwise the length of S is small and we can just do bruteforce solution 
in O(|S|4) time: iterate through the all possible ways of splitting the string and check each one. */

#define FOR(i,a,b) for(int i=a;i<b;++i)

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if (s.size() >= 10)
		{
			cout << "YES" << endl;
			continue;
		}
		bool ok = 0;
		FOR(i,1,s.size())
			FOR(j,i + 1 , s.size())
				FOR(k,j + 1 , s.size())
				{
					string s1 = s.substr(0,i);
					string s2 = s.substr(i, j - i);
					string s3 = s.substr(j, k - j);
					string s4 = s.substr(k, s.size() - k);
					if (s1 != s2 && s1 != s3 && s1 != s4 && s2 != s3 && s2 != s4 && s3 != s4)
					{
						ok = 1;
					}
				}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}
