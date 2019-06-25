#include<bits/stdc++.h>
using namespace std;
#define ld long double
int main(){
	ld ai,bi,ak,bk,a_plus,b_plus,Q;
	long long int i,k,s,t;
	scanf("%lld %lld %lld",&i,&k,&s);
	scanf("%LF %LF",&ai,&bi);
	if(k>=i){
		if((k-i)%2==0){
			t=(k-i)/2;
		//	ak=pow(16,t)*ai;
		//	bk=pow(16,t)*bi;
		if((4*t-s)>=0)
		Q=pow(2,4*t-s)*ai + pow(2,4*t-s)*bi;
		else
		Q=ai/pow(2,s-4*t) + bi/pow(2,s-4*t);
		}
		else{
			a_plus=sqrt(2)*(ai+bi) - sqrt(6)*(ai-bi);
			b_plus=sqrt(2)*(ai-bi) + sqrt(6)*(ai+bi);
			t=(k-i-1)/2;
		//	ak=pow(16,t)*ai;
		//	bk=pow(16,t)*bi;
		if((4*t-s)>=0)
			Q=pow(2,4*t-s)*a_plus + pow(2,4*t-s)*b_plus;
			else
			Q=a_plus/pow(2,s-4*t) + b_plus/pow(2,s-4*t);
		}
	}
	else{
		if((i-k)%2==0){
			t=(i-k)/2;
		//	ak=ai/pow(16,t);
		//	bk=bi/pow(16,t);
		Q=ai/pow(2,4*t+s) + bi/pow(2,4*t+s);
		}
		else{
			a_plus=sqrt(2)*(ai+bi) - sqrt(6)*(ai-bi);
			b_plus=sqrt(2)*(ai-bi) + sqrt(6)*(ai+bi);
			t=(i-k+1)/2;
		//	ak=ai/pow(16,t);
		//	bk=bi/pow(16,t);
			Q=a_plus/pow(2,4*t+s) + b_plus/pow(2,4*t+s);
		}
	}
//	ld Q=(ak+bk)/pow(2,s);
	printf("%LF",Q);
	return 0;
}
