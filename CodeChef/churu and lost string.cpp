#include<stdio.h>
char str[20001];
int main(){
	int i,index,t,n,k,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		index=0;
		for(i=0;i<n;i++) {
            if(index==0) {
                str[i]='(';
                index=1;
            }
            else if (index==1) {
                str[i]=')';
                index=0;
            }
        }
		while(k--){
			scanf("%d %d",&x,&y);
			index=0;
			while(x<=y){
				if(index==0){
					str[x]='(';
					index=1;
					x++;
				}
				else if(index==1){
					str[x]=')';
					index=0;
					x++;
				}
			}
		}
		str[n]='\0';
		printf("%s\n",str);
	}
	return 0;
}
