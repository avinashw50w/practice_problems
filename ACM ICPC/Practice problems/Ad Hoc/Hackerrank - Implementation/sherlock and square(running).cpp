#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int ModExp(int a,int b,int c);
int main() {
    long long unsigned int t,n,c;
    const int MOD=1000000007;
    scanf("%llu",&t);
    while(t--)
        {
        scanf("%llu",&n);
       // if(n==0)
           // printf("4\n");
       // else
        c=(ModExp(2, n + 1, MOD) + 2) % MOD;
        printf("%llu\n",c);
    }

       
    return 0;
}
int ModExp(int a, int b, int n)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % n;
		d = (d*d) % n;
		b >>= 1;
	}
	return (int)c;
}
