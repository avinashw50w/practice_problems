#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int m,n,a,b,k,sum,avg;
    scanf("%lld %lld",&n,&m);
    sum=0;
    while(m--){
        
        scanf("%lld %lld %lld",&a,&b,&k);
        sum=sum +k*(b-a+1);
    }
    avg=sum/n;
    printf("%lld",avg);
    return 0;
}
