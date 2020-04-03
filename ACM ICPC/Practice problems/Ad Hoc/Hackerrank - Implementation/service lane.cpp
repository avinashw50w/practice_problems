#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    long long int n;
    scanf("%lld %d",&n,&t);
     int arr[n];
        long long int s,e,i,j=0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
    while(t--){
         int max;
       scanf("%lld %lld",&s,&e);
     max=0;
        for(i=s;i<=e;i++){
            if(arr[i]>max)
                max=arr[i];
        }
         printf("%d\n",max);
    }
  //  for(i=0;i<t;i++)
        
    return 0;
}

