#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int max=0,player,s,t,k,p1=0,p2=0;
	while(n--){
		scanf("%d %d",&s,&t);
		p1+=s;
		p2+=t;
		if(p1-p2>max){
		max=p1-p2;
		player=1;
	}
	else if(p2-p1>max){
		max=p2-p1;
		player=2;
	}
	}
	printf("%d %d",player,max);
	return 0;
}
