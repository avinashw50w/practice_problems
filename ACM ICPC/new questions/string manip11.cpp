/*He likes his strings sorted, in a different kind of a way. He wants his strings to be sorted based on the count of characters present in the string. For instance, if the string is: "aaabbc", then the desired string would be: cbbaaa. In case where the count of two characters is same, then the lexicographically smaller one will be printed first. For instance: "aabbcc" then, the output will be: "aabbcc".

Input:
First line of input contains number of test cases T. Each test case contains a single string S.

Output:
For each test cases print the sorted string.

Constraints:
1<=T<=100
1<=|S|<=100

Note:
String contains only lowercase characters ['a' to 'z'].

SAMPLE INPUT 
3
aabbccdd
aabcc
hackerearth

SAMPLE OUTPUT 
aabbccdd
baacc
cktaaeehhrr */

int main()
{
    int t; cin>>t;
    string s;
    while(t--) {
    	cin>>s;
    	
    	vector<pair<int, char>> v(26);
    	
    	for(int i = 0; i < 26; ++i) {
    		v[i].first = 0;
    		v[i].second = i+'a';
    	}
    	
    	for(int i = 0; i < s.size(); ++i) v[s[i]-'a'].first++;
    	
    	sort(v.begin(), v.end());
    	
    	string ans = "";
    	for(int i = 0; i < 26; ++i) {
    		int k = v[i].first;
    		char c = v[i].second;
    		for(int j = 0; j < k; ++j) ans += c;
    	}
    	
    	cout << ans << endl;
    }
    return 0;
}
