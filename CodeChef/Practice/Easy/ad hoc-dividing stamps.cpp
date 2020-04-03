#include <stdio.h>
#define ll long long int
 #ifdef __WIN32__
 #define getchar_unlocked getchar
 #endif
 inline ll inp(){ll n = 0;register int c=getchar_unlocked();while(c==' ' or c=='\n')c=getchar_unlocked();
 while(c>='0' and c<='9'){n=(n<<3)+(n<<1)+c-48;c=getchar_unlocked();}return n;}
int main(){
	ll n,i,a;
	ll sum = 0;
	n=inp();
	for(i=0;i<n;++i) {
		sum = sum + inp();
	}
	(sum == (n*(n+1))/2)? puts("YES") : puts("NO");	
	return 0;
}