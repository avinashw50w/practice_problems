#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,k,c=0;
        scanf("%d%d",&n,&k);
        int arr[n];
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
                if(arr[i]<=0)
                c++;
        }
        if(c<k)
            printf("YES\n");
        else
            printf("NO\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

