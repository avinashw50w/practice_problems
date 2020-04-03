#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n,m,l,r,max,i,count;
    scanf("%lld %lld",&n,&m);
    long long int arr[n];
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    while(m--){
        scanf("%lld %lld",&l,&r);
        max=0;count=0;
        for(i=(l-1);i<=(r-1);i++){
            if(arr[i]>=max)
                max=arr[i];
        }
        for(i=(l-1);i<(r-1);i++){
            if(arr[i]==max)
                count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}

