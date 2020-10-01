/*
	               _            .                                 .x+=:.
	              u            @88>                              z`    ^%    .uef^"
	             88Nu.   u.    %8P      u.    u.                    .   <k :d88E
	      u     '88888.o888c    .     x@88k u@88c.       u        .@8Ned8" `888E
	   us888u.   ^8888  8888  .@88u  ^"8888""8888"    us888u.   .@^%8888"   888E .z8k
	.@88 "8888"   8888  8888 ''888E`   8888  888R  .@88 "8888" x88:  `)8b.  888E~?888L
	9888  9888    8888  8888   888E    8888  888R  9888  9888  8888N=*8888  888E  888E
	9888  9888    8888  8888   888E    8888  888R  9888  9888   %8"    R88  888E  888E
	9888  9888   .8888b.888P   888E    8888  888R  9888  9888    @8Wou 9%   888E  888E
	9888  9888    ^Y8888*""    888&   "*88*" 8888" 9888  9888  .888888P`    888E  888E
	"888*""888"     `Y"        R888"    ""   'Y"   "888*""888" `   ^"F     m888N= 888>
	 ^Y"   ^Y'                  ""                  ^Y"   ^Y'               `Y"   888
	                                                                             J88"
	                                                                             @%
	                                                                           :"
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define all(o) (o).begin(),(o).end()
#define mset(a,o) memset((a),(o),sizeof(a))
#define BOOST ios_base::sync_with_stdio(0)

int main() {

	//BOOST;

	int t; cin>>t;

	string s;

	while(t--) {
		cin>>s;
	
		int n = s.size();

		if( s[0]!='?' && s[n-1]!='?' && (s[0] == s[n-1]) ) { cout << "Not found\n"; continue; }

		if(s[0] == '?'){
			if(s[n-1] == '?') {
				if(s[1] == 'a') s[0] = 'b';
				else s[0] = 'a';
			}

			else if(s[n-1] == 'a') {
				if(s[1] == 'b') s[0] = 'c';
				else s[0] = 'b';
			}

			else if(s[n-1] == 'b') {
				if(s[1] == 'a') s[0] = 'c';
				else s[0] = 'a';
			}

			else if(s[n-1] == 'c') {
				if(s[1] == 'a') s[0] = 'b';
				else s[0] = 'a';
			}
			
		}

		int flag = 0;

		for(int i=1;i<n-1;++i) {

			if(s[i] == s[i-1]) { flag = 1; break; }

			if(s[i] == '?') {
				if(s[i-1] == 'a') {
					if(s[i+1]!='b') s[i] = 'b';
					else s[i] = 'c';
				}

				else if(s[i-1] == 'b') {
					if(s[i+1]!='a') s[i] = 'a';
					else s[i] = 'c';
				}

				else if(s[i-1] == 'c') {
					if(s[i+1]!='a') s[i] ='a';
					else s[i] = 'b';
				}
			}
		}

		if(s[n-1] == '?') {

			if(s[0] == 'a') {
				if(s[n-2] == 'b') s[n-1] = 'c';
				else s[n-1] = 'b';
			}

			else if(s[0] == 'b') {
				if(s[n-2] == 'a') s[n-1] = 'c';
				else s[n-1] = 'a';
			}

			else if(s[0] == 'c') {
				if(s[n-2] == 'a') s[n-1] = 'b';
				else s[n-1] = 'a'; 
			}
			
		}

		for(int i=1; i<n; ++i) {
			if(s[i] == s[i-1]) {
				flag = 1;
				break;
			}
		}

		(flag)? cout<<"Not found" : cout<<s;
		cout<<endl;
	}
}