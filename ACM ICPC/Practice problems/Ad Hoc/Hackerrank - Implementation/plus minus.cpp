#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,pos=0,neg=0,zero=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>0)
            pos++;
        else if(a[i]<0)
            neg++;
            else zero++;
    }
    printf("%f\n%f\n%f",pos/(float)n,neg/(float)n,zero/(float)n);
    return 0;
}
