/*N Soldiers are lined up for a memory test. They are numbered from 0 to N-1 from left to right.

In the test, there are M rounds. In each round, Captain selects one position. Soldier at that position will be numbered 0. All the soldiers to the right of selected 
position will be numbered one greater than the soldier to his left. All the soldiers to the left of selected position will be numbered one greater than the soldier to his right. 
eg. if N = 6 and selected position is 3, then the numbering will be [3, 2, 1, 0, 1, 2].

After M rounds, Captain asked each soldier to shout out the greatest number he was assigned during the M rounds. In order to check the correctness, Captain asked you to 
produce the correct values for each soldier (That is the correct value each soldier should shout out).

Input

The first line of the input contains an integer T denoting the number of test cases.
First line of each test case contains two integers, N and M.
Second line of each test case contains M integers, the positions selected by Captain, in that order.

Output

For each test case, output one line with N space separated integers.*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)

typedef long long int ll;

#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline ll inp(){ ll n=0, sg=1; register int c=getchar_unlocked(); if(c=='-') sg=-1; while(c<'0' || c>'9')
c=getchar_unlocked(); while(c>='0' && c<='9'){n = (n<<3) + (n<<1) + c-48; c=getchar_unlocked();} return n*sg;}

char _str[19];
inline void pout(ll _x){ register int _i=0;ll _tmp=(_x); do{*(_str + _i++)=_tmp % 10 + 48;_tmp /= 10;}
while (_tmp != 0);for (_i--; _i >= 0; _i--) putchar_unlocked(*(_str + _i)); }


int main() {
	int i,m,n,mini,maxx;
	int t=inp();
	while(t--){
		n=inp(); m=inp();
		mini=inp();
		maxx=mini;
		m--;
		while(m--){
			i=inp();
			if(i<mini) mini=i;
			else if(i>maxx) maxx=i;
		}
		i=(mini+maxx)>>1;
		for(m=0;m<=i;++m) printf("%d ", maxx-m);
		for(;m<n;++m) printf("%d ", m-mini);
		printf("\n");
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int i,m,n,mini,maxx;
	int t=inp();
	while(t--){
		n=inp(); m=inp();
		mini=inp();
		maxx=mini;
		m--;
		while(m--){
			i=inp();
			if(i<mini) mini=i;
			else if(i>maxx) maxx=i;
		}
		rep(i,0,n){
			(abs(maxx-i) > abs(i-mini)) ? printf("%d ", abs(maxx-i)) : printf("%d ", abs(i-mini));
		}
		printf("\n");
	}
	return 0;
}
