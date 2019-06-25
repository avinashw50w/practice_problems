   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
typedef long long int ll;
inline ll inp(){ll n = 0;register int c=getchar_unlocked();while(c==' ' or c=='\n')c=getchar_unlocked();
while(c>='0' and c<='9'){n=(n<<3)+(n<<1)+c-48;c=getchar_unlocked();}return n;}
/*========================================================================================*/

int main() {
	int t=inp();
	while(t--){
		int f=0;
		string s; cin>>s;
		for(int i=0;s[i];++i){
			if((s[i]=='0' and s[i+1]=='1' and s[i+2]=='0') or
				(s[i]=='1' and s[i+1]=='0' and s[i+2]=='1')){
				f=1; break;
			}
		}
		(f==0)?puts("Bad"):puts("Good");
	}
	return 0;
}
