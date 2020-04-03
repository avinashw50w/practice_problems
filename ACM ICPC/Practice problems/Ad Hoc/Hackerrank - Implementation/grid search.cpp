#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t,i,j,n,m,p,q,k,count,pos;
        scanf("%d",&t);
   char *ptr;
    while(t--){
        scanf("%d %d",&n,&m);
     char matrx[n+1][m+1];
        for(i=0;i<n;i++){
            scanf("%s",matrx[i]);
        }
        scanf("%d %d",&p,&q);
        char smatrx[p+1][q+1];
        for(i=0;i<p;i++){
                scanf("%s",smatrx[i]);
        }
       for(i=0;i<n;i++){
           count=1;
            ptr=strstr(matrx[i],smatrx[0]);    //strstr returns the pointer location where the first occurence of the substring occurs,
            if(ptr!=0){                        // if substring is not present then it returns 0
                pos=ptr-matrx[i];              // save the position where the first char of the substring occurs
                k=i+1;                         // increment the row of the matrix
                for(j=1;j<p && k<n;j++,k++)
            {
            ptr=strstr(matrx[k],smatrx[j]);
            if(pos==ptr-matrx[k])
            count++;
            }
        if(count==p)
        {
            printf("YES\n");
            break;
        }
    }
}
if(i==n)
printf("NO\n");
 
    }
    return 0;
}

