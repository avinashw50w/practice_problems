/*Given a string S consisting of only 1s and 0s, find the number of substrings which start and end both in 1.

In this problem, a substring is defined as a sequence of continuous characters Si, Si+1, ..., Sj where 1 ≤ i ≤ j ≤ N. 

Input

First line contains T, the number of testcases. Each testcase consists of N(the length of string) in one line and string in second line.

Output

For each testcase, print the required answer in one line.

Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 105
Sum of N over all testcases ≤ 105
Example

Input:
2
4
1111
5
10001

Output:
10
3*/
#include <stdio.h>

#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline int inp(){register int n=0 ,c=getchar_unlocked(); while(c<'0' || c>'9') c=getchar_unlocked();
while(c>='0' && c<='9'){n = (n<<3) + (n<<1) + c-48; c=getchar_unlocked();} return n;}

char _str[10];
#define pout(_x){	\
register int _i=0;long long int _tmp=(_x); do{*(_str + _i++)=_tmp % 10 + 48;_tmp /= 10;}     \
while (_tmp != 0);for (_i--; _i >= 0; _i--) putchar_unlocked(*(_str + _i));}	     \

typedef long long int ll;

int main() {
	char s[100000+2];
	int n, i, t=inp();
	while(t--){
		n=inp();
		scanf("%s",s);
		ll cnt = 0;
		for(i=0;i<n;++i) if(s[i]=='1') cnt++;
		pout((cnt*(cnt+1))>>1);
		putchar_unlocked('\n');
	}
	return 0;
}
