#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int i,t,a;
    long int n,sum;
    scanf("%d\n",&t);
    while(t!=0){
        t--;
        scanf("%ld\n",&n);
        sum=0;
        for(i=1;i<=n;i++){
            a=(i*i)-((i-1)*(i-1));
            sum+=a;
        }
        printf("%ld\n",sum);
    }
    return 0;
}

