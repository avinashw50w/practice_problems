/*A tourist is visiting Byteland. The tourist knows English very well. The language of Byteland is rather different from English. To be exact it differs in following points:
Bytelandian alphabet has the same letters as English one, but possibly different in meaning. Like 'A' in Bytelandian may be 'M' in English. However this does not mean that 'M' in Bytelandian must be 'A' in English. More formally, Bytelindian alphabet is a permutation of English alphabet. It will be given to you and could be any possible permutation. Don't assume any other condition.
People of Byteland don't like to use invisible character for separating words. Hence instead of space (' ') they use underscore ('_'). Other punctuation symbols, like '?', '!' remain the same as in English.
The tourist is carrying "The dummies guide to Bytelandian", for translation. The book is serving his purpose nicely. But he is addicted to sharing on BaceFook, and shares his numerous conversations in Byteland on it. The conversations are rather long, and it is quite tedious to translate for his English friends, so he asks you to help him by writing a program to do the same.
Input

The first line of the input contains an integer T, denoting the length of the conversation, and the string M, denoting the English translation of Bytelandian string "abcdefghijklmnopqrstuvwxyz". T and M are separated by exactly one space. Then T lines follow, each containing a Bytelandian sentence S which you should translate into English. See constraints for details.
Output

For each of the sentence in the input, output its English translation on a separate line. Replace each underscores ('_') with a space (' ') in the output. Each punctuation symbol (see below) should remain the same. Note that the uppercase letters in Bytelandian remain uppercase in English, and lowercase letters remain lowercase. See the example and its explanation for clarity.
Constraints

1 ≤ T ≤ 100
M is a permutation of "abcdefghijklmnopqrstuvwxyz"
Each sentence is non-empty and contains at most 100 characters
Each sentence may contain only lowercase letters ('a'-'z'), uppercase letters ('A'-'Z'), underscores ('_') and punctuation symbols: dot ('.'), comma (','), exclamation ('!'), question-mark('?')
Example

Input:
5 qwertyuiopasdfghjklzxcvbnm
Ph
Pcssi
Bpke_kdc_epclc_jcijsc_mihyo?
Epcf_kdc_liswhyo_EIED_hy_Vimcvpcn_Zkdvp_siyo_viyecle.
Ipp!

Output:
Hi
Hello
What are these people doing?
They are solving T*/
int main() {
	int t=inp();
	string s; cin>>s;
	while(t--){
		string a, ans = ""; 
		cin>>a;
		for(int i=0;i<a.size();i++){
			if(a[i]=='_') ans += " ";
			else if('a'<=a[i] and a[i]<='z')ans += s[a[i]-'a']; 
			else if('A'<=a[i] and a[i]<='Z')ans += toupper(s[a[i]-'A']); 
			else ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
