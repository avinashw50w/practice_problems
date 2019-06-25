#include<bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<(int)n;i++)
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		float A;
		int hr,j,B,x,min;
		scanf("%f",&A);
		for(int h=0;h<12;h++){
			for(int m=0;m<60;m++){
				float r = (float)(abs(60*h-11*m))/2.0;
				if(abs(A-r)<0.008333  || abs(360-A-r)<0.008333){
					hr=h;
					min=m;
			if(hr<10 && min<10)
			printf("0%d:0%d\n",hr,min);	
			else if(hr<10 && min>9)
			printf("0%d:%d\n",hr,min);
			else if(hr>9 && min<10)
			printf("%d:0%d\n",hr,min);
			else if(hr>9 && min>9)
			printf("%d:%d\n",hr,min);
		//	int b=360-A;
				}
			}
		}
	}
	return 0;
}

