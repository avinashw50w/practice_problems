#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
	int t;
	scanf("%d",&t);
	ll l,r,t1,t2,count;
	while(t--){
		scanf("%lld %lld",&l,&r);
		count=0;
		if(l==1)
		count++;
		for(int i=1;(1<<i)<=r;i++){
			t1=(ll)(1<<i);
			t2=t1;
			for(int j=0;t2<=r;j++){
				t2=(ll)t1*pow(3,j);
				if(t2<=r && t2>=l)
				count++;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
