#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char str1[15],str2[15];
		scanf("%s",str1);
		scanf("%s",str2);
		int i,j,f=0;
		int l1=strlen(str1);
		int l2=strlen(str2);
		if(l1!=l2){
			printf("No\n");
			break;
		}
		for(i=0;i<l1;i++){
			if(str1[i]!=str2[i]){
				if(str1[i]=='?' || str2[i]=='?')
				continue;
				else{
					printf("No\n");
					f=1;
					break;
				}
			}
		}if(f==0)
		printf("Yes\n");
	}
	return 0;
}
