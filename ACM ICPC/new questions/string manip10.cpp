/*When he reached Dandi, he decided to play a game with the tired people to give them some strength. 
At each turn of the game he pointed out a person and told him to say a number N(possibly huge) of his choice. 
The number was called lucky if that equals it's mirror image.

Input: 
First line contains number of test cases T. Each test case contains a single integer N.
Output: 
For each test case print "YES" if the number was lucky else print "NO" (quotes for clarity) in one line.

Constraints:
1 ≤ T ≤ 100
0 ≤ N ≤ 10100

Image for Sample Test Cases :

enter image description here

SAMPLE INPUT 
2
101
020
SAMPLE OUTPUT 
YES
NO  */

int pal(string s) {
	int n = s.size();
	for(int i = 0; i < n/2; ++i) {
		if(s[i] != s[n-i-1]) return 0;
	}
	return 1;
}

int main()
{
    int t; cin>>t;
    string s;
    
    while(t--) {
    	cin>>s;
    	int n = s.size(), flag = 0;
    	for(int i=0; i < n; ++i) 
    		if(s[i]!='1' and s[i]!='0' and s[i]!='8') {
    			flag = 1;
    			break;
    		}
    	if(flag) cout << "NO\n";
    	else {
    		if(pal(s)) cout << "YES\n";
    		else cout << "NO\n";
    	}
    	
    }
    return 0;
}
