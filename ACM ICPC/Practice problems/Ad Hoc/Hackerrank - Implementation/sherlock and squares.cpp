#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    long long int a,b,x,y,c,i;
    scanf("%d",&t);
    while(t--)
        {
        scanf("%lld %lld",&a,&b);
        x=sqrt(a);
        y=sqrt(b);
        c=0;
        for(i=x;i<=y;i++){
            if(a<=i*i && i*i<=b)
                c++;
        }
        printf("%lld\n",c);
    }
    return 0;
}

