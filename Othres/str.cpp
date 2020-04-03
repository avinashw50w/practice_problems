#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char str[1000];
		scanf("%s",str);
		int i=0,maxcount=0,count=0,s,e;
		while(str[i]!='\0'){
			if(str[i]=='b'){
				s=i;
				break;
			}
			i++;
		}
	//	printf("ok");
		while(str[i]!='\0'){
			if(str[i]=='b'){
			count=0;
			continue;
		}
			else{
				count++;
				if(count>maxcount){
				maxcount=count;
				e=i;
			}
		}
		i++;
	}
	printf("\n%d,%d",s,e);
}
return 0;
}
