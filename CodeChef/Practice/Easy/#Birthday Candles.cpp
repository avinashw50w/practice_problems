/* The chef is preparing a birthday cake for one of his guests, and his decided to write the age of the guest in candles on the cake. There are 10 types 
of candles, one for each of the digits '0' through '9'. The chef has forgotten the age of the guest, however, so doesn't know whether he has enough 
candles of the right types. For example, if the guest were 101 years old, the chef would need two '1' candles and one '0' candle. Given the candles 
the chef has, your task is to determine the smallest positive integer that cannot be represented with those candles.
Input:

Input will begin with an integer T=100, the number of test cases. Each test case consists of a single line with exactly 10 integers, each between 0 and 8, 
inclusive. The first integer of each test case represents the number of '0' candles the chef has, the second integer represents the number of '1' candles 
the chef has, and so on.
Output:

For each test case, output on a single line the smallest positive integer that cannot be expressed with the given candles.
Sample input:

3
2 1 1 4 0 6 3 2 2 2
0 1 1 1 1 1 1 1 1 1
2 2 1 2 1 1 3 1 1 1
 
Sample output:

4
10
22  */

#include <iostream>
#include <algorithm>
#define oo 0x3f3f3f3f
using namespace std;
#define ll long long int
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#if defined(WIN64)
#define gc getchar()
#else
#define gc getchar_unlocked()
#endif
inline ll inp(){
	ll n = 0;
	register int c = gc;
	while(c==' ' or c=='\n') c=gc;
	while(c>='0' and c<='9'){
		n = (n<<3) + (n<<1) + c-48;
		c=gc;
	}
	return n;
} 
 
int main(){
	int t=inp();
	while(t--){
		int a[10];
		rep(i,0,10) a[i] = inp();
		int mini = a[1], idx = 1;
		rep(i,2,10){
			if(a[i]<mini){
				mini = a[i];
				idx = i;
			}
		}
		if(a[0]<mini){
			mini = a[0];
			idx = 0;
		}
		if(idx == 0) {
			printf("1");
			rep(i,0,mini+1) printf("0");
		}
		else{
			rep(i,0,mini+1) printf("%d",idx);
		}
		printf("\n");
	}
} 
