#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long unsigned int t,s,sum;
    long long unsigned int n,i;
    
    scanf("%llu",&t);
    while(t!=0){
        t--;
        scanf("%llu",&n);
       
       // sum=4;
        
            sum=2+ pow(2,n+1);
        
        s=sum%1000000007;
            printf("%lld\n",s%1000000007);
    }
    return 0;
}

