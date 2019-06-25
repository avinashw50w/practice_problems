#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,k,i=0;
    scanf("%d",&n);
    char str[n];
    scanf("%s",str);
    scanf("%d",&k);
    while(str[i]!='\0'){
        if(str[i]>=97 && str[i]<=122)
            str[i] = ((str[i]+k-97)%26) + 97;
        else{
            if(str[i]>=65 && str[i]<=90)
                str[i] = ((str[i]+k-65)%26) + 65;
        }i++;
    }
    printf("%s",str);

    return 0;
}

