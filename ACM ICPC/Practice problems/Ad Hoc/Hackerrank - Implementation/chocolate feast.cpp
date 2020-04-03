#include<stdio.h>
#include<stdlib.h>
int main(){

int t;
long long int n,c,m;
scanf("%d",&t);
while(t--){
	long long int t,t1,r,e;
	scanf("%lld %lld %lld",&n,&c,&m);
	t=n/c;
	t1=t;
	while(t1>=m){
		r=t1/m;
		t+=r;
		e=t1%m;
		t1=r+e;
	}
	printf("%lld\n",t);
}
return 0;
}
