#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    long long int k,p,q,s;
    scanf("%d",&t);
    while(t!=0){
        t--;
        scanf("%lld\n",&k);
        if(k%2==0){
            p=k/2;
            s=p*p;
        }
        else{
            p=k/2;
            q=k/2+1;
            s=p*q;
        }
        printf("%lld\n",s);
    }
    return 0;
}

