#include<stdio.h>
int main(){
	long int n,k,i,j,h;
	scanf("%ld %ld",&n,&k);
	long int arr[n],itwas_x[n];
	long int count1=0;
	int f=0;
	for(i=0;i<n;i++){
		scanf("%ld",&arr[i]);
		itwas_x[i]=0;
	//	itwas_y[i]=0;
	}
	for(h=1;h<=n;h++){
		for(i=0;i<=(n-h);i++)
		{
			for(j=i;j<(i+h);j++)
			{
				f=0;
				if(itwas_x[j]==1 && itwas_x[j+1]==1){
				f=1;
				break;
				}
				if(arr[j]%arr[j+1]==k)
				{
					itwas_x[j]=itwas_x[j+1]=1;
				//	itwas_y[j]=itwas_y[j+1]=1;
					f=1;
					break;
				}
			}if(f==0)
			count1++;
		}
	}
	printf("%ld",count1);
return 0;
	
}
