/*Write a method to replace all spaces in a string with ‘%20’.*/

void replace(string s) {
	int n = s.size(), spaceCnt = 0;

	for(int i = 0; i < n; ++i)
		if(s[i] == ' ')
			spaceCnt++;

	int newLen = n + spaceCnt * 2;

	for(int i = n-1; i >= 0; --i) {
		if(s[i] == ' ') {
			s[newLen-1] = '0';
			s[newLen-2] = '2';
			s[newLen-3] = '%';
			newLen -= 3;
		}
		else {
			s[newLen-1] = s[i];
			newLen--;
		}
	}
}