/* Farzi Coder wants to give a nice Christmas present to his brother. For that he has brought N pairs of letters where each letter is either 'a' or 'b'. So, the possible pairs are "aa", "ab", "ba" or "bb". Now, Farzi Coder's brother loves palindromes. So, he decided to concatenate some of the pairs (possibly all or none) and form a palindrome. He wants the longest such palindrome possible. If there are multiple such longest palindromes possible, he wants to give his brother the lexicographically smallest palindrome among them as the gift. Since he is, well, Farzi Coder, you have to help him build the gift.
Input
The first line of the input has the number T denoting the number of test cases.
The first line of each test case has the number N denoting the number of pairs in this case.
Each of the next N lines contain a pair of characters which are either aa, ab, ba or bb.
Output
For each test case, output on a seperate line the gift that Farzi Coder has to build. Note that the empty string is a palindrome.
Constraints
1 = T = 500
1 = N = 2000
Each pair can be either aa, ab, ba or bb
Sample
Input

2
4
aa
aa
bb
bb
3
ab
ba
ab
    
Output

aabbbbaa
abba

    
Explanation

Case 1: The following palindromes are possible: "aa", "aaaa", "bb", "bbbb", "aabbaa", "bbaabb", "aabbbbaa", "bbaaaabb". 
Of these, "aabbbbaa" and "bbaaaabb" are of the maximum length. Among these two, "aabbbbaa" is the lexicographically smallest.


Case 2: The palindromes possible here are: "baab" and "abba".  */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
int pair[4];
void Comp(string s){
	if(s.compare("aa")==0) pair[0]++;
	if(s.compare("ab")==0) pair[1]++;
	if(s.compare("ba")==0) pair[2]++;
	if(s.compare("bb")==0) pair[3]++;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		memset(pair,0,4);
		for(int i=0;<n;i++){
			string s;
			cin>>s;
			Comp(s);
		}
		string ans="",ans1="",ans2="";
			if(pair[0]){
				for(int i=0;i<pair[0]/2;i++) ans1+="aa", ans2+="aa";
				pair[0]-=pair[0]/2;
			}
			if(pair[1]&& pair[2]){
				if(pair[1]<=pair[2]) {
					for(int i=0;i<pair[1];i++)
					ans1+="ab",ans2+="ab";
				}
				else { 
				for(int i=0;i<pair[2];i++)
					ans1+="ba", ans2+="ba";
					}
			}
			if(pair[3]){
				for(int i=0;i<pair[3]/2;i++)
				ans1+="bb",ans2+="bb";
				pair[3]-=pair[3]/2;
			}
			ans2.reverse();
			ans+=ans1+ans2;
	}
}
