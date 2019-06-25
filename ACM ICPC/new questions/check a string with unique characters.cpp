/*Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?*/
/*consider that that string only contains small-case letters.*/

bool solve(string s) {

	int n = s.length();

	if(n < 1 || n > 26) return false;
	
	int check = 0;

	REP(i, 0, s.size()) {
		int c = s[i] - 'a';
		if(check & (1<<c)) return false;
		check |= (1<<c); 
	}
	return true;
}