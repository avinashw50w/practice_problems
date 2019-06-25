#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t,l,b,i,j,q,r,m,arr[10000],min;
    scanf("%d",&t);
    while(t--)
        {
        scanf("%d %d",&l,&b);
        if(l>b)
            m=b;
        else
            m=l;
        int k=0;
        q=(l*b);
        for(i=m;i>=1;i--)
            {
           if(q%(i*i)==0){
               if(l%i==0&&b%i==0)
               arr[k++]=q/(i*i);
               
                  }
               
    }
        min=arr[0];
        for(j=0;j<=k;j++)
            {
           if(arr[j]<min)
               min=arr[i];
        }
        printf("%d\n",min);
        
    }
    return 0;
}
