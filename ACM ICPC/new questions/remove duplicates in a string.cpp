/*Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. 
NOTE: One or two additional variables are fine. An extra copy of the array is not.*/

//for each char of the string starting from index 1, if char is equal to any of the previous characters then proceed to next char
// otherwise if it is a new character then set it to the tail of the string

// this one is inplace
void solve(char s[]) {

	int n = strlen(s);
	if(n < 2) return;

	int tail = 1;

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < tail; ++j) {		// all unique characters will be upto tail
			if(s[i] == s[j]) break;
		}
		if(j == tail) s[tail++] = s[i];	// if s[i] is a new char then add it to the tail
	}

	s[tail] = '\0';
}

// this one uses constant space of 256

void solve(char s[]) {

	int n = strlen(s);
	if(n < 2) return;

	int tail = 1;
	bool f[256] = {};

	f[s[0]] = 1;

	for(int i = 1; i < n; ++i) {
		if(!f[s[i]]){
			s[tail++] = s[i];
			f[s[i]] = 1;
		}
	}

	s[tail] = '\0';
}