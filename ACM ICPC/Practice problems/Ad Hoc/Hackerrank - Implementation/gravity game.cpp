#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
long int t;
scanf("%ld",&t);
while(t--){
	char str1[200001],str2[200001];
	scanf("%s",str1);
	scanf("%s",str2);
	int l=strlen(str1);
	int f=0;
	//long int l2=strlen(str2);
	int i=0,count=0;
	while(i<l){
		if((str1[i]=='#' && str2[i]=='#')||(str1[l-1]=='#' && str2[l-1]=='#')||(str1[i]=='.' && str1[i+1]=='#' && str2[i+1]=='#')||(str2[i]=='.' && str2[i+1]=='#' && str1[i+1]=='#')){
		printf("No");
		f=1;
		break;
		}
		else if((str1[i]=='.' && str1[i+1]=='#' && str2[i+1]=='.')||(str2[i]=='.' && str2[i+1]=='#' && str1[i+1]=='.')){
			count++;
		}
		i++;
		
	}
	if(f==0)
	printf("Yes\n%d\n",count);
}
	return 0;
}
