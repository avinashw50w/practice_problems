/*Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match. 
Your task is simple. Given a string, you need to tell if it is a lapindrome.
Input:

First line of input contains a single integer T, the number of test cases.

Each test is a single line containing a string S composed of only lowercase English alphabet.


Output:

For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.

Constraints:

1 = T = 100
2 = |S| = 1000, where |S| denotes the length of S*/

int main(){
	int t=inp();
	while(t--){
		string s; cin>>s;
		int l=s.size() , i;
		int f1[26]={}, f2[26]={} , flag=0;
		for(i=0;i<l/2;i++) f1[s[i]-'a']++;
		if(l&1) i++;
		for(;i<l;i++) f2[s[i]-'a']++;
		rep(i,0,26){
			if(f1[i]!=f2[i]){
				flag=1;
				break;
			}
		}
		if(flag==0) puts("YES");
		else puts("NO");
		
	}
} 
