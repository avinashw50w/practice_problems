/* You are given a string. Your task is to determine whether number of occurrences of some character in the string is equal to the sum of the numbers of occurrences 
of other characters in the string. 
Input

The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contains one string S consisting of lowercase latin letters.
Output

For each test case, output a single line containing "YES" if the string satisfies the condition given above or "NO" otherwise.
Constraints

1 = T = 1000
1 = length of S = 50*/

#include<iostream>
using namespace std;
#define ll long long
int main(){
	int t;cin>>t;
	while(t--){
		string s; cin>>s;
		int freq[26]={};
		for(int i=0;s[i];i++) freq[s[i]-'a']++;
		int sum = 0 , ans = 0, f=0;
		for(int i=0;i<26;i++){
			sum += freq[i];   //  or simply the sum will be equal to the size of the string
		}
		for(int i=0;i<26;i++){
			if(freq[i] == sum-freq[i]){
				f=1;
				break;
			}
		}
		if(f==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
