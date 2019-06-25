#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int min(long long int,long long int);
long long int min(long long int a,long long int b){
    return (a<b)?a:b;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    scanf("%d",&t);
    long long int b,w,x,y,z,count;
    while(t--){
        scanf("%lld %lld",&b,&w);
        scanf("%lld %lld %lld",&x,&y,&z);
        count = min(b*x,b*(y+z)) + min(w*y,w*(x+z));
        printf("%lld\n",count);
    }
    return 0;
}

