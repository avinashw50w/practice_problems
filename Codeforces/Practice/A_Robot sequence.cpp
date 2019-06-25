/* Calvin the robot lies in an infinite rectangular grid. Calvin's source code contains a list of n commands, each either 'U', 'R', 'D', or 'L' — instructions to move a single square up, right, down, or left, respectively. How many ways can Calvin execute a non-empty contiguous substrings of commands and return to the same square he starts in? Two substrings are considered different if they have different starting or ending indices.

Input
The first line of the input contains a single positive integer, n (1?=?n?=?200) — the number of commands.

The next line contains n characters, each either 'U', 'R', 'D', or 'L' — Calvin's source code.

Output
Print a single integer — the number of contiguous substrings that Calvin can execute and return to his starting square.

Examples
input
6
URLLDR
output
2 

*/
#include <iostream>
#define ll long long int
#define gc getchar()
using namespace std;
inline ll inp(){
	int n=0; register int c=gc;
	while(c==' '||c=='\n') c=gc;
	while(c>='0'&&c<='9'){
		n=(n<<3)+(n<<1)+c-48;
		c=gc;
	}
	return n;
}
int main(){
	int n; cin>>n;
	string s;
	cin>>s;
	int x = 0, y = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='U') y++;
		else if(s[i]=='D') y--;
		else if(s[i]=='R') x++;
		else if(s[i]=='L') x--;
	}
	int cnt = 0, xf,yf;
	for(int i=0;i<n;i++){
		xf=x,yf=y;
		for(int j=i;j<n;j++){
			if(s[j]=='U') yf++;
			else if(s[j]=='D') yf--;
			else if(s[j]=='R') xf++;
			else if(s[j]=='L') xf--;
			if(xf==x && yf==y)  cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
