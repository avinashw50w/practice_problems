#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,a[101][101],i,j,p,q,r,s,x;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        //for(j=0;j<n;j++)
            scanf("%d\n",&a[i]);
       // printf("\n");
    }
   /*for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
        x=a[i][j];
        p=a[i-1][j];
        q=a[i+1][j];
        r=a[i][j-1];
        s=a[i][j+1];
        if(x>p && x>q && x>r && x>s){
            a[i][j]='X';
        }
        }
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d",a[i][j]);
        
    }*/
    return 0;
}

