/*This is his method: if the number of distinct characters in one's user name is odd, then he is a male, 
otherwise she is a female. You are given the string that denotes the user name, please help our hero to 
determine the gender of this user by his method.

Input
The first line contains a non-empty string, that contains only lowercase English letters — 
the user name. This string contains at most 100 letters.

Output
If it is a female by our hero's method, print "CHAT WITH HER!" (without the quotes), 
otherwise, print "IGNORE HIM!" (without the quotes).

Examples
inputCopy
wjmzbmr
outputCopy
CHAT WITH HER!
inputCopy
xiaodao
outputCopy
IGNORE HIM!*/

#include <iostream>
using namespace std;

int main() {
	int f[26] = {}, cnt = 0;
	char c; 
	while(cin>>c) cnt += !f[c-'a'], f[c-'a'] = 1;
	(cnt&1) ? cout << "IGNORE HIM!\n" : cout << "CHAT WITH HER!\n";
	cout << endl; 
}