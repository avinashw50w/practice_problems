#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	long long int i,j,h,k,n,m,c,max;
	int f=0;
	scanf("%lld %lld",&n,&m);
	 char ch1[m],ch2[m],str[m];
	long long int arr[n],count[n],num;
	for(i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		count[i]=0;
	}
	
	for(h=1;h<=n;h++){
		for(i=0;i<=(n-h);i++){
			max=0;k=0;
			{
				for(j=i;j<(i+h);j++){
					if(arr[j]>max){
						k++;
						max=arr[j];
					}
				}
				count[k+i-1]++;
			}
		}
	}
	for(i=0;i<m;i++){
		scanf("%s %lld %s",ch1,&num,ch2);
	c=0;
		if(ch1[0]=='>'){
			for(j=0;j<n;j++){
				if(arr[j]>num){
					c+=count[j];
				}
				else continue;	
				}
			}
			 else if(ch1[0]=='<'){
				for(j=0;j<n;j++){
				if(arr[j]<num){
					c+=count[j];
				}
				else continue;		
			}	
			}
			 else{
				for(j=0;j<n;j++){
				if(arr[j]==num){
					c+=count[j];
				}
				else continue;	
			}
			}
				if(c==0){
					if(ch2[0]=='D')
					str[i]='C';
					else str[i]='D';
				}
				else{
					if(c%2==1)
				str[i]=ch2[0];
			//	printf("%c\n",str[a]);
				if(c%2==0){
					if(ch2[0]=='D')
					str[i]='C';
					else str[i]='D';
				}
				}
			
		
		
			}str[i]='\0';
				/*if(str[i]=='C')
				printf("D");
				else printf("C");*/
				printf("%s",str);
		
		
	
	return 0;
	
}
