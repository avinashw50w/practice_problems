#include<stdio.h>
int main(){
	long long int n,m,i,sum=0,c=0;
	scanf("%lld %lld",&n,&m);
	if(m<=n){
		printf("1");
		return 0;
	}
	else if(m>(n*(n+1)/2)){
		printf("-1");
		return 0;
	}
	else{
		for(i=n;i>=1;i--){
			sum+=i;
			c++;
			if(sum<m)
			continue;
			else {
			printf("%lld",c);
			break;
			}
		}
	}
	return 0;
}
