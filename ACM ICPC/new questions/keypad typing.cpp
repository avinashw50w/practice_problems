/*You are given N strings of alphabet characters and the task is to find their matching decimal representation as on the shown keypad. 
Output the decimal representation corresponding to the string. For ex: if you are given “amazon” then its corresponding decimal 
representation will be 262966.*/


#include <iostream>
using namespace std;

int main() {
	int t, x;
	string s;
	cin>>t;
	while(t--) {
	    cin>>s;
	    string ans = "";
	    for(int i = 0; s[i]; ++i) {
	        if(s[i] == toupper(s[i])) {
	            x = (s[i] - 'A');
	            if(x < 18) x = x/3 + 2;
	            else {
	                if(x == 18) x = 7;
	                else if(x == 19 || x == 20 or x == 21) x = 8;
	                else x = 9;
	            }
	        } 
	            
	        else {
	            x = (s[i] - 'a');
	            if(x < 18) x = x/3 + 2;
	            else {
	                if(x == 18) x = 7;
	                else if(x == 19 || x == 20 or x == 21) x = 8;
	                else x = 9;
	            }
	        }
	           
	        ans += (x+'0');
	    }
	    cout << ans << endl;
	}
	return 0;
}