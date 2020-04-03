#include<stdio.h>
#include<math.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n!=1 && (n&(n+1))==0)
            printf("%d\n",(1<<((int)log2(n+1)-1))-1);
        else if(n==1)
            printf("%d\n",2);
        else
            printf("-1\n");
    }
    return 0;
}
