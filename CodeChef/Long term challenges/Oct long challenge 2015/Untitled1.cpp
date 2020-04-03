#include<bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<(int)n;i++)
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		float A;
		int h,j,B,x,m;
		scanf("%f",&A);
		for(int i=0;i<=360*12;i+=6){
			float p = (float)((i%360)-i/12.0);
			float a = abs(p);
			float q = 360.0-a;
			if(a==A || q==A){
			m = (i%360)/6;
			h = i/360;
			if(h>=12) continue;
			if(h<10 && m<10)
			printf("0%d:0%d\n",h,m);
			else if(h<10 && m>9)
			printf("0%d:%d\n",h,m);
			else if(h>9 && m<10)
			printf("%d:0%d\n",h,m);
			else if(h>9 && m>9)
			printf("%d:%d\n",h,m);
		}
		}
	
	}
	return 0;
}

