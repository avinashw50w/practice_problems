#include <stdio.h>
#include <stdlib.h>
#define max 10000000
long long int fib(long long int);
long long int fib(long long int n){
	long long int k=0,a,b,c;
	a=0;
	b=1;
	while(k<max){
		c=a+b;
		a=b;
		b=c;
		if(n>=a && n<(a+b))
		return k+1;
		else k++;
	} 
}
int main(){
	long long int t;
	scanf("%lld",&t);
	while(t--){
		long long int n;
		scanf("%lld",&n);
		printf("%lld\n",fib(n));
		
	}
	return 0;
} 
