#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,arr[12];
   long long int n,k,c,i,count,temp;
    scanf("%d",&t);
    while(t!=0){
        t--;
        scanf("%llu",&n);
       k=n;
        c=0;i=0;
        while(k!=0){
           temp=k%10;
            k=k/10;
            arr[i]=temp;
            if(arr[i]!=0){
                if(n%arr[i]==0)
                    c++;
            }
              i++;
        }
        printf("%llu\n",c);
    }
    return 0;
}

