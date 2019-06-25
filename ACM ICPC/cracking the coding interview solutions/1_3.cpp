/*Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. 
NOTE: One or two additional variables are fine. An extra copy of the array is not.*/

// this one only works if the duplicates are adjacent
void removeDuplicates(char *s) {
	int k = 1;
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] == s[i-1])
			continue;
		s[k++] = s[i];
	}

	s[k] = '\0';
}

// this one works for all cases
void removeDuplicates(char *str) {
	int n = strlen(str);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(str[j] == str[i]) {
				str[j] = ' ';
				break;
			}
		}
	}

	int k = 1;
	for(int i = 1; i < n; ++i) {
		if(str[i] == ' ')
			continue;
		str[k++] = str[i];
	}

	str[k] = '\0';
}