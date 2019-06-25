#include<stdio.h>
int main()
{
	int i,j,t,value[20];                                  //initial height is 1 metre,after first cycle  height doubles and after 2nd cycle height increases by 1m
	printf("\nEnter the no of trials:");                  //and the process continues untill n. we have to find the final height.
	scanf("%d",&t);
	printf("\nEnter the no. of cycles:");
	for(i=1;i<=t;i++)
	{
		int count=0;
	scanf("%d",&value[i]);
	
	for(j=0;j<=value[i];j++)
	{
		if(j%2==0)
		count=count+1;
		else
		count=count*2;
	}
	printf("%d\n",count);

}
return 0;
}
