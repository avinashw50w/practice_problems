#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char check_w(char ch1[],char ch2[],long int num,long int arr[],long int n,long int count[] );
int main(){
	long int i,j,h,k,n,m,max;
	int f=0;
	scanf("%lld %lld",&n,&m);
	 char ch1[m],ch2[m],str[m+1];
	long int arr[n],count[n],num;
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
	//	 printf("%d\n",i);
		scanf("%s %lld %s",ch1,&num,ch2);
	 str[i]=check_w(ch1,ch2,num,arr,n,count);
	  
}
				str[i]='\0';
			printf("%s",str);	
	
	return 0;
	
}

char check_w(char ch1[],char ch2[],long int num,long int arr[],long int n,long int count[] ){
	long int c=0,j;
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
			
		//	long long int t=c;
			if(c==0){
					if(ch2[0]=='D')
					return 'C';
					else return 'D';
				}
				else{
			if(c%2==1)
				return ch2[0];
				else if(c%2==0){
					if(ch2[0]=='D')
					return 'C';
					else return 'D';
				}
			}
		
			}
		
