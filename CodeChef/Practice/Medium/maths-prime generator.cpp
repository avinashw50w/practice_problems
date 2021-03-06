/*Shridhar wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers.

Input

The first line contains t, the number of test cases (less then or equal to 10). Followed by t lines which contain two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.*/
#include <stdio.h>
#include <algorithm>
#define ll long long int
using namespace std;

void sieve(ll l,ll r){
	bool primes[r-l+1];
	for(ll i=0;i<(r-l+1);i++) primes[i]=true;
	for(ll i=2;i*i<=r;i++){
		for(ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
		primes[j-l]=false;
	}
	for(ll i=max(l,(ll)2);i<=r;i++){
		if(primes[i-l]) printf("%lld\n", i );
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		ll n,m; scanf("%lld%lld",&m,&n);
		sieve(m,n);
		printf("\n");
	}
	return 0;
}