/*Check if two given strings are isomorphic to each other
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every 
character of str2. And all occurrences of every character in ‘str1’ map to same character in ‘str2’

Examples:

Input:  str1 = "aab", str2 = "xxy"
Output: True
'a' is mapped to 'x' and 'b' is mapped to 'y'.

Input:  str1 = "aab", str2 = "xyz"
Output: False
One occurrence of 'a' in str1 has 'x' in str2 and 
other occurrence of 'a' has 'y'.
*/

bool isIsomorphic(string s1, string s2) {

	int N = s1.size(), M = s2.size();

	if(N != M) return false;

	bool vis[256] = {false};

	int map[256];
	memset(map, -1, sizeof map);

	REP(i, 0, N) {
		// if the current char of s1 is seen for the first time
		if(map[s1[i]] == -1) {

			// if the current char of s2 has already been visited, then there is no one-to-one mapping
			if(vis[s2[i]]) return false;

			vis[s2[i]] = true;

			map[s1[i]] = s2[i];
		}
		// if there exists some other mapping 
		else if(map[s1[i]] != s2[i]) return false;
	}

	return true;
}