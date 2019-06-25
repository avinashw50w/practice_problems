#include<stdio.h>
#include<string.h>
 
#if defined(_WIN64)
 
#define GC getchar
#define PC putchar
 
#else
	
#define GC getchar_unlocked
#define PC putchar_unlocked
 
#endif
 
#define FRE freopen("input.txt","r",stdin);
 
#ifdef LONG
 
typedef long long int ll;
 
#else
	
typedef int ll;
 
#endif
 
inline ll read_int()
{
    ll n=0,a=1;
    char c=GC();
    
    while(c < 48 || c >57) 
	{
		if(c=='-')
		{
			a=-1;
		}
		c=GC();
	}
    while(c>47 && c<58)
    {
   		n=(n<<3)+(n<<1)+c-'0';
    	c=GC();
    }
    return a*n;
}
 
inline void fastwrite(ll a)
{
	char snum[40];
	ll i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	
	i=i-1;
	
	while(i>=0)
		PC(snum[i--]);
	PC('\n');
}
 
int main()
{
	
	
	ll t=read_int();
	
	while(t--)
	{
		ll n=read_int();
		
		if(n==1)
			PC('1');
		else
			PC('0');
		
		PC('\n');
	}
	
	return 0;
}
