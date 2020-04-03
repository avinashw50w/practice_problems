#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int arr[1001],i,min,n,c,j,x;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    while( x!=1){
        x=n;
        min=arr[0];
    for(i=0;i<j;i++){
        if(min==0)
            min=arr[i+1];
        if(arr[i]==0)
           continue;
        else{
        if(arr[i]<min)
            min=arr[i];
        }
    }
    for(i=0;i<j;i++){
        if(arr[i]!=0){
         arr[i]-=min;
        }
        else
            x--;
    }
    printf("%d\n",x);
    }
    return 0;
}

