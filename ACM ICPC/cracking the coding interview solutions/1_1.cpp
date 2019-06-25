/*Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?*/

// method 1
bool check(string s) {
	bool f[255] = {};
	for(int i = 0; i < s.size(); ++i) {
		if(f[s[i]]) 
			return false;
		f[s[i]] = true;
	}

	return true;
}

// method 2 : suppose the string contains only small case letters
bool check(string s) {
	int a = 0;
	for(int i = 0; i < s.size(); ++i) {
		int k = s[i] - 'a';
		if(a & (1<<k))
			return false;
		a |= (1<<k);
	}

	return true;
}