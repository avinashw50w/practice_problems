#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int powof2(int n)
{
	if (n == 0)
    	return 0;
  	while (n != 1)
  	{
    	if (n%2 != 0)
      	return 0;
    	n = n/2;
  	}
  	return 1;
}
		
int main()
{
	long long int t,a,b,r=0,q,save=0;
	scanf("%lld",&t);
	while(t--)
	{	
		int f=0;
		int s=0;
		int count=0;
		scanf("%lld%lld",&a,&b);
		save=a;
		 r=powof2(a);//Checking if a is power of 2
		if(r==1)
		printf("%d\n",abs(log2 (b)-log2 (a)));//if it is power of 2
		else
		{	
			
			while(!powof2(save))/*if not power of 2 then I am finding the no which is power of 2 by doing the operation save/=2*/
			{
			save/=2;
			count++
			}	//checking if no is power of 2	
			
				printf("%d\n",abs((log2 (b)-log2 (save)))+count);
		
		
		}
	}
	return 0;	
}		
		
			
