/*Xsquare got bored playing with the arrays all the time. Therefore he has decided to buy a string S 
consists of N lower case alphabets. Once he purchased the string, He starts formulating his own terminologies 
over his string S. Xsquare calls a string str A Balanced String if and only if the characters of the 
string str can be paritioned into two multisets M1 and M2 such that M1= M2 .

For eg:

Strings like "abccba" , "abaccb" , "aabbcc" are all balanced strings as their characters 
can be partitioned in the two multisets M1 and M2 such that M1 = M2.

M1 = {a,b,c}

M2 = {c,b,a}

whereas strings like ababab , abcabb are not balanced at all.

Xsquare wants to break the string he has purchased into some number of substrings so that 
each substring is a balanced string . However he does not want break 
the string into too many substrings, otherwise the average size of his strings will become small. 
What is the minimum number of substrings in which the given 
string can be broken so that each substring is a balanced string.

Output

For each test case, print the minimum number of substrings in which the given string can be broken so that 
each substring is a balanced string. If it is not possible the given string according to the requirement print -1 .

There are a lot of people who think question is wrong.. but actually the question asks of minimum number of 
balanced sub-string. If the string string is balanced, the answer becomes one as that is the minimum number of sub-string. 
If the string is not balanced, then none of the division of the string be balanced, and the ans is either 1 or -1. 
It is a logical question, nothing else....*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	string s;
	cin>>t;
	while(t--) {
		cin>>s;

		int n = s.size();

		int ans = 0;

		for(int i=0;i<n;++i) ans ^= (s[i]-'a' + 1);
		
		puts(ans == 0 ? "1" : "-1");
	}
}