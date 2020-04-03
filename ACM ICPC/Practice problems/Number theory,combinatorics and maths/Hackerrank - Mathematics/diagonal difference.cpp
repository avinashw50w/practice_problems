#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i,j,diff,d1=0,d2=0;
    scanf("%d",&n);
    long int arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%ld",&arr[i][j]);
    }
    for(i=0,j=0;i<n,j<n;i++,j++){
        d1+=arr[i][j];
        d2+=arr[n-i-1][j];
    }
    diff=abs(d1-d2);
    printf("%d",diff);
    return 0;
}

