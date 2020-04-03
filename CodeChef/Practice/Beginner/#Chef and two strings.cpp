#include<iostream>
using namespace std;
#define ll long long
int main(){
	int t;cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int n = s1.size();
		int mini=0, similar=0,maxx=0;
		for(int i=0;i<n;i++){
			if(s1[i]!=s2[i] and s1[i]!='?' and s2[i]!='?') mini++;
			if(s1[i]==s2[i] and s1[i]!='?' and s2[i]!='?') similar++;
		}	
		cout<< mini <<" "<< (n-similar) << endl;
	}
}

/* Chef has found two very old sheets of paper, each of which originally contained a string of lowercase Latin letters. The strings on both the sheets have equal lengths.
 However, since the sheets are very old, some letters have become unreadable.
Chef would like to estimate the difference between these strings. Let's assume that the first string is named S1, and the second S2. The unreadable symbols are 
specified with the question mark symbol '?'. The difference between the strings equals to the number of positions i, such that S1i is not equal to S2i, where S1i and S2i 
denote the symbol at the i the position in S1 and S2, respectively.
Chef would like to know the minimal and the maximal difference between the two strings, if he changes all unreadable symbols to lowercase Latin letters. 
Now that you're fully aware of Chef's programming expertise, you might have guessed that he needs you help solving this problem as well. Go on, help him!
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of a test case contains a string S1.
The second line of a test case contains a string S2.
Both strings consist of lowercase Latin letters and question marks in places where the symbols are unreadable.
Output

For each test case, output the minimal and the maximal difference between two given strings separated with a single space.
Constraints

1 = T = 100
1 = |S1|, |S2| = 100
*/
