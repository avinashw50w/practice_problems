#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    long long int n,m,s,q,r;
    scanf("%d",&t);
        while(t!=0){
            t--;
            scanf("%lld  %lld\n",&n,&m);
            q=n/m;
            r=n%m;
            s=(q*((m*(m-1))/2))+((r*(r+1))/2);
            printf("%lld\n",s);
        }
    return 0;
}

