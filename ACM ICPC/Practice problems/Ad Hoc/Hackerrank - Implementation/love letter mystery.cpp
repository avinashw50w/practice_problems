#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     char a[100000];
    int i,n,t,l;
     scanf("%d\n",&t);
    while(t!=0)
        {
        t--;
        scanf("%s\n",a);
        int c=0;
        n=strlen(a);
        l=n/2;
        for(i=0;i<l;i++)
            {
            if(a[i]>=a[n-1-i])
                c=(a[i]-a[n-1-i])+c;
     
            else
                c=c+(a[n-1-i]-a[i]);
            
            }
        printf("%d\n",c);
        
}
    return 0;
}

