/*Write a method to decide if two strings are anagrams or not.*/

// method 1: use hash
bool isAnagram(string s1, string s2) {
	int f[256] = {};

	for(int i = 0; i < s1.size(); ++i)
		f[s1[i]]++;

	for(int i = 0; i < s2.size(); ++i)
		f[s2[i]]--;

	for(int i = 0; i < 256; ++i)
		if(f[i])
			return false;

	return true;
}

// method 2: use sorting

bool isAnagram(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return s1 == s2;
}